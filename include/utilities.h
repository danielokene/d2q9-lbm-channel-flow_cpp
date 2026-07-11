#pragma once

#include "lattice.h"


// helper functions

inline int index(int x, int y, int nx)
{
    return x + y * nx;
} // node index function

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