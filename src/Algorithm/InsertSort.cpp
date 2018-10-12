#include "InsertSort.hpp"

namespace Alg{


    InsertSort::InsertSort(std::vector<int> &vector) : Algorithm{vector}{
        if(n > 1)
            key = vec[i];

        else finished = true;
    }

    void InsertSort::step(){

        while(i < n){

            while(j >= 0 && vec[j] > vec[j + 1]){
                vec[j + 1] = vec[j];
                vec[j] = key;
                j--;
                return; //yield
            }

            i++;
            j = i - 1;
            key = vec[i];
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
            selected = {i, j, key};

        return selected;
    }

}