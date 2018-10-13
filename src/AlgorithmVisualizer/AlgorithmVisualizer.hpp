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
#include "../Algorithm/SelectionSort.hpp"
#include "../Algorithm/AlgTypesEnum.hpp"

namespace Alg{

    class Visualizer{
        private:
        //Constants
        const std::array<sf::Color, 3> colors = {sf::Color::Yellow, sf::Color::Green, sf::Color::Blue};

        //Attributes
        Alg::Type algType;
        int numVecElements;

        unsigned int randSeed;
        sf::RenderWindow window;
        std::unique_ptr<Algorithm> algorithm;
        std::vector<int> vec;
        std::vector<int> selectedIndexes;
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