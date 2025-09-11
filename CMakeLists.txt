cmake_minimum_required(VERSION 3.31)
project(OOP)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOP main.cpp
        analysis/Analysis.h
        core/CSVLoader.h
        core/CSVLoader.cpp
        core/Report.cpp
        core/Report.h
        analysis/MinMaxAnalysis.cpp
        analysis/MinMaxAnalysis.h
        analysis/StdDevAnalysis.cpp
        analysis/StdDevAnalysis.h
        analysis/MeanAnalysis.h
        analysis/MeanAnalysis.cpp
        analysis/MedianAnalysis.cpp
        analysis/MedianAnalysis.h
        analysis/ModeAnalysis.cpp
        analysis/ModeAnalysis.h)
