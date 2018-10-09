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



    //PRIVATE METHODS
    void BubbleSort::swap(int &x, int &y){
        int z = x;
        x = y;
        y = z;
    }

}