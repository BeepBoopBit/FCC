#ifndef FC_CONTROLLER_H
#define FC_CONTROLLER_H

#include "Flashcard.h"

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

private:

};


#endif // FC_CONTROLLER_H