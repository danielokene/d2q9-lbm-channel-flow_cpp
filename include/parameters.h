#pragma once

namespace LBM
{
    struct Parameters // data structure for simulation parameters
    {
        int nx = 160; // number of lattice node in the x-direction
        int ny = 50; // number of lattice node in the y-direction

        int steps = 20000; // number of timestep
        int saveEvery = 200; // to save data after every 200 timestep
        int outputInterval = 1000; // to output data after every 1000 steps

        double tau = 0.8; // relaxation time
        double forceX = 1e-6; // body force (to show pressure difference)
    };
}
