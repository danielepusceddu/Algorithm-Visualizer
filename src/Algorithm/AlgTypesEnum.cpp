#include "AlgTypesEnum.hpp"
#include "../Helpers/Helpers.hpp"

namespace Alg{

    Type string2algType(std::string str){
        Type type;

        Helpers::toLower(str);
        if(str == "bubblesort")
            type = Type::BubbleSort;

        //I need to replace this with std::optional
        else type = static_cast<Type>(-1);

        return type;
    }

}