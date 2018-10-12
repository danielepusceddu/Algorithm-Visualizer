#pragma once
#include <string>

namespace Alg{
    enum class Type{BubbleSort, InsertSort, SelectionSort};
    Type string2algType(std::string str);
    std::string algType2string(Type alg);
}