#ifndef FLASHCARD_H
#define FLASHCARD_H

#include "../includes.h"

class Flashcard{
private:
    std::string _fData, _bData; // Front and Back
    bool _isFrontView = true;

public:
    Flashcard(){

    }
    Flashcard(std::string frontData, std::string backData){

    }
    Flashcard(std::string frontData, std::string backData, bool view){

    }

};

#endif // FLASHCARD_H