#include "InputFiles.hpp"

InputFiles::InputFiles(){}


int InputFiles::open_file(std::string* path,std::ifstream* file){
    file->open(*path);

    if(!file->is_open()){
        std::cerr << "Error: could not open file" << std::endl;
        return -1;
    }
    else
        return 0;
}

void InputFiles::close_file(std::ifstream* file){
    file->close();
}

void InputFiles::read_vector_info(std::ifstream* file,std::vector<int>* vector,VectorType type){
        int num_right{},num_left{};
        file->clear();
        file->seekg(0);
        while(*file>>num_left>>num_right){
        if(type==LEFT){
            vector->push_back(num_left);
        }
        else if(type==RIGHT){
            vector->push_back(num_right);
        }
        }
}
