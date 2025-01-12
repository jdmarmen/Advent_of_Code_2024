#include <iostream>
#include "InputFiles/InputFiles.hpp"
#include "Dynamic_Programming/Dynamic_Programming.hpp"
#include <vector>
#include <stdint.h>
#include "Binary_Tree/BSTreeDict.h"

BSTreeDict<uint64_t> memo;

uint64_t blinking(int steps,std::vector<uint64_t> stones){
    uint64_t total=0;
    for(auto& stone:stones){
        total+=Dynamic_Programming::count(stone,steps, memo);
    }
    return total;
}


int main(){

    std::ifstream file{};
    std::string path = "../Day_11/day_11_puzzle";
    InputFiles::open_file(&path,&file);

    std::vector<uint64_t> stones{};
    InputFiles::read_vector_info<uint64_t>(&file,&stones,VectorType::HORIZONTAL);
   

    std::cout<<blinking(75,stones)<<std::endl;
    
    InputFiles::close_file(&file);

    return 0;
}