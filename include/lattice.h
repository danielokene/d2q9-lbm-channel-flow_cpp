#pragma once

#include <array>
#include <vector>
#include "parameters.h"

// defining the discrete lattice namespace
namespace LBM
{
    constexpr int Q = 9; // number of directions

    using Cell = std::array<double, Q>; // stores distribution function of each lattice nodes

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

    // initialize the equillibrium distribution function
    inline double equilibrium (
        int direction,
        double rho,
        double ux,
        double uy)
    {
        const double cu = 
            cx[direction] * ux +
            cy[direction] * uy;

        const double uSquared =
            ux * ux + uy * uy;
        
        return weights[direction] * rho *
            (
                1.0 + 3.0 * cu +
                4.5 * cu * cu
                - 1.5 * uSquared
            );
    }

    // Guo forcing scheme implementation
    inline double forcingTerm(
    int direction,
    double omega,
    double ux,
    double uy,
    double forceX)
    {
        const double ciDotU =
        cx[direction] * ux +
        cy[direction] * uy;

        const double forceDotCi =
        cx[direction] * forceX;

        return weights[direction]
            * (1.0 - 0.5 * omega)
            * (
                3.0 * forceDotCi
                + 9.0 * ciDotU * forceDotCi
                - 3.0 * ux * forceX
        );
    }
}