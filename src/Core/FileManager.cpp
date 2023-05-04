#include "headers/FileManager.hpp"
FileManager::FileManager()
{
    DBG_CTOR("FileManager",this);
    this->file_.open(FILENAME);
    if(!this->file_.is_open()) DBG_ERR("File failed to open");
}
FileManager::~FileManager()
{
    DBG_DTOR("FileManager", this);
    this->file_.close();
}