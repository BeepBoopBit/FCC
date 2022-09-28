#ifndef FC_Folder_H
#define FC_Folder_H

#include "FC_Set.h"

class FC_Folder{
public: // Constructors
    FC_Folder(){

    }

private: // Variables
    std::vector<FC_Set*> _sets;
};

#endif // FC_Folder_H