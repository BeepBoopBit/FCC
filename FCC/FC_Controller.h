#ifndef FC_CONTROLLER_H
#define FC_CONTROLLER_H

#include "FC_Folder.h"

class FC_Controller{
private:
    static FC_Controller *my_instance;
    FC_Controller(){

    }
public: // Singleton
    static FC_Controller *get_instance(){
        if(!my_instance){
            my_instance = new FC_Controller();
        }
        return my_instance;
    }
public: // Factories
    void createFlashcard(std::string front, std::string back){
        _flashcardBuffer.push_back(new Flashcard(front, back));
    }


private:
    std::vector<Flashcard*> _flashcardBuffer;
};


#endif // FC_CONTROLLER_H