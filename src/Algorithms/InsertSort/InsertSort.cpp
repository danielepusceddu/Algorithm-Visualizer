#include "InsertSort.hpp"

namespace Alg{


    InsertSort::InsertSort(std::vector<int> &vector) : Algorithm{vector}{
        if(n > 1)
            key = vec[i];

        else finished = true;
    }

    void InsertSort::step(){

        while(i < n){

            //swapShown is so we can show the changes in the selected elements
            while(j >= 0 && (vec[j] > vec[j + 1] || swapShown)){

                //If we haven't swapped
                //(vec[j] > vec[j + 1]) will be false after executing this block
                //swapShown will allow us to keep sorting
                if(!swapShown){
                    vec[j + 1] = vec[j];
                    vec[j] = key;
                    swapShown = true;
                    return; 
                }

                j--;
                swapShown = false;
                if(j >= 0) //this check is to avoid showing vec[-1] as a selected element
                    return; //yield
            }

            i++;
            j = i - 1;

            if(i < n){ //this check is to avoid showing vec[n] as a selected element
                key = vec[i];
                return; //yield
            }
        }

        finished = true;
    }


    void InsertSort::run(){
        int n = vec.size();

        //For each element starting at 1
        for(int i = 1; i < n; i++){
            int key = vec[i];

            //While previous element is greater, swap them
            for(int j = i - 1; j >= 0 && vec[j] > vec[j + 1]; j--){
                vec[j + 1] = vec[j];
                vec[j] = key;
            }
        }

        finished = true;
    }


    std::vector<int> InsertSort::selectedElements(){
        std::vector<int> selected;

        if(!finished)
            selected = {i, j, j+1};

        return selected;
    }

}