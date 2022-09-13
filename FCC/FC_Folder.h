#ifndef FC_Folder_H
#define FC_Folder_H

#include "FC_Set.h"

class FC_Folder{
private:
    std::vector<FC_Set*> _sets;
public:
    void addSet(FC_Set *set){
        _sets.push_back(set);
    }
    std::vector<FC_Set*> getSet(){
        return _sets;
    }
};

#endif // FC_Folder_H