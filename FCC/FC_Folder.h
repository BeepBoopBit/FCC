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

public: // Important functions
    void useSet(int index){
        _currentSet = _sets[index];
    }

public: // Getters
    std::string getFolderName(){
        return _folderName;
    }

    void showSets(){
        for(int i = 0; i < _sets.size(); ++i){
            std::cout << "[" << i << "] " << _sets[i]->getSetName() << '\n';
        }
    }

    int getSetSize(){
        return _sets.size();
    }
    
    FC_Set* getCurrentSet(){
        return _currentSet;
    }

public: // Setters
    void setFolderName(std::string name){
        _folderName = name;
    }

public:
    void createSet(std::string str){
        _sets.push_back(new FC_Set(str));
    }

private: // Variables
    std::vector<FC_Set*> _sets;
    FC_Set* _currentSet;
    std::string _folderName;
};

#endif // FC_Folder_H