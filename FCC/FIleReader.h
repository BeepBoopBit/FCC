#ifndef _FILEREADER_H
#define _FILEREADER_H

#include <string>
#include <fstream>

class FileReader{
private:
    std::string _fileName;
    std::string _fileContent;
    std::ifstream _fileStream;
public:
    FileReader(std::string fileName){
        _fileName = fileName;
    }
    ~FileReader(){
        _fileStream.close();
    }
    std::string getFileContent(){
        _fileStream.open(_fileName);
        if(_fileStream.is_open()){
            std::string line;
            while(std::getline(_fileStream, line)){
                _fileContent += line + ' ';
            }
        }
    }
};


#endif  // _FILEREADER_H