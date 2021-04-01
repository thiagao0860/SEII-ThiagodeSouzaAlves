#include "FileIOHandler.h"

using namespace std;

FileIOHandler::FileIOHandler(string file_path)
{
    this->path=file_path;
    this->file=new ifstream(file_path,ifstream::binary);
    this->file->seekg (0, this->file->end);
    this->file_length = this->file->tellg();
    this->file->seekg (0, this->file->beg);
    this->seek_pointer=0;
}

FileIOHandler::~FileIOHandler()
{
}

char* FileIOHandler::getData(){
    if(this->file_length==this->seek_pointer){return nullptr;}
    if((this->file_length-this->seek_pointer)/1024>0){
        char* returnValue = new char[1024];
        this->file->read(returnValue,1024);
        this->seek_pointer +=1024;
        return returnValue;
    }else if((this->file_length-this->seek_pointer)%1024>0){
        auto tam = (this->file_length-this->seek_pointer);
        char* returnValue = new char[tam];
        this->file->read(returnValue,tam);
        this->seek_pointer += tam;
        return returnValue;
    }
}