#include "FileIOHandler.h"

using namespace std;

FileIOHandler::FileIOHandler(string file_path, int mode)
{
    this->path=file_path;
    if (mode == FileIOHandler::INPUT){
    this->file=new fstream(file_path, fstream::in | fstream::binary );
    }
    if (mode == FileIOHandler::OUTPUT){
    this->file=new fstream(file_path, fstream::out | fstream::binary );
    }
    this->file->seekg (0, this->file->end);
    this->file_length = this->file->tellg();
    this->file->seekg (0, this->file->beg);
    this->seek_pointer=0;
}

FileIOHandler::~FileIOHandler()
{   
    this->file->close();
    delete this->file;
}

vector<char> FileIOHandler::getData(){
    if(this->file_length==this->seek_pointer){
        this->seek_pointer=0;
        this->file->seekg(0, this->file->beg);
        return vector<char>(0);
    }else if((this->file_length-this->seek_pointer)/1024>0){
        vector<char> returnValue(1024);
        this->file->read(&returnValue[0],1024);
        this->seek_pointer +=1024;        
        return returnValue;
    }else if((this->file_length-this->seek_pointer)%1024>0){
        fstream::pos_type tam = (this->file_length-this->seek_pointer);
        vector<char> returnValue(tam);
        this->file->read(&returnValue[0],tam);
        this->seek_pointer += tam;
        return returnValue;
    }
}

void FileIOHandler::setData(vector<char> data){
    this->file->write(&data[0],data.size());
}