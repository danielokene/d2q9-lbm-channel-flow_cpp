// Boundary conditions are handled during pull streaming
// for the channel-flow solver.
// This module will be used for more advanced boundary
// conditions (e.g., Zou-He, moving walls) in future solvers.


// #include "../include/boundary.h"
// #include "../include/utilities.h"

// namespace LBM
// {

// void applyBounceBack(
//     std::vector<Cell>& f,
//     const Parameters& params)
// {
//     // Bottom wall
//     int y = 0;

//     for (int x = 0; x < params.nx; ++x)
//     {
//         int n = index(x, y, params.nx);

//         f[n][4] = f[n][2];
//         f[n][7] = f[n][5];
//         f[n][8] = f[n][6];
//     }

//     // Top wall
//     y = params.ny - 1;

//     for (int x = 0; x < params.nx; ++x)
//     {
//         int n = index(x, y, params.nx);

//         f[n][2] = f[n][4];
//         f[n][5] = f[n][7];
//         f[n][6] = f[n][8];
//     }
// }

// }