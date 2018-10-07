#pragma once
#include "Algorithm.hpp"


class BubbleSort : public Algorithm{
    private:
    int i = 1;
    int n;
    bool swapped = false;
    void swap(int &x, int &y);

    public:
    BubbleSort(std::vector<int> &vector);
    void step() override;
};