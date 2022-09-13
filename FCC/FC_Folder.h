#ifndef FC_Folder_H
#define FC_Folder_H

#include "FC_Set.h"

class FC_Folder{
private:
    std::vector<FC_Set*> _sets;
    std::string _name;
public:
    void addSet(FC_Set *set){
        _sets.push_back(set);
    }
    std::vector<FC_Set*> getSet(){
        return _sets;
    }
    std::string getName(){
        return _name;
    }
    void setName(std::string name){
        _name = name;
    }
};

#endif // FC_Folder_H