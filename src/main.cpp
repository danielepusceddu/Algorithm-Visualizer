#include "AlgorithmVisualizer/AlgorithmVisualizer.hpp"

int main(){
    AlgorithmVisualizer visualizer{AlgorithmVisualizer::AlgType::BubbleSort};

    while(visualizer.isRunning()){
        visualizer.update();
        visualizer.handleEvents();
    }

    return 0;
}