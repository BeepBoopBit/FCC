#ifndef _FILEREADER_H
#define _FILEREADER_H

#include <string>
#include <vector>
#include <fstream>

class FileReader{
private:
    std::string                 _fileName;
    std::vector<std::string>    _fileContent;
    std::ifstream               _fileStream;
public:
    FileReader(std::string fileName){
        _fileName = fileName;
    }
    ~FileReader(){
        _fileStream.close();
    }
    /* File Structure
     * FolderName
     * SetName#1,SetName#2,SetName#3
     * {SetName#1 Data#1,SetName#1 Data#2} {SetName#2 Data#1,SetName#2 Data#2} {SetName#3 Data#1,SetName#3 Data#2}
     */
    std::string getFileContent(){
        _fileStream.open(_fileName);
        if(_fileStream.is_open()){
            std::string line;
            while(std::getline(_fileStream, line)){
                _fileContent.push_back(line + '\n');
            }
        }
    }
};


#endif  // _FILEREADER_H