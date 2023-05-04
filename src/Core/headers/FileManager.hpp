#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <fstream>
#include "Debug.hpp"

class FileManager
{
public:
    static constexpr std::string FILENAME{""};
public:
    FileManager();
    ~FileManager();


private:
    std::fstream file_;

};





#endif 