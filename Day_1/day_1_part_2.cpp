#include "InputFiles/InputFiles.hpp"
#include "Divide_and_Conquer/Divide_and_Conquer.hpp"
#include <utility>


int main()
{
    std::ifstream file{};
    std::string path = "/home/jdmarmen/Mis_cosas/UPV/Segundo/PRA/Advent_of_Code_2024/Day_1/day_1_puzzle";
    std::vector<int> left{};
    std::vector<int> right{};

    InputFiles::open_file(&path,&file);
    InputFiles::read_vector_info(&file,&left,VectorType::LEFT);
    InputFiles::read_vector_info(&file,&right,VectorType::RIGHT);

    MergeSort::merge_sort(&left,0,left.size()-1);
    MergeSort::merge_sort(&right,0,right.size()-1);

    int similarity=0;
    for(auto& num:left){
        int rep=0;
        for(auto& num2:right){
            if(num==num2)
                rep++;
        }
        similarity+=num*rep;
    }
    
    std::cout<<"\n"<<similarity<<std::endl;
}