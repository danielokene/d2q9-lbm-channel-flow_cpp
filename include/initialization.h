#pragma once

#include <vector>

#include "lattice.h"
#include "parameters.h"

namespace LBM
{
    // initialize the entire lattice
    void initializeDistributionFunction(
        std::vector<Cell>& f,
        const Parameters& params);
}