cmake_minimum_required(VERSION 2.8.9)
project(AlgorithmVisualizer)

#C++11 Standard
set(CMAKE_CXX_STANDARD 11)

#Extended Warnings
set(CMAKE_CXX_FLAGS -Wall)

#Source file list
set(SOURCE_FILES src/main.cpp 
                 src/AlgorithmVisualizer/AlgorithmVisualizer.cpp
                 src/Algorithm/BubbleSort.cpp
                 src/Algorithm/InsertSort.cpp
                 src/Algorithm/AlgTypesEnum.cpp
                 src/Helpers/Helpers.cpp)


add_executable(AlgorithmVisualizer ${SOURCE_FILES})
target_link_libraries(AlgorithmVisualizer -lsfml-graphics -lsfml-window -lsfml-system)