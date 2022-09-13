#ifndef FC_SET_H
#define FC_SET_H

#include"Flashcard.h"

class FC_Set{
private:
    std::vector<Flashcard*> _flashcards;
    std::string _name;
public:
    FC_Set(){

    }
    FC_Set(std::string name){
        _name = name;
    }
public:
    void addFlashcard(Flashcard *fc){
        _flashcards.push_back(fc);
    }

    std::vector<Flashcard*> getFlashcards(){
        return _flashcards;
    }
    void setName(std::string name){
        _name = name;
    }
    std::string getName(){
        return _name;
    }

};


#endif // FC_SET_H