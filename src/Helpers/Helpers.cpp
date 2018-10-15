#include "Helpers.hpp"

namespace Helpers{

    std::chrono::milliseconds now_ms(){
        using namespace std::chrono;
        nanoseconds ns = system_clock::now().time_since_epoch();
        milliseconds ms = duration_cast<milliseconds>(ns);
        return ms;
    }

    void toLower(std::string &str){
        for(char &c : str)
            if(c >= 'A' && c <= 'Z')
                c += 'a' - 'A';
    }

}