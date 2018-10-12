#include "AlgTypesEnum.hpp"
#include "../Helpers/Helpers.hpp"

namespace Alg{

    Type string2algType(std::string str){
        Type type;

        Helpers::toLower(str);
        if(str == "bubble" || str == "bubblesort" )
            type = Type::BubbleSort;

        else if(str == "insert" || str == "insertsort")
            type = Type::InsertSort;

        else if(str == "selection" || str == "selectionsort")
            type = Type::SelectionSort;

        //I need to replace this with std::optional
        else type = static_cast<Type>(-1);

        return type;
    }


    std::string algType2string(Type alg){
        std::string str;

        switch(alg){
            case Type::BubbleSort:
            str = "Bubble Sort";
            break;

            case Type::InsertSort:
            str = "Insert Sort";
            break;

            case Type::SelectionSort:
            str = "Selection Sort";
            break;

            default:
            str = "Null";
            break;
        }

        return str;
    }

}