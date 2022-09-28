#ifndef FC_SET_H
#define FC_SET_H

#include"Flashcard.h"

class FC_Set{
public: // Constructors
    FC_Set(){
        
    }

private:
    std::vector<Flashcard*> _flashcards;
    std::string _name;
};


#endif // FC_SET_H