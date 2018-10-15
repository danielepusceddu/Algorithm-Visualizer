#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <algorithm>
#include <random>
#include <memory>
#include <array>
#include <chrono>
#include "../Helpers/Helpers.hpp"
#include "../Algorithm/BubbleSort.hpp"
#include "../Algorithm/InsertSort.hpp"
#include "../Algorithm/SelectionSort.hpp"
#include "../Algorithm/AlgTypesEnum.hpp"

namespace Alg{

    class Visualizer{
        public:

        /////////////////
        //Public Methods
        /////////////////
        Visualizer(Alg::Type alg, int numElements, std::chrono::milliseconds msBetweenSteps);
        void run();
        void update();
        void handleEvents();
        bool isRunning();


        private:

        //Constants
        const std::array<sf::Color, 3> colors = {sf::Color::Yellow, sf::Color::Green, sf::Color::Blue};

        ////////////
        //Attributes
        ////////////
        bool running = true;

        //Algorithm to Visualize
        Alg::Type algType;
        std::unique_ptr<Algorithm> algorithm;
        std::vector<int> selectedIndexes;
        std::chrono::milliseconds msBetweenEachStep;

        //Vector to sort
        std::vector<int> vec;
        int numVecElements;

        //Random to shuffle the vector
        unsigned int randSeed;
        std::default_random_engine randEng;

        //SFML Window to draw on
        sf::RenderWindow window;


        /////////////////
        //Private Methods
        /////////////////
        void initWindow();
        void initAlg();
        void initVec();
        void visualizeVec();
        void draw();
        void reset();
    };

}