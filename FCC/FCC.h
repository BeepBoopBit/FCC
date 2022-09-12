#ifndef FCC_H
#define FCC_H

#include "Flashcard.h"

class MyFCC{
private:
    std::vector<Flashcard> _fFront, _fBack;
    bool isFront = true;
public:
    MyFCC(){

    }

public:
    void InitMenu(){

    }


private:
    void createFlashcard(std::string fData, std::string bData){

    }
    void checkAnswer(Flashcard fc, std::string data){
        
    }

};

#endif // FCC_H