#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <fstream>
#include "Debug.hpp"
// 1st value will be a null value, second will be the deck size
class FileManager
{
public:
    static constexpr std::string FILENAME{""};
public:
    FileManager();
    ~FileManager();

    void create_new_file();
    void read_file();
private:
    uint16_t deck_size_;


};





#endif 