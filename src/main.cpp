#include "AlgorithmVisualizer/AlgorithmVisualizer.hpp"

int main(){
    AlgorithmVisualizer visualizer{AlgorithmVisualizer::AlgType::BubbleSort};

    while(visualizer.isRunning()){
        visualizer.update();
        visualizer.handleEvents();
        sf::sleep(sf::milliseconds(25));
    }

    return 0;
}