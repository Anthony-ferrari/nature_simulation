
# nature_simulation
This program is a nature simulator using functional decomposition design for entity interaction and state synchronization. It simulates grain growth, deer population growth, and hunter population growth by accessing environment variables like precipitation factors and temperature factors. 
#### Features 
- [x] Utilizies OpenMP's omp sections to break down the updating of current state and moving to the next state at an entity level. 
- [x] Allows synchronization to occur with a Watcher class that updates environment variables and moves the entire program forward. Makes use of implied barriers for all entities to be at the same step. 
- [x] Implemented a functional decomposition design for easier synchronization. 
- [x] Simulates grain growth, deer population growth, and hunter population growth for 6 years. 

### Example

Month in Sim | Grain Height (cm) | Deer | Hunters | Precipitation | Temp (celsius) | 
--- | --- | --- | --- | --- | --- |
0 |  29.88546748 |  3 |  1 | 9.89135 | 8.15104378
1 | 43.09777634 | 4 | 2 |z12.29641 | 3.33126916
2 | 33.93652352 | 3 | 2 | 12.50698 | 14.1750675 | 
3 | 26.3166083 | 4 | 2 | 13.48409 | 23.9843029 | 
4 | 16.15831119 | 3 | 2 | 10.24663 | 21.5713501 | 
5 | 8.538312413 | 4 | 2 | 7.52697 | 26.9437917 | 
6 | 0 | 1 | 2 | 5.62229 | 24.459343
7 | 0 | 0 | 1 | 3.89876 | 20.9438536 | 
8 | 0.064540359 | 0 | 0 | 0.2396 | 16.763755 | 
9 | 0.104305329 | 0 | 0 | 2.6406 | 17.8384611 | 
10 | 15.94313296 | 0 | 0 | 4.0465 | 3.82374869 | 
11 | 33.72312084 | 1 | 0 | 7.29719 | 2.09882101 | 
12 | 39.84647286 | 2 | 1 | 8.01015 | 9.80402205 | 
13 | 36.704092 | 3 | 1 | 12.95817 | 13.0158954 | 
14 | 29.2310961 | 3 | 2 | 14.44527 | 16.678132 | 
15 | 21.61166051 | 4 | 2 | 12.97728 | 22.4648285 | 
16 | 11.45166051 | 3 | 2 | 9.47993 | 28.6707052 | 
17 | 3.833300411 | 4 | 2 | 10.12855 | 21.6058816 | 
18 | 0 | 1 | 2 | 5.84391 | 26.3895671 | 
19 | 0 | 0 | 1 | 4.37084 | 19.3641959 | 
20 | 0.009921113 | 0 | 0 | 1.72118 | 19.2028809 | 
21 | 0.608385753 | 0 | 0 | 1.72445 | 13.9992396 | 
22 | 1.908868471 | 0 | 0 | 3.24289 | 13.0691083 | 
23 | 19.12159084 | 0 | 0 | 6.43981 | 2.24322213 | 
24 | 35.72255548 | 1 | 0 | 10.41654 | 7.57825428 | 
25 | 36.36295245 | 2 | 1 | 12.29696 | 12.1416918 | 
26 | 32.90278332 | 2 | 1 | 12.71426 | 13.3565585 | 
27 | 27.82829171 | 3 | 1 | 12.57884 | 20.415607
28 | 20.20829171 | 3 | 2 | 10.77915 | 28.3772871 | 
29 | 12.58853515 | 4 | 2 | 10.468 | 23.2422129 | 
30 | 2.428539999 | 2 | 2 | 4.45605 | 26.0698276
31 | 0 | 1 | 2 | 2.07503 | 18.6900753 | 
32 | 0 | 0 | 1 | 0.9118 | 19.4949129 | 
33 | 0.026190575 | 0 | 0 | 0.5439 | 17.9131614 | 
34 | 9.070675128 | 0 | 0 | 2.37268 | 7.70983166 | 
35 | 23.899922 | 1 | 0 | 3.48853 | 4.96544096 | 
36 | 40.41835655 | 2 | 1 | 9.29595 | 6.78122838 | 
37 | 45.88333305 | 3 | 1 | 11.54442 | 9.25533294 | 
38 | 41.01855248 | 3 | 2 | 13.20843 | 12.326586 | 
39 | 33.45099599 | 4 | 2 | 13.57075 | 17.9957708 | 
40 | 23.29405295 | 3 | 2 | 11.67478 | 21.0107464
41 | 15.67405295 | 4 | 2 | 8.3207 | 31.0650804 | 
42 | 5.514052955 | 3 | 2 | 5.57068 | 30.40969 | 
43 | 0 | 2 | 2 | 2.70651 | 27.4298265 | 
44 | 0 | 0 | 2 | 0.44943 | 15.0326369 | 
45 | 0.195946471 | 0 | 1 | 3.15703 | 15.9526804 | 
46 | 12.99012401 | 0 | 0 | 3.53166 | 6.68054157 | 
47 | 27.87581303 | 1 | 0 | 6.30835 | 1.43876394 | 
48 | 47.23889953 | 2 | 1 | 8.13287 | 3.95067427 | 
49 | 56.91082855 | 3 | 1 | 12.79602 | 7.77702543 | 
50 | 51.07935311 | 3 | 2 | 11.74645 | 13.2592328 | 
51 | 43.4849717 | 4 | 2 | 11.72684 | 18.8931105 | 
52 | 33.32497653 | 3 | 2 | 12.25831 | 26.5586344 | 
53 | 25.70497653 | 4 | 2 | 9.57019 | 28.7199275 | 
54 | 15.54600604 | 3 | 2 | 6.48392 | 21.9100528 | 
55 | 7.926022985 | 4 | 2 | 3.70065 | 25.0012377 | 
56 | 0 | 1 | 2 | 0.76768 | 18.0081685 | 
57 | 0 | 0 | 1 | 0.98621 | 12.9817157 | 
58 | 2.950927855 | 0 | 0 | 1.23638 | 10.728018 | 
59 | 8.682160207 | 1 | 0 | 3.74294 | 9.97759501 | 
60 | 26.6910743 | 2 | 1 | 7.46545 | 5.58760749 | 
61 | 36.44716485 | 3 | 1 | 10.76758 | 8.07232963 | 
62 | 29.41791366 | 3 | 2 | 11.81991 | 15.0184504 | 
63 | 21.7999678 | 4 | 2 | 13.05766 | 21.3173421 | 
64 | 11.63997748 | 3 | 2 | 12.92123 | 25.6696192 | 
65 | 4.019977482 | 4 | 2 | 9.97066 | 30.8341048 | 
66 | 0 | 1 | 2 | 7.42098 | 21.8731901 | 
67 | 0 | 0 | 1 | 1.98558 | 19.3317752 | 
68 | 0.017068216 | 0 | 0 | 1.866 | 18.6500634 |
69 | 1.375972356 | 0 | 0 | 0.5786 | 12.1726227 | 
70 | 7.202234795 | 0 | 0 | 4.19243 | 10.0819906 | 
71 | 17.96460357 | 1 | 0 | 5.39077 | 0.35862605 | 

![Image of Results](https://github.com/Anthony-ferrari/nature_simulation/blob/main/nature_simulation_graph.png)
