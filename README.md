# D2Q9 Lattice Boltzmann Method (LBM) Solver in C++
<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-17-blue.svg" alt="C++17">
  <img src="https://img.shields.io/badge/Python-post--processing-green.svg" alt="Python post-processing">
  <img src="https://img.shields.io/badge/LBM-D2Q9-orange.svg" alt="D2Q9">
  <img src="https://img.shields.io/badge/License-MIT-blue.svg" alt="MIT License">
</p>

After implementing the 2D incompressible Channel Flow Navier–Stokes equations using the Finite Difference Method in python (Link here), I wanted to explore an entirely different numerical approach to Computational Fluid Dynamics. I developed this project to learn the **Lattice Boltzmann Method from first principles**, beginning with the microscopic kinetic theory and progressively building a complete CFD solver in C++. Unlike conventional finite difference or finite volume methods that solve the Navier–Stokes equations directly, the Lattice Boltzmann Method models the evolution of particle distribution functions whose collective behaviour reproduces macroscopic fluid flow.

This repository is not intended to compete with production CFD software. Instead, it serves as a learning-focused implementation that will gradually evolve into more advanced LBM solvers, parallel implementations, and complex flow simulations.

---

# What the code does

The solver simulates **pressure-driven laminar channel (Poiseuille) flow** using the standard D2Q9 Lattice Boltzmann Method.

Current implementation includes:

* Serial C++17 solver
* Two-dimensional D2Q9 lattice
* BGK (Single Relaxation Time) collision operator
* Guo forcing scheme for pressure-driven flow
* Streaming step
* Half-way bounce-back wall boundary conditions
* Periodic inlet and outlet boundaries
* Structured Cartesian lattice
* CSV output for velocity and density fields
* Python scripts for visualization and post-processing
* Validation against the analytical Poiseuille velocity profile

Unlike traditional CFD solvers, the algorithm does **not** solve the Navier–Stokes equations directly. Instead, it computes the evolution of particle distribution functions, from which the macroscopic density and velocity fields are recovered.

---

# Example Result

The figure below shows the fully developed velocity profile obtained from the LBM simulation.


---

# Validation

The solver is validated using the analytical solution for fully developed laminar Poiseuille flow.

The primary comparison includes:

* Streamwise velocity profile, **u(y)**, along the channel centreline
* Analytical parabolic velocity profile
* Convergence history of the numerical solution

Future versions of this repository will report:

* L₂ error
* L∞ error
* Grid convergence studies
* Relaxation time sensitivity
* Reynolds number studies

---

# How it works

Unlike conventional CFD methods that discretize the Navier–Stokes equations directly, the Lattice Boltzmann Method advances particle distribution functions on a discrete lattice.

Each iteration performs the following steps:

1. Compute density and velocity from the distribution functions.
2. Evaluate the equilibrium distribution.
3. Perform the BGK collision step.
4. Stream particle populations to neighbouring lattice nodes.
5. Apply bounce-back and periodic boundary conditions.
6. Repeat until the specified number of iterations is reached.

Further details are provided in **docs/METHODOLOGY.md**.

---

# Running

The project is designed to run on Linux or Windows Subsystem for Linux (WSL).

After building with CMake:

```bash
mkdir build
cd build
cmake ..
make
./lbm_channel
```

or with custom simulation parameters:

```bash
./lbm_channel 160 50 20000 0.8 1e-6 200
```

Simulation outputs are written as CSV files and can be visualized using the accompanying Python plotting scripts.

---

# Repository Structure

```text
src/            C++ source files
include/        Header files
scripts/        Python visualization scripts
docs/           Numerical methods and documentation
results/        Simulation outputs and figures
```

---

# Requirements

### Solver

* C++17 compatible compiler
* CMake

### Visualization

* Python 3
* NumPy
* Pandas
* Matplotlib

WSL is recommended for Windows users to provide a Linux-like development environment.

---

# Learning Objectives

This project is part of my Computational Fluid Dynamics learning journey. Through its development, I aim to strengthen my understanding of:

* Kinetic theory of fluids
* Lattice Boltzmann Method (LBM)
* D2Q9 lattice model
* BGK collision operator
* Particle distribution functions
* Numerical solution of fluid flow
* Scientific programming in C++
* Software engineering for scientific computing
* Validation of numerical methods

---

# Future Improvements

Planned extensions include:

* Lid-driven cavity flow using LBM
* Cylinder flow around a circular obstacle
* Zou-He velocity and pressure boundary conditions
* Multiple Relaxation Time (MRT) collision model
* Thermal Lattice Boltzmann Method
* Smagorinsky LES model
* OpenMP parallelization
* MPI domain decomposition
* GPU acceleration using CUDA
* ParaView (VTK) output
* Performance benchmarking
* Comparison with finite-difference Navier–Stokes solvers

---

# References

1. Krüger, T., Kusumaatmaja, H., Kuzmin, A., Shardt, O., Silva, G., & Viggen, E. **The Lattice Boltzmann Method: Principles and Practice.** Springer, 2017.

2. Succi, S. **The Lattice Boltzmann Equation for Fluid Dynamics and Beyond.** Oxford University Press, 2001.

3. Mohamad, A. A. **Lattice Boltzmann Method: Fundamentals and Engineering Applications with Computer Codes.** Springer, 2011.

4. Guo, Z., Zheng, C., & Shi, B. (2002). *Discrete lattice effects on the forcing term in the lattice Boltzmann method.* Physical Review E, 65(4).

---

# Acknowledgements

This project is being developed as part of my Computational Fluid Dynamics learning journey while exploring numerical methods beyond the classical finite difference approach. The implementation is built from first principles through extensive study of the Lattice Boltzmann Method literature and is structured to document both the numerical concepts and the software engineering practices involved in developing a CFD solver from scratch.

---

# License

Released under the MIT License.