#include "../include/output.h"
#include "../include/utilities.h"

#include <fstream>
#include <iomanip>
#include <cmath>

namespace LBM
{
    void writeCSV(
        const std::string& filename,
        const std::vector<double>& rho,
        const std::vector<double>& ux,
        const std::vector<double>& uy,
        const Parameters& params)
    {
        std::ofstream file(filename);

        if (!file.is_open())
        {
            return;
        }

        file << "x,y,rho,ux,uy,velocity\n";

        file << std::fixed << std::setprecision(8);

        for (int y = 0; y < params.ny; ++y)
        {
            for (int x = 0; x < params.nx; ++x)
            {
                const int n = index(x, y, params.nx);

                const double velocity =
                    std::sqrt(ux[n] * ux[n] +
                            uy[n] * uy[n]);

                file
                    << x << ","
                    << y << ","
                    << rho[n] << ","
                    << ux[n] << ","
                    << uy[n] << ","
                    << velocity << "\n";
            }
        }
    }
}