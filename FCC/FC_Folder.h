#ifndef FC_Folder_H
#define FC_Folder_H

#include "FC_Set.h"

class FC_Folder{
public: // Constructors
    FC_Folder(){

    }
    FC_Folder(std::string folderName){
        _folderName = folderName;
    }

public: // Getters
    std::string getFolderName(){
        return _folderName;
    }

public: // Setters
    std::string setFolderName(std::string name){
        _folderName = name;
    }

private: // Variables
    std::vector<FC_Set*> _sets;
    std::string _folderName;
};

#endif // FC_Folder_H