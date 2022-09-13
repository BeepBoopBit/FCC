#ifndef FC_CONTROLLER_H
#define FC_CONTROLLER_H

#include "FC_Folder.h"
#include <map>

class FC_Controller{
private:
    FC_Controller *my_instance = nullptr;
    FC_Controller(){

    }

    FC_Controller(Flashcard *fc){

    }
public:
    FC_Controller *get_instance(Flashcard *fc){
        if(my_instance != nullptr){
            my_instance = new FC_Controller();
        }
        return my_instance;
    }

    FC_Controller *get_instance(){
        if(my_instance != nullptr){
            my_instance = new FC_Controller();
        }
        return my_instance;
    }

public:

    void useFolder(std::string name){
        if(isFolderExists(name)){
            currFolderName = name;
        }else{
            std::cout << "Folder doesn't exists";
        }

    }

    void addFolder(std::string name){
        if(isFolderExists(name)){
            _folders[name] = new FC_Folder();
            _folders[name]->setName(name);
        }else{
            std::cout << "Folder Exists";
        }
    }

    void addSet(std::string setName){
        _folders[currFolderName]->addSet(new FC_Set(setName));
    }

private:
    bool isFolderExists(std::string name){
        return _folders.find(name) != _folders.end();
    }
private:
    // <NameOfFolder, TheData>
    std::map<std::string, FC_Folder*> _folders;

    std::string currFolderName;
};


#endif // FC_CONTROLLER_H