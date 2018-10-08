#include "Helpers.hpp"

namespace Helpers{

    void toLower(std::string &str){
        for(char &c : str)
            if(c >= 'A' && c <= 'Z')
                c += 'a' - 'A';
    }

}