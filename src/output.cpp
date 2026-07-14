#include "../include/output.h"
#include "../include/utilities.h"

#include <fstream>
#include <filesystem>
#include <iomanip>
#include <cmath>

namespace fs = std::filesystem;

namespace LBM
{
    void writeCSV(
        const std::string& filename,
        const std::vector<double>& rho,
        const std::vector<double>& ux,
        const std::vector<double>& uy,
        const Parameters& params)
    {
        // Create results directory if it doesn't exist
        fs::create_directories("results");
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

    void appendResidual(
    const std::string& filename,
    int iteration,
    double residual)
    {
        // Create results directory if it doesn't exist
        fs::create_directories("results");

        bool fileExists = fs::exists(filename);

        std::ofstream file(filename, std::ios::app);

        if (!file)
        {
            return;
        }

        // Write header only once
        if (!fileExists)
        {
            file << "Iteration,Residual\n";
        }

        file << iteration
            << ","
            << residual
            << "\n";
    }

}