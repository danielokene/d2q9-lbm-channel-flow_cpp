#pragma once

#include <vector>

#include "lattice.h"
#include "parameters.h"

namespace LBM
{
    void computeMacroscopic(
        const std::vector<Cell>& f,
        std::vector<double>& rho,
        std::vector<double>& ux,
        std::vector<double>& uy,
        const Parameters& params);

    void collide(
        const std::vector<Cell>& f, // current distribution function
        std::vector<Cell>& fPostCollision, // distribution function after collision
        const std::vector<double>& rho,
        const std::vector<double>& ux,
        const std::vector<double>& uy,
        const Parameters& params);
}