#pragma once
#include <map>
#include <stdint.h>
#include "Binary_Tree/BSTreeDict.h"

class Dynamic_Programming{
    public:
        static uint64_t count (uint64_t stone, int steps,BSTreeDict<uint64_t>& memoDict);

    private:
        // AUXILIARY FUNCTIONS THAT HAVE NOTHING TO DO WITH DYNAMIC PROGRAMMING BUT ARE NECESSARY FOR THE ALGORITHM
        static bool is_even(uint64_t num);
        static uint64_t count_digits(uint64_t num);
        static void divide_number(uint64_t number, uint64_t* n1, uint64_t* n2);
};