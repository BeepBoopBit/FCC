#ifndef FC_Folder_H
#define FC_Folder_H

#include "FC_Set.h"

class FC_Folder{
private:
    std::vector<FC_Set*> _sets;
public:
    std::vector<FC_Set*> getSet(){
        return _sets;
    }
    
};

#endif // FC_Folder_H