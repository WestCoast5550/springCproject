cmake_minimum_required(VERSION 3.7.2)
project(RecursiveTemplate)

set(CMAKE_CXX_STANDARD 14)

add_executable(RecursiveTemplate main.cpp Constraint.h ProblemSolver.h QBoundaryConstraint.h)