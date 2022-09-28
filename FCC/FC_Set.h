#ifndef FC_SET_H
#define FC_SET_H

#include"Flashcard.h"

class FC_Set{
public: // Constructors
    FC_Set(){
        
    }

public: // setters
    void addFlashcard(Flashcard* ff){
        _flashcards.push_back(ff);
    }
    void removeFlashcard(int index){
        // deallocate the memory
        delete _flashcards[index];

        // delete it in the vector (expensive)
        _flashcards.erase(_flashcards.begin() + index, _flashcards.begin()+index+1);
    }

private:
    std::vector<Flashcard*> _flashcards;
    std::string _name;
};


#endif // FC_SET_H