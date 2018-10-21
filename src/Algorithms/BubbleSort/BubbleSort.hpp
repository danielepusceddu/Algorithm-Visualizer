#pragma once
#include "../Algorithm/Algorithm.hpp"

namespace Alg{

    class BubbleSort : public Algorithm{
        private:
        int i = 1;
        int lastSwap = 0;
        void swap(int &x, int &y);

        public:
        BubbleSort(std::vector<int> &vector);
        std::vector<int> selectedElements() override;
        void step() override;
        void run() override;
    };

}