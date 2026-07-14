#pragma once

#include <string>
#include <vector>

#include "parameters.h"

namespace LBM
{
    void writeCSV(
        const std::string& filename,
        const std::vector<double>& rho,
        const std::vector<double>& ux,
        const std::vector<double>& uy,
        const Parameters& params);
}