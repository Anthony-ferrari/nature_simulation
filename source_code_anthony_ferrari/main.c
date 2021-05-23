#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define _USE_MATH_DEFINES
#include <omp.h>

float Ranf(unsigned int*, float, float); // prototype for random function
float SQR(float); // prototype for squaring


unsigned int seed = 0;
float x = Ranf( &seed, -1.f, 1.f );

int	NowYear = 2021;		// 2021 - 2026
int	NowMonth = 0;		// 0 - 11

float	NowPrecip;		// inches of rain per month
float	NowTemp;		// temperature this month
float	NowHeight ;		// grain height in inches
int	NowNumDeer ;		// number of deer in the current population
int NowNumHunters;       // number of hunters in current population


// time step is 1 month
const float GRAIN_GROWS_PER_MONTH =		9.0;
const float ONE_DEER_EATS_PER_MONTH =		1.0;
// how much a hunter eats per month
const float HUNTER_EATS_PER_MONTH = 1.0;

const float AVG_PRECIP_PER_MONTH =		7.0;	// average
const float AMP_PRECIP_PER_MONTH =		6.0;	// plus or minus
const float RANDOM_PRECIP =			2.0;	// plus or minus noise

const float AVG_TEMP =				60.0;	// average
const float AMP_TEMP =				20.0;	// plus or minus
const float RANDOM_TEMP =			10.0;	// plus or minus noise

const float MIDTEMP =				40.0;
const float MIDPRECIP =				10.0;


void Watcher()
{
    while( NowYear < 2027 )
    {
        // compute a temporary next-value for this quantity
        // based on the current state of the simulation:
        

        // watcher does nothing in computing barrier

        // DoneComputing barrier:
        #pragma omp barrier

        // watcher does nothing in assigning barrier

        // DoneAssigning barrier:
        #pragma omp barrier


        // print out now state info 
        // fprintf(stdout, "current month: %2d, current year: %4d, grain height: %6.8lf, number of deer: %d, number of hunters: %d, precip: %6.5lf, temp: %6.8lf\n",
		// NowMonth, NowYear, NowHeight, NowNumDeer, NowNumHunters, NowPrecip, NowTemp);

        fprintf(stdout, "%2d,%4d,%6.8lf,%d,%d,%6.5lf,%6.8lf\n",
		NowMonth, NowYear, NowHeight, NowNumDeer, NowNumHunters, NowPrecip, NowTemp);
        // advance the month and possibly year
        NowMonth++;
        if(NowMonth>11){
            NowYear++;
            NowMonth = 0;
        }

        // environment variables
        // temp and precip are a function of the particular month
        float ang = (  30.*(float)NowMonth + 15.  ) * ( M_PI / 180. );

        float temp = AVG_TEMP - AMP_TEMP * cos( ang );
        NowTemp = temp + Ranf( &seed, -RANDOM_TEMP, RANDOM_TEMP );

        float precip = AVG_PRECIP_PER_MONTH + AMP_PRECIP_PER_MONTH * sin( ang );
        NowPrecip = precip + Ranf( &seed,  -RANDOM_PRECIP, RANDOM_PRECIP );
        if( NowPrecip < 0. )
            NowPrecip = 0.;

        // DonePrinting barrier:
        #pragma omp barrier
    }
}

void Deer()
{
    while( NowYear < 2027 )
    {
        // compute a temporary next-value for this quantity
        // based on the current state of the simulation:
        int next_num_deer = NowNumDeer;
        int carryingCapacity = (int)(NowHeight);
        if(NowNumDeer > carryingCapacity){
            next_num_deer--;
        }else if(NowNumDeer < carryingCapacity){
            next_num_deer++;
        }

        // hunters hunt deer every other month
        if(NowMonth%2==0){
            next_num_deer -= NowNumHunters * HUNTER_EATS_PER_MONTH;
        }
        // if deer are about to go extinct then cap at 0
        if(next_num_deer < 0){
            next_num_deer = 0;
        }

        // DoneComputing barrier:
        #pragma omp barrier
        
        NowNumDeer = next_num_deer;

        // DoneAssigning barrier:
        #pragma omp barrier
        
        //do nothing 

        // DonePrinting barrier:
        #pragma omp barrier
        
    }
}

void Grain()
{
    while( NowYear < 2027 )
    {
        // compute a temporary next-value for this quantity
        // based on the current state of the simulation:
        
        float tempFactor = exp(   -SQR(  ( NowTemp - MIDTEMP ) / 10.  )   );

        float precipFactor = exp(   -SQR(  ( NowPrecip - MIDPRECIP ) / 10.  )   );
        
        float nextHeight = NowHeight;

        // check for ideal temp and precip !!!!

        nextHeight += tempFactor * precipFactor * GRAIN_GROWS_PER_MONTH;
        nextHeight -= (float)NowNumDeer * ONE_DEER_EATS_PER_MONTH;

        if( nextHeight < 0. )
        {
            nextHeight = 0.;
        }
        // DoneComputing barrier:
        #pragma omp barrier
        
        NowHeight = nextHeight;

        // DoneAssigning barrier:
        #pragma omp barrier
        
        // do nothing in this step - letting watcher() handle environment vars

        // DonePrinting barrier:
        #pragma omp barrier
    }
}

void Hunter()
{
    while( NowYear < 2027 )
    {
        // compute a temporary next-value for this quantity
        // based on the current state of the simulation:
        int next_num_hunters = NowNumHunters;
        int deer_supply = (int)(NowNumDeer);
        // hunters die from starvation
        if(NowNumHunters > deer_supply){
            next_num_hunters--;
        // hunters increase due to abundance -- lower deer supply so it looks cyclic
        }else if(NowNumHunters < (0.5*deer_supply)){
            next_num_hunters++;
        }
        // if deer are about to go extinct then cap at 0
        if(next_num_hunters < 0){
            next_num_hunters = 0;
        }
        // DoneComputing barrier:
        #pragma omp barrier
        
        NowNumHunters = next_num_hunters;

        // DoneAssigning barrier:
        #pragma omp barrier
        
        //do nothing 

        // DonePrinting barrier:
        #pragma omp barrier
        
    }
}

int main( int argc, char *argv[ ] )
{
	#ifndef _OPENMP
	fprintf( stderr, "No OpenMP support!\n" );
	return 1;
    #endif
    // set numbers 
    // starting date and time:
    NowMonth =    0;
    NowYear  = 2021;

    // starting state (feel free to change this if you want):
    NowNumDeer = 2;
    NowHeight =  8.;
    NowNumHunters = 0;
        // temp and precip are a function of the particular month
    float ang = (  30.*(float)NowMonth + 15.  ) * ( M_PI / 180. );

    float temp = AVG_TEMP - AMP_TEMP * cos( ang );
    NowTemp = temp + Ranf( &seed, -RANDOM_TEMP, RANDOM_TEMP );

    float precip = AVG_PRECIP_PER_MONTH + AMP_PRECIP_PER_MONTH * sin( ang );
    NowPrecip = precip + Ranf( &seed,  -RANDOM_PRECIP, RANDOM_PRECIP );
    if( NowPrecip < 0. )
        NowPrecip = 0.;

    omp_set_num_threads( 4 );	// same as # of sections
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            Deer( );
        }

        #pragma omp section
        {
            Grain( );
        }

        #pragma omp section
        {
            Watcher( );
        }

        #pragma omp section
        {
            Hunter( );	// your own
        }
    }       // implied barrier -- all functions must return in order
        // to allow any of them to get past here
}

float Ranf( unsigned int *seedp,  float low, float high )
{
        float r = (float) rand_r( seedp );              // 0 - RAND_MAX

        return(   low  +  r * ( high - low ) / (float)RAND_MAX   );
}

float SQR( float x )
{
        return x*x;
}
