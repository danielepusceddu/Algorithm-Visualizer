#include "InsertSort.hpp"

namespace Alg{

    
    InsertSort::InsertSort(std::vector<int> &vector) : Algorithm{vector}, n{(int)vector.size()}{
        if(n > 1)
            key = vec[i];

        else finished = true;
    }

    void InsertSort::step(){

        if(finished == false){

            if(j >= 0 && vec[j] > vec[j + 1]){
                vec[j + 1] = vec[j];
                vec[j] = key;
                j--;
            }

            else if(++i < n){
                j = i - 1;
                key = vec[i];
            }

            else finished = true;

        }

    }


}