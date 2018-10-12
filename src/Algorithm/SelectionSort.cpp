#include "SelectionSort.hpp"

namespace Alg{

    SelectionSort::SelectionSort(std::vector<int> &vec) : Algorithm{vec}{}

    void SelectionSort::step(){

        while(i < n){
            
            while(j < n){
                if(vec[j] < vec[minimum])
                    minimum = j;

                j++;
                return; //yield
            }

            swap(vec[i], vec[minimum]);
            i++;
            minimum = i;
            j = i + 1;
        }

    }


    void SelectionSort::run(){
        int minimum; //position of minimum element

        for(int i = 0; i < n; i++){
            minimum = i;

            for(int j = i + 1; j < n; j++)
                if(vec[j] < vec[minimum])
                    minimum = j;

            swap(vec[i], vec[minimum]);
        }
    }


    void SelectionSort::swap(int &x, int &y){
        int z = x;
        x = y;
        y = z;
    }

}