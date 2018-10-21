#pragma once
#include "../Algorithm/Algorithm.hpp"

namespace Alg{

    class SelectionSort : public Algorithm{
        private:
        int i = 0;
        int minimum = i;
        int j = i + 1;
        void swap(int &x, int &y);

        public:
        SelectionSort(std::vector<int> &vec);
        std::vector<int> selectedElements() override;
        void run() override;
        void step() override;
    };

}
