#include "BubbleSort.hpp"

//PUBLIC METHODS


namespace Alg{

    //Constructor
    BubbleSort::BubbleSort(std::vector<int> &vector): Algorithm{vector}{}


    void BubbleSort::step(){
        while(finished == false){
            if(i == 1)
                swapped = false;

            while(i < n){
                if(vec[i - 1] > vec[i]){
                    swap(vec[i - 1], vec[i]);
                    swapped = true;
                }

                i++;
                return; //yield
            }

            if(swapped)
                i = 1;

            else finished = true;
        }
    }


    void BubbleSort::run(){
        int n = vec.size();
        bool swapped = true;

        //Loop till we have a cycle with no swaps happening
        while(swapped){
            swapped = false;

            //For each vector element starting at 1
            for(int i = 1; i < n; i++){
                //If previous element is greater, swap
                if(vec[i - 1] > vec[i]){
                    swap(vec[i - 1], vec[i]);
                    swapped = true;
                }
            }
        }

        finished = true;
    }



    //PRIVATE METHODS
    void BubbleSort::swap(int &x, int &y){
        int z = x;
        x = y;
        y = z;
    }

}