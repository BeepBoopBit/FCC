#ifndef FC_SET_H
#define FC_SET_H

#include"Flashcard.h"

class FC_Set{
private:
    std::vector<Flashcard*> _flashcards;

public:
    void addFlashcard(Flashcard *fc){
        _flashcards.push_back(fc);
    }

    std::vector<Flashcard*> getFlashcards(){
        return _flashcards;
    }

};


#endif // FC_SET_H