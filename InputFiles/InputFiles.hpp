#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum VectorType{
    LEFT,
    RIGHT,
    HORIZONTAL
};

class InputFiles{
    public:

    InputFiles();
    
    static int open_file(std::string* path,std::ifstream* file);
    static void close_file(std::ifstream* file);

    template <typename T>
    static void read_vector_info(std::ifstream* file,std::vector<T>* vector,VectorType type){
        int num_right{},num_left{};
        file->clear();
        file->seekg(0);

        if(type==HORIZONTAL){
            int num{};
            while(*file>>num)
                vector->push_back(num);
        }
        else{
            while(*file>>num_left>>num_right){
            if(type==LEFT){
                vector->push_back(num_left);
            }
            else if(type==RIGHT){
                vector->push_back(num_right);
            }
            }            
        }
    }


};