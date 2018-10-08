#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <algorithm>
#include <random>
#include <memory>
#include <array>
#include <chrono>
#include "../Algorithm/BubbleSort.hpp"
#include "../Algorithm/InsertSort.hpp"
#include "../Algorithm/AlgTypesEnum.hpp"

namespace Alg{

    class Visualizer{
        private:
        //Attributes
        Alg::Type algType;
        int numVecElements;

        unsigned int randSeed;
        std::unique_ptr<sf::RenderWindow> window;
        std::unique_ptr<Algorithm> algorithm;
        std::vector<int> vec;
        bool running = true;


        //Private Methods
        void initWindow();
        void initAlg();
        void initVec();
        void visualizeVec();
        void reset();

        public:
        //Public Methods
        Visualizer(Alg::Type alg, int numElements);
        void update();
        void handleEvents();
        bool isRunning();
    };

}