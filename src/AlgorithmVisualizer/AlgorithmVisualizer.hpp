#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <algorithm>
#include <random>
#include <memory>
#include <array>
#include <chrono>
#include "../Algorithm/BubbleSort.hpp"

namespace Alg{

    class Visualizer{
        public:
        //enum for possible algorithms
        enum class AlgType{BubbleSort};

        private:
        //Attributes
        AlgType algType;
        unsigned int randSeed;
        std::unique_ptr<sf::RenderWindow> window;
        std::unique_ptr<Algorithm> algorithm;
        std::vector<int> vec;
        bool running = true;


        //Private Methods
        void initWindow();
        void initAlg(AlgType alg);
        void initVec(int size);
        void visualizeVec();
        void reset();

        public:
        //Public Methods
        Visualizer(AlgType alg);
        void update();
        void handleEvents();
        bool isRunning();
    };

}