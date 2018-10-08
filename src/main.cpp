#include "AlgorithmVisualizer/AlgorithmVisualizer.hpp"
#include <string>

void parseArgs(int argc, char **argv, int &numElements, int &msToSleep, Alg::Type &alg);

int main(int argc, char **argv){
    Alg::Type algorithm = Alg::Type::BubbleSort;
    int numElements = 50;
    int msToSleep = 25;
    parseArgs(argc, argv, numElements, msToSleep, algorithm);
    
    Alg::Visualizer visualizer{algorithm, numElements};
    while(visualizer.isRunning()){
        visualizer.update();
        visualizer.handleEvents();
        sf::sleep(sf::milliseconds(msToSleep));
    }

    return 0;
}


void parseArgs(int argc, char **argv, int &numElements, int &msToSleep, Alg::Type &alg){
    //For each possible command line option
    for(int i = 1; i < argc - 1; i++){
        std::string arg{argv[i]};

        //If option is number of elements
        if(arg == "-e"){
            int arg2int = std::atoi(argv[i+1]);

            //If next arg is a valid amount of elements
            if(arg2int > 0){
                numElements = arg2int;
                i++;
            }
        } //end -e


        //Else if option is milliseconds to sleep in each loop
        else if(arg == "-s"){
            int arg2int = std::atoi(argv[i+1]);

            if(arg2int >= 0){
                msToSleep = arg2int;
                i++;
            }
        } //end -s


        //Else of option is algorithm to visualize
        else if(arg == "-a"){
            std::string algArg{argv[i + 1]};
            Alg::Type alg2arg = Alg::string2algType(algArg);

            if(alg2arg != static_cast<Alg::Type>(-1)){
                alg = alg2arg;
                i++;
            }
        } //end -a

    } //end for
} //end parseArgs