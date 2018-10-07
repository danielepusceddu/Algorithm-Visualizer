#include "AlgorithmVisualizer.hpp"


//Public Methods
bool AlgorithmVisualizer::isRunning(){
    return running;
}


AlgorithmVisualizer::AlgorithmVisualizer(AlgorithmVisualizer::AlgType alg)
    : algType{alg} {
    initWindow();
    reset();
}



void AlgorithmVisualizer::update(){
    if(algorithm->isFinished() == false){
        window->clear();

        algorithm->step();
        visualizeVec();
        
        window->display();
    }
}



void AlgorithmVisualizer::handleEvents(){
    sf::Event event;

    //While there are events to process
    while(window->pollEvent(event)){
        switch(event.type){
            //User clicked the button to close the window
            case sf::Event::Closed:
            running = false;
            break;

            //User pressed a key
            case sf::Event::KeyPressed:
            switch(event.key.code){
                //ESC (quit)
                case sf::Keyboard::Escape:
                running = false;
                break;

                //R (restart visualization)
                case sf::Keyboard::R:
                reset();
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

void AlgorithmVisualizer::initWindow(){
    window.reset(new sf::RenderWindow{sf::VideoMode(1080, 720), "Algorithm Visualizer"});
}



void AlgorithmVisualizer::reset(){
    //randSeed = time
    randSeed = std::chrono::system_clock::now().time_since_epoch().count();
    initVec(200);
    initAlg(algType);
}



void AlgorithmVisualizer::initVec(int size){
    vec.resize(size);

    for(int i = 0; i < size; i++)
        vec[i] = i + 1;

    std::shuffle(vec.begin(), vec.end(), std::default_random_engine{randSeed});
}



void AlgorithmVisualizer::initAlg(AlgorithmVisualizer::AlgType alg){
    switch(alg){
        default:
        case AlgorithmVisualizer::AlgType::BubbleSort:
        this->algorithm.reset(new BubbleSort{vec});
        break;
    }
}



void AlgorithmVisualizer::visualizeVec(){
    //Get size of window
    sf::Vector2u windowSize = window->getSize();

    //Size of vector and max element
    const int vecSize = vec.size();
    const auto max = std::max_element(vec.begin(), vec.end());

    //Init rectangle that will represent vec's elements
    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color::White);
    float rectWidth = (float)windowSize.x / vecSize;

    //For each element
    for(int i = 0; i < vecSize; i++){
        //Set rectangle height based on the element's value and window height
        float rectHeight = ((float)vec[i] / *max) * windowSize.y;

        //Set rectangle position based on its size and position in the vector
        sf::Vector2f rectPos{rectWidth * i, windowSize.y - rectHeight};

        //Apply changes to the rectangle and draw it
        rectangle.setSize(sf::Vector2f{rectWidth, rectHeight});
        rectangle.setPosition(rectPos);
        window->draw(rectangle);
    }
}