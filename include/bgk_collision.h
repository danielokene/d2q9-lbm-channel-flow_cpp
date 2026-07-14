#pragma once

#include <vector>

#include "lattice.h"
#include "parameters.h"

namespace LBM
{
    void collide(
        const std::vector<Cell>& f, // current distribution function
        std::vector<Cell>& fPostCollision, // distribution function after collision
        const std::vector<double>& rho,
        const std::vector<double>& ux,
        const std::vector<double>& uy,
        const Parameters& params);
}