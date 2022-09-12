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

public:
    void setFront(std::string data){
        _fData = data;
    }
    void setBack(std::string data){
        _bData = data;
    }

    std::string getFront(){
        return _fData;
    }
    std::string getBack(){
        return _bData;
    }

};

#endif // FLASHCARD_H