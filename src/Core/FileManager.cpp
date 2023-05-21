#include "headers/FileManager.hpp"
FileManager::FileManager()
:deck_size_(0)
{
    DBG_CTOR("FileManager",this);
    std::ifstream file(FILENAME,std::ios::in);
    if(!file.is_open()) create_new_file();

    file.close();
}
FileManager::~FileManager()
{
    DBG_DTOR("FileManager", this);
}
void FileManager::create_new_file()
{
    std::ofstream file(FILENAME,std::ios::out);
    file << "*,";
    file << 36 << ',';
    file.close();
}
void FileManager::read_file()
{
    std::ifstream file(FILENAME, std::ios::in);
    if(!file.is_open()) 
    {
        create_new_file();
        DBG_ERR("File failed to open, new file created");
    }
    file.seekg(0,std::ios::end);
    std::streampos size = file.tellg();
    char* memblock = new char[size];
    file.read(memblock,size);
    
    delete[] memblock;
}