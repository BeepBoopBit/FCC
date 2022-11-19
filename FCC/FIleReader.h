#ifndef _FILEREADER_H
#define _FILEREADER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class FileReader{
private:
    std::string                 _fileName;
    std::vector<std::string>    _fileContent;
    std::ifstream               _fileStream;
public:
    FileReader(std::string fileName){
        _fileName = fileName;
    }
    FileReader(){
        _fileName = "FCC\\data.dat";
    }
    ~FileReader(){
        _fileStream.close();
    }
    /* File Structure
     * FolderName
     * SetName#1,SetName#2,SetName#3
     * {SetName#1 Data#1,SetName#1 Data#2} {SetName#2 Data#1,SetName#2 Data#2} {SetName#3 Data#1,SetName#3 Data#2}
     */
    void saveFileContent(std::vector<std::string> &folderName, std::vector<std::vector<std::string>> &setName, std::vector<std::vector<std::string>> &setData){
        _fileStream.open(_fileName);
        if(_fileStream.is_open()){
            std::string line;
            int count = 0;
            while(std::getline(_fileStream, line)){
                if(count == 0){
                    folderName.push_back(line);
                }else if(count == 1){
                    std::string myLine = line;
                    std::vector<std::string> setValues = splitString(myLine, ',');
                    std::vector<std::string> setNames;
                    for(int i = 0; i < setValues.size(); i++){
                        setNames.push_back(setValues[i]);
                    }
                    setName.push_back(setNames);
                }else if(count == 2){
                    std::string myLine = line;
                    std::vector<std::string> setValues = splitString(myLine, ';');
                    std::vector<std::string> setValuesOrganize;
                    for(int i = 0; i < setValues.size(); ++i){
                        std::string myLine = setValues[i];
                        std::vector<std::string> setValues = splitString(myLine, ',');
                        for(int i = 0; i < setValues.size(); ++i){
                            setValuesOrganize.push_back(setValues[i]);
                        }
                        setData.push_back(setValuesOrganize);
                    }
                    count = -1;
                }
                count++;
            }
        }
    }

// Auxillary
private:
    std::vector<std::string> splitString(std::string str, char delimiter){
        std::vector<std::string> internal;
        std::stringstream ss(str); // Turn the string into a stream.
        std::string tok;
        
        while(std::getline(ss, tok, delimiter)) {
            internal.push_back(tok);
        }
        
        return internal;
    }
};


#endif  // _FILEREADER_H