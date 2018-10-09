#pragma once
#include <string>

namespace Alg{
    enum class Type{BubbleSort, InsertSort};
    Type string2algType(std::string str);
    std::string algType2string(Type alg);
}