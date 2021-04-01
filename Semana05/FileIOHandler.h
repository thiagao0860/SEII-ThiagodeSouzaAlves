#include <iostream>
#include <string>
#include <fstream>

class FileIOHandler
{
private:
public:
    char buffer[1024] = {0};
    std::string path;
    std::fstream *file;
    int seek_pointer=0;
    int file_length=0;

    FileIOHandler(std::string file_path);
    ~FileIOHandler();
    char* getData();
};


