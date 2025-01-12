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


