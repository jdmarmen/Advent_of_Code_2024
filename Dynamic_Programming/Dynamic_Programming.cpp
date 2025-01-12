#include "Dynamic_Programming/Dynamic_Programming.hpp"

uint64_t Dynamic_Programming::count(uint64_t stone, int steps, BSTreeDict<uint64_t>& memoDict){
    if(steps == 0)
        return 1;

    std::string key = std::to_string(stone) + "_" + std::to_string(steps);
    try {
        uint64_t cachedValue = memoDict.search(key);
        return cachedValue;
    } catch(const std::runtime_error&) {
    }

    uint64_t result;
    if(stone == 0){
        result = count(1, steps - 1, memoDict);
    } 
    else if(is_even(count_digits(stone))){
        uint64_t left_stone, right_stone;
        divide_number(stone, &left_stone, &right_stone);
        result = count(left_stone, steps - 1, memoDict) + count(right_stone, steps - 1, memoDict);
    } 
    else {
        result = count(stone * 2024, steps - 1, memoDict);
    }

    memoDict.insert(key, result);
    return result;
}

bool Dynamic_Programming::is_even(uint64_t num){
    return num%2==0;
}

uint64_t Dynamic_Programming::count_digits(uint64_t num){
    if (num==0)
        return 1;
    else{
        uint64_t count=0;
        while(num!=0){
            num/=10;
            count++;
        }
        return count;
    }
}

void Dynamic_Programming::divide_number(uint64_t number, uint64_t* n1, uint64_t* n2) {
    
    uint64_t digits = count_digits(number);

    uint64_t divisor = 1;
    for(uint64_t i = 0; i < digits/2; i++) {
        divisor *= 10;
    }
    
    *n1 = number / divisor;
    *n2 = number % divisor;

}