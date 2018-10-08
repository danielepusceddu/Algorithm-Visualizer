#include "AlgorithmVisualizer/AlgorithmVisualizer.hpp"
#include <string>

void parseArgs(int argc, char **argv, int &numElements);

int main(int argc, char **argv){
    int numElements = 50;
    parseArgs(argc, argv, numElements);
    
    Alg::Visualizer visualizer{Alg::Type::BubbleSort, numElements};

    while(visualizer.isRunning()){
        visualizer.update();
        visualizer.handleEvents();
        sf::sleep(sf::milliseconds(25));
    }

    return 0;
}


void parseArgs(int argc, char **argv, int &numElements){
    //For each optional argument
    for(int i = 1; i < argc; i++){
        std::string arg{argv[i]};

        //If arg is number of elements and there is at least one more arg to process
        if(arg == "-e" && i < argc - 1){
            int atoi = std::atoi(argv[i+1]);

            //If next arg is a valid number
            if(atoi > 0){
                numElements = atoi;
                i++;
            }
        }
    }
}