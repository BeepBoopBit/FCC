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
                system("cls");
                showFolders();
            }else if(userInput == "2"){
                createFolder();
            }else if(userInput == "3"){
                inGame = false;
                break;
            }

            // I mean, I don't need to think about security... So I'll use it
            system("cls");
        }
        
    }

public: // Menu Choices
    void showFolders(){
        int size = _folders.size();
        std::cout << std::string(20,'=') << '\n';
        // Prints all the folder name
        for(int i = 0; i < size; ++i){
            std::cout << '[' << i << ']' << ' ' << _folders[i]->getFolderName() << '\n';
        }
        std::cout << std::string(20,'=') << '\n';
    }
    void createFolder(){
        bool isNotSatisfied = true;

        std::string userInput;
        while(isNotSatisfied){
            std::cout << "Enter the folder name: ";
            std::getline(std::cin, userInput);

            std::cout << "Are you satisfied with \"" << userInput << "\"?\n [YES or No] >";

            std::string userChoice;
            std::getline(std::cin, userChoice);
            if(transformToLower(userChoice) == "yes"){
                break;   
            }
        }
        _folders.push_back(new FC_Folder(userInput));
    }

public: // Factories
    void createFlashcard(std::string front, std::string back){
        _flashcardBuffer.push_back(new Flashcard(front, back));
    }

private: // Utility
    std::string transformToLower(std::string str){
        int size = str.length();
        for(int i = 0; i < size; ++i){
            str[i] = tolower(str[i]);
        }
        return str;
    }

private:
    std::vector<Flashcard*> _flashcardBuffer;
    std::vector<FC_Folder*> _folders;
};


#endif // FC_CONTROLLER_H