#include "AlgorithmVisualizer.hpp"

namespace Alg{
    ////////////////
    //Public Methods
    ////////////////

    //Constructor with initializer list
    Visualizer::Visualizer(Alg::Type alg, int numElements, std::chrono::milliseconds msBetweenSteps)
        : algType{alg}, msBetweenEachStep{msBetweenSteps}, numVecElements{numElements}
    {
        //randSeed = time
        randSeed = std::chrono::system_clock::now().time_since_epoch().count();
        randEng = std::default_random_engine{randSeed};
        initWindow();
        reset();
    }


    //Main loop
    void Visualizer::run(){
        std::chrono::milliseconds lastUpdate{0};
        
        initWindow();
        while(running){
            //Handle user input (such as closing the window)
            handleEvents();

            //Get current time in ms
            std::chrono::milliseconds now = Helpers::now_ms();

            //If enough time has passed, update the visualization
            if(lastUpdate + msBetweenEachStep <= now){
                update();
                lastUpdate = now;
            }

        } //end while running
    } //end run()


    /////////////////
    //Private Methods
    /////////////////
    void Visualizer::update(){
            selectedIndexes = algorithm->selectedElements();
            draw();
            algorithm->step();
    }



    void Visualizer::handleEvents(){
        sf::Event event;

        //While there are events to process
        while(window.pollEvent(event)){
            switch(event.type){
                //User clicked the button to close the window
                case sf::Event::Closed:
                running = false;
                break;

                //User resized the window
                case sf::Event::Resized:{
                sf::FloatRect newViewRect{0, 0, (float)event.size.width, (float)event.size.height};
                window.setView(sf::View{newViewRect});
                draw();
                }
                break;

                //User pressed a key
                case sf::Event::KeyPressed:
                switch(event.key.code){
                    //ESC / Q (quit)
                    case sf::Keyboard::Escape:
                    case sf::Keyboard::Q:
                    running = false;
                    break;

                    //R (restart visualization)
                    case sf::Keyboard::R:
                    reset();
                    draw();
                    break;

                    default:
                    break;
                }   //end key pressed switch
                break;

                //Default
                default:
                break;

            }   //end event type switch
        }   //end while
    }



    //PRIVATE METHODS

    void Visualizer::initWindow(){
        window.create(sf::VideoMode(1080, 720), "Algorithm Visualizer");
        window.setVerticalSyncEnabled(true);
    }



    void Visualizer::reset(){
        initVec();
        initAlg();
    }



    void Visualizer::initVec(){
        vec.resize(numVecElements);

        for(int i = 0; i < numVecElements; i++)
            vec[i] = i + 1;

        std::shuffle(vec.begin(), vec.end(), randEng);
    }



    void Visualizer::initAlg(){
        switch(algType){
            default:
            case Alg::Type::BubbleSort:
            this->algorithm.reset(new BubbleSort{vec});
            break;

            case Alg::Type::InsertSort:
            this->algorithm.reset(new InsertSort{vec});
            break;

            case Alg::Type::SelectionSort:
            this->algorithm.reset(new SelectionSort{vec});
            break;
        }
    }


    void Visualizer::draw(){
        window.clear();
        visualizeVec();
        window.display();
    }


    void Visualizer::visualizeVec(){
        //Get size of window
        sf::Vector2u windowSize = window.getSize();

        //Size of vector and max element
        const int vecSize = vec.size();
        const auto max = std::max_element(vec.begin(), vec.end());

        //Init rectangle that will represent vec's elements
        sf::RectangleShape rectangle;
        float rectWidth = (float)windowSize.x / vecSize;

        //For each element
        for(int i = 0; i < vecSize; i++){
            //See if it is currently selected
            auto found = std::find(selectedIndexes.begin(), selectedIndexes.end(), i);

            //If it's not, rectangle will be white
            if(found == selectedIndexes.end())
                rectangle.setFillColor(sf::Color::White);

            //Else get the respective color
            else rectangle.setFillColor(colors[(int)(found - selectedIndexes.begin())]);

            //Set rectangle height based on the element's value and window height
            float rectHeight = ((float)vec[i] / *max) * windowSize.y;

            //Set rectangle position based on its size and position in the vector
            sf::Vector2f rectPos{rectWidth * i, windowSize.y - rectHeight};

            //Apply changes to the rectangle and draw it
            rectangle.setSize(sf::Vector2f{rectWidth, rectHeight});
            rectangle.setPosition(rectPos);
            window.draw(rectangle);
        }
    }

}