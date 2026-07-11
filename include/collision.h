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
}