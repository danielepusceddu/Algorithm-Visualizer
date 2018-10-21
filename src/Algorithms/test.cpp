//Quick and dirty code to check accuracy of Algorithm objects
//define TO_TEST with the name of the Algorithm Class to test

#include "algorithms.hpp"
#include <algorithm>
#include <memory>
#include <iostream>
#include <random>
#include <chrono>

#define TO_TEST BubbleSort

void randVec(std::vector<int> &vec, std::default_random_engine &eng);

int main(){
    unsigned int randSeed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine randEng{randSeed};


    std::unique_ptr<Alg::Algorithm> alg;
    std::vector<int> vec;

    //Testing step()
    for(int testCount = 0; testCount < 500; testCount++){
        randVec(vec, randEng);
        std::vector<int> backup = vec;

        alg.reset(new Alg::TO_TEST{vec});
        while(!alg->isFinished()) alg->step();

        if(std::is_sorted(vec.begin(), vec.end()) == false){
            std::cout << "Step method failed! Test num " << testCount + 1 << std::endl;
            break;
        }
    }



    //Testing run()
    for(int testCount = 0; testCount < 500; testCount++){
        randVec(vec, randEng);
        std::vector<int> backup = vec;

        alg.reset(new Alg::TO_TEST{vec});
        alg->run();

        if(std::is_sorted(vec.begin(), vec.end()) == false){
            std::cout << "Run method failed! Test num " << testCount + 1 << std::endl;
            break;
        }
    }

    return 0;
}


void randVec(std::vector<int> &vec, std::default_random_engine &eng){
    std::uniform_int_distribution<unsigned> dist{2, 1000};
    vec.clear();
    vec.resize(dist(eng));

    for(int &x : vec)
        x = dist(eng);
}