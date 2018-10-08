#include "AlgorithmVisualizer/AlgorithmVisualizer.hpp"

int main(){
    Alg::Visualizer visualizer{Alg::Type::BubbleSort};

    while(visualizer.isRunning()){
        visualizer.update();
        visualizer.handleEvents();
        sf::sleep(sf::milliseconds(25));
    }

    return 0;
}