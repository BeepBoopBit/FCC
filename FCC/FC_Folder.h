#ifndef FC_Folder_H
#define FC_Folder_H

#include "FC_Set.h"

class FC_Folder{
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

    void useSet(int setIndex){
        currSet = setIndex;
    }

    int findGetSet(std::string name){
        for(int i = 0; i < _sets.size(); ++i){
            if(_sets[i]->getName() == name){
                useSet(i);
                return i;
            }
        }
        std::cout << "No Set Found\n";
        return -1;
    }

    FC_Set* getSet(int index){
        return _sets[index];
    }
private:
    std::vector<FC_Set*> _sets;
    std::string _name;
    int currSet;
};

#endif // FC_Folder_H