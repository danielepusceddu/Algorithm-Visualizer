#pragma once
#include "Algorithm.hpp"

namespace Alg{

    class InsertSort : public Algorithm{
        private:
        int key;
        int i = 1;
        int j = 0;

        public:
        InsertSort(std::vector<int> &vector);
        void step() override;
    };

}