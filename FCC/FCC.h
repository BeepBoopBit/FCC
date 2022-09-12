#ifndef FCC_H
#define FCC_H

#include "Flashcard.h"

class MyFCC{
private:
    std::vector<Flashcard*> _flashcards;
    bool isFront = true;
public:
    MyFCC(){

    }

public:
    void InitMenu(){

    }


private:
    void createFlashcard(std::string fData, std::string bData){
        _flashcards.push_back(new Flashcard(fData,bData));
    }
    void checkAnswer(Flashcard fc, std::string data){
    }

};

#endif // FCC_H