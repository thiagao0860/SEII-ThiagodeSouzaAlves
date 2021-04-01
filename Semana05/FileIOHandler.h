#include <iostream>
#include <string>
#include <fstream>

class FileIOHandler
{
    
private:
    std::string path;
    std::ifstream *file;
    int seek_pointer;
    int file_length;

public:

    FileIOHandler(std::string file_path);
    ~FileIOHandler();
    char* getData();
    void setData(char* data);
};


