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

public: // Initial Functions
    void start(){
        bool inGame = true;
        while(inGame){
            // Display the menu
            std::cout << "BeepBoop Cards\n"
                    << "[1] Show Folders\n"
                    << "[2] Create Folder\n"
                    << "[3] Exit\n"
                    << "> ";

            // Get the Input
            std::string userInput;
            std::getline(std::cin, userInput);

            if(userInput == "1"){

            }else if(userInput == "2"){

            }else if(userInput == "3"){

            }
        }
        
    }

public: // Menu Choices
    void showFolders(){
        int size = _folders.size();
        for(int i = 0; i < size; ++i){
            std::cout << '[' << i << ']' << ' ' << _folders[i]->getFolderName() << '\n';
        }
    }

public: // Factories
    void createFlashcard(std::string front, std::string back){
        _flashcardBuffer.push_back(new Flashcard(front, back));
    }

private:
    std::vector<Flashcard*> _flashcardBuffer;
    std::vector<FC_Folder*> _folders;
};


#endif // FC_CONTROLLER_H