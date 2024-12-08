#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum VectorType{
    LEFT,
    RIGHT
};

class InputFiles{
    public:

    InputFiles();
    
    static int open_file(std::string* path,std::ifstream* file);
    static void close_file(std::ifstream* file);
    static void read_vector_info(std::ifstream* file,std::vector<int>* vector,VectorType type);


};