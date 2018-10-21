#pragma once
#include "../Algorithm/Algorithm.hpp"

namespace Alg{

    class InsertSort : public Algorithm{
        private:
        int key;
        int i = 1;
        int j = 0;
        bool swapShown = false;

        public:
        InsertSort(std::vector<int> &vector);
        void step() override;
        void run() override;
        std::vector<int> selectedElements() override;
    };

}