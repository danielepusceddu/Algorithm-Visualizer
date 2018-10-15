#include "AlgorithmVisualizer/AlgorithmVisualizer.hpp"
#include <iostream>
#include <string>

void parseArgs(int argc, char **argv, int &numElements, std::chrono::milliseconds &msToSleep, Alg::Type &alg, bool &record);
void printArgs(Alg::Type alg, int numElements, std::chrono::milliseconds msToSleep, bool record);

int main(int argc, char **argv){
    //Initialize visualizer settings with default values
    Alg::Type algorithm = Alg::Type::BubbleSort;
    std::chrono::milliseconds msToSleep{25};
    int numElements = 50;
    bool record = false;
    
    //Parse command line arguments for visualizer settings and time to sleep
    parseArgs(argc, argv, numElements, msToSleep, algorithm, record);

    //Let the user know about current visualizer settings
    printArgs(algorithm, numElements, msToSleep, record);
    
    //Construct the visualizer and run it to completion
    Alg::Visualizer visualizer{algorithm, numElements, msToSleep, record};
    visualizer.run();

    return 0;
}


void parseArgs(int argc, char **argv, int &numElements, std::chrono::milliseconds &msToSleep, Alg::Type &alg, bool &record){
    //For each possible command line option
    for(int i = 1; i < argc; i++){
        std::string arg{argv[i]};

        //If option is gif recording flag
        if(arg == "-r")
            record = true;

        //If option is number of elements
        else if(arg == "-e"){
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
                msToSleep = std::chrono::milliseconds{arg2int};
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


void printArgs(Alg::Type alg, int numElements, std::chrono::milliseconds msToSleep, bool record){
    std::cout << "Algorithm: " << Alg::algType2string(alg) << "\n"
              << "Size of Vector: " << numElements << "\n"
              << "Time between each algorithm step: " << msToSleep.count() << "ms" << std::endl;

    if(record)
        std::cout << "Saving the visualization to .gif" << std::endl;
}