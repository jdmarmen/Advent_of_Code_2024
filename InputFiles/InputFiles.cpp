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

std::string InputFiles::read_line(std::ifstream* file){
    std::string line{};
    std::getline(*file,line);
    return line;
}

std::vector<std::string> InputFiles::read_lines(std::ifstream* file){
    std::vector<std::string> lines{};
    std::string line{};
    while(std::getline(*file,line)){
        lines.push_back(line);
    }
    return lines;
}


