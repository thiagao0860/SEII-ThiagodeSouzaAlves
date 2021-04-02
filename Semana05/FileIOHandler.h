#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class FileIOHandler
{
private:
    std::string path;
    std::fstream *file;
    int seek_pointer;
    int file_length;

public:
    enum type{
        INPUT = 0 ,
        OUTPUT = 1
    };
    FileIOHandler(std::string file_path,int mode);
    ~FileIOHandler();
    std::vector<char> getData();
    void setData(std::vector<char> data);
};


