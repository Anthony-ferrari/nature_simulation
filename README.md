
# nature_simulation
This program is a nature simulator using functional decomposition design for entity interaction and state synchronization. It simulates grain growth, deer population growth, and hunter population growth by accessing environment variables like precipitation factors and temperature factors. 
#### Features 
- [x] Utilizies OpenMP's omp sections to break down the updating of current state and moving to the next state at an entity level. 
- [x] Allows synchronization to occur with a Watcher class that updates environment variables and moves the entire program forward. Makes use of implied barriers for all entities to be at the same step. 
- [x] Implemented a functional decomposition design for easier synchronization. 
- [x] Simulates grain growth, deer population growth, and hunter population growth for 6 years. 

### Example
