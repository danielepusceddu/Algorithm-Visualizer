#include "BubbleSort.hpp"

//PUBLIC METHODS


namespace Alg{

    //Constructor
    BubbleSort::BubbleSort(std::vector<int> &vector): Algorithm{vector}{}


    void BubbleSort::step(){
        while(finished == false){

            while(i < n){
                if(vec[i - 1] > vec[i]){
                    swap(vec[i - 1], vec[i]);
                    lastSwap = i;
                    return; //yield to show the swap taking place.                    
                }

                i++;
                //this conditional is to avoid showing vec[n] as selected
                //if i < n, i = 1 (or finish) then yield
                if(i < n) 
                    return; //yield
            }

            if(lastSwap > 1){
                i = 1;
                n = lastSwap;
                lastSwap = 0;
                return; //yield
            }

            else finished = true;
        }
    }


    void BubbleSort::run(){
        int n = vec.size();
        int lastSwap;

        //Loop till we have a cycle with no swaps happening
        while(n > 1){
            lastSwap = 0;

            //For each vector element starting at 1
            for(int i = 1; i < n; i++){
                //If previous element is greater, swap
                if(vec[i - 1] > vec[i]){
                    swap(vec[i - 1], vec[i]);
                    lastSwap = i;
                }
            }

            //Do not check the already sorted part of the vector
            n = lastSwap;
        }

        finished = true;
    }


    std::vector<int> BubbleSort::selectedElements(){
        std::vector<int> selected;

        if(!finished)
            selected = {i, i - 1};

        return selected;
    }



    //PRIVATE METHODS
    void BubbleSort::swap(int &x, int &y){
        int z = x;
        x = y;
        y = z;
    }

}