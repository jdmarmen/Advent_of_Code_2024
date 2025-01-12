#include "InputFiles/InputFiles.hpp"
#include "Divide_and_Conquer/Divide_and_Conquer.hpp"


int main()
{
    std::ifstream file{};
    std::string path = "../Day_1/day_1_puzzle";
    std::vector<int> left{};
    std::vector<int> right{};

    InputFiles::open_file(&path,&file);
    InputFiles::read_vector_info<int>(&file,&left,VectorType::LEFT);
    InputFiles::read_vector_info<int>(&file,&right,VectorType::RIGHT);

    MergeSort::merge_sort(&left,0,left.size()-1);
    MergeSort::merge_sort(&right,0,right.size()-1);

    int dif=0;
    for(int i=0;i<left.size();i++){
        if(left[i]<right[i])
            dif+=right[i]-left[i];
        else
            dif+=left[i]-right[i];
    }
    
    std::cout<<"\n"<<dif<<std::endl;
    
    InputFiles::close_file(&file);
}