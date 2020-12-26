cmake_minimum_required(VERSION 3.17)
project(GLS__FLS)

set(CMAKE_CXX_STANDARD 14)

add_executable(GLS__FLS main.cpp algo/FLS/FLS.cpp algo/FLS/FLS.h algo/Points/Point.cpp algo/Points/Point.h cost/twoOptMoveCost.cpp cost/twoOptMoveCost.h algo/GLS/GLS.cpp algo/GLS/GLS.h algo/TSPSolver.cpp algo/TSPSolver.h data/PointArray.cpp data/PointArray.h diatance/Diatance.cpp diatance/Diatance.h)