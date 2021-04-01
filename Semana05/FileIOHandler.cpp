#include "FileIOHandler.h"

using namespace std;

FileIOHandler::FileIOHandler(string file_path)
{
    this->path=file_path;
    this->file=new fstream(file_path,fstream::binary);
    this->file->seekg (0, this->file->end);
    this->file_length = this->file->tellg();
    this->file->seekg (0, this->file->beg);

}

FileIOHandler::~FileIOHandler()
{
}

char* FileIOHandler::getData(){
    if(this->file_length==this->seek_pointer){return nullptr;}
    if((this->file_length-this->seek_pointer)/1024>0){
        this->file->read(this->buffer,1024);
        this->seek_pointer +=1024;
        return this->buffer;
    }else if((this->file_length-this->seek_pointer)%1024>0){
        this->file->read(this->buffer,(this->file_length-this->seek_pointer));
        this->seek_pointer +=(this->file_length-this->seek_pointer);
        return this->buffer;
    }
}