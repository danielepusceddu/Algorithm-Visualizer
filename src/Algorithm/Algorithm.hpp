#pragma once
#include <vector>

namespace Alg{

    class Algorithm{
        protected:
        std::vector<int> &vec;
        bool finished = false;

        public:
        Algorithm(std::vector<int> &vector) : vec{vector} {};
        virtual ~Algorithm() = default;

        std::vector<int>& getVec() const {return vec;}
        bool isFinished() const {return finished;}
        virtual void step() = 0; //pure virtual function

    };

}