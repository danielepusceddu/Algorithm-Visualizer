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


}