#pragma once
#include "Algorithm.hpp"

namespace Alg{

    class BubbleSort : public Algorithm{
        private:
        int i = 1;
        bool swapped = false;
        void swap(int &x, int &y);

        public:
        BubbleSort(std::vector<int> &vector);
        void step() override;
        void run() override;
    };

}