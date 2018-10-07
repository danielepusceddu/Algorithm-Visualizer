#include "BubbleSort.hpp"

//PUBLIC METHODS

//Constructor
BubbleSort::BubbleSort(std::vector<int> &vector)
: Algorithm{vector}, n{(int)vector.size()}{}



void BubbleSort::step(){
    //Do nothing if sorting has already finished
    if(finished) return;

    //If i is less than n (which is initialized to vec's size)
    if(i < n){
        //Sort [i-1] and [i]
        if(vec[i - 1] > vec[i]){
            swap(vec[i - 1], vec[i]);
            swapped = true;
        }

        i++;
    }

    //If cycle has ended and there were no swaps
    else if(swapped == false) 
        //Sorting has finished
        finished = true;
   
    //Else, start new cycle
    else{
        n--;
        i = 1;
        swapped = false;
    }
}



//PRIVATE METHODS
void BubbleSort::swap(int &x, int &y){
    int z = x;
    x = y;
    y = z;
}