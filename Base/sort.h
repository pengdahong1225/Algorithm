//
// Created by Messi on 2023/12/6.
//

#ifndef ALGORITHM_SORT_H
#define ALGORITHM_SORT_H

#include <iostream>
#include <vector>

class sort {
public:
    void bubbleSort(std::vector<int>& nums);
    void simpleSelectSort(std::vector<int>& nums);
    void insertSort(std::vector<int>& nums);
    void shellSort(std::vector<int>& nums);
    void quickSort(std::vector<int>& nums, int L, int R);

};


#endif //ALGORITHM_SORT_H
