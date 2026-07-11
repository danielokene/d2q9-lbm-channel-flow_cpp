#pragma once

#include <array>
#include <vector>
#include "parameters.h"
#include "utilities.h"

// defining the discrete lattice namespace
namespace LBM
{
    constexpr int Q = 9; // number of directions

    using Cell = std::array<double, Q>; // stores probability function of each lattice nodes

    constexpr std::array<int, Q> cx =
    {
        0, 1, 0, -1, 0, 1, -1, -1, 1
    }; // x-velocity vector

    constexpr std::array<int, Q> cy =
    {
        0, 0, 1, 0, -1, 1, 1, -1, -1
    }; // y-velocity vector

    constexpr std::array<int, Q> opposite =
    {
        0, 3, 4, 1, 2, 7, 8, 5, 6
    }; // opposite direction for straming and bouncing-back

    constexpr std::array<double, Q> weights =
    {
        4.0/9.0,
        1.0/9.0,
        1.0/9.0,
        1.0/9.0,
        1.0/9.0,
        1.0/36.0,
        1.0/36.0,
        1.0/36.0,
        1.0/36.0
    };

    // initialize the entire lattice
    void initialize(
        std::vector<Cell>& f,
        const Parameters& params)
    {
        const int totalCells = params.nx * params.ny;

        f.resize(totalCells);

        for (int y = 0; y < params.ny; ++y)
        {
            for (int x = 0; x < params.nx; ++x)
            {
                const int n = index(x, y, params.nx);

                for (int k = 0; k < Q; ++k)
                {
                    f[n][k] = equilibrium(k, 1.0, 0.0, 0.0);
                }
            }
        }
    }
}