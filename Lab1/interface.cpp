#include "interface.h"

void Interface::call_interface(){

    Constructor constructor;
    Reader reader;
    constructor.input();
    bool power_on = true;
    bool enter = false;
    int option = 0;
    char cmd = 'U';

    while (power_on){
        constructor.output();
        constructor.length();
        std::cout << std::endl;
        switch (option){
            case 0:
                std::cout << "Press down arrow to move down" << std::endl;
                std::cout << "Press up arrow to move up" << std::endl;
                std::cout << "Press enter to select option" << std::endl << std::endl;
                std::cout << "1.Insert Element<--" << std::endl;
                std::cout << "2.Remove element" << std::endl;
                std::cout << "3.Insert several random elements" << std::endl;
                std::cout << "4.Remove several elements" << std::endl;
                std::cout << "5.Remove list" << std::endl;
                std::cout << "6.Reverse list" << std::endl;
                std::cout << "7.Sort list" << std::endl;
                std::cout << "8.Exit" << std::endl;
                break;
            case 1:
                std::cout << "Press down arrow to move down" << std::endl;
                std::cout << "Press up arrow to move up" << std::endl;
                std::cout << "Press enter to select option" << std::endl << std::endl;
                std::cout << "1.Insert Element" << std::endl;
                std::cout << "2.Remove element<--" << std::endl;
                std::cout << "3.Insert several random elements" << std::endl;
                std::cout << "4.Remove several elements" << std::endl;
                std::cout << "5.Remove list" << std::endl;
                std::cout << "6.Reverse list" << std::endl;
                std::cout << "7.Sort list" << std::endl;
                std::cout << "8.Exit" << std::endl;
                break;
            case 2:
                std::cout << "Press down arrow to move down" << std::endl;
                std::cout << "Press up arrow to move up" << std::endl;
                std::cout << "Press enter to select option" << std::endl << std::endl;
                std::cout << "1.Insert Element" << std::endl;
                std::cout << "2.Remove element" << std::endl;
                std::cout << "3.Insert several random elements<--" << std::endl;
                std::cout << "4.Remove several elements" << std::endl;
                std::cout << "5.Remove list" << std::endl;
                std::cout << "6.Reverse list" << std::endl;
                std::cout << "7.Sort list" << std::endl;
                std::cout << "8.Exit" << std::endl;
                break;
            case 3:
                std::cout << "Press down arrow to move down" << std::endl;
                std::cout << "Press up arrow to move up" << std::endl;
                std::cout << "Press enter to select option" << std::endl << std::endl;
                std::cout << "1.Insert Element" << std::endl;
                std::cout << "2.Remove element" << std::endl;
                std::cout << "3.Insert several random elements" << std::endl;
                std::cout << "4.Remove several elements<--" << std::endl;
                std::cout << "5.Remove list" << std::endl;
                std::cout << "6.Reverse list" << std::endl;
                std::cout << "7.Sort list" << std::endl;
                std::cout << "8.Exit" << std::endl;
                break;
            case 4:
                std::cout << "Press down arrow to move down" << std::endl;
                std::cout << "Press up arrow to move up" << std::endl;
                std::cout << "Press enter to select option" << std::endl << std::endl;
                std::cout << "1.Insert Element" << std::endl;
                std::cout << "2.Remove element" << std::endl;
                std::cout << "3.Insert several random elements" << std::endl;
                std::cout << "4.Remove several elements" << std::endl;
                std::cout << "5.Remove list<--" << std::endl;
                std::cout << "6.Reverse list" << std::endl;
                std::cout << "7.Sort list" << std::endl;
                std::cout << "8.Exit" << std::endl;
                break;
            case 5:
                std::cout << "Press down arrow to move down" << std::endl;
                std::cout << "Press up arrow to move up" << std::endl;
                std::cout << "Press enter to select option" << std::endl << std::endl;
                std::cout << "1.Insert Element" << std::endl;
                std::cout << "2.Remove element" << std::endl;
                std::cout << "3.Insert several random elements" << std::endl;
                std::cout << "4.Remove several elements" << std::endl;
                std::cout << "5.Remove list" << std::endl;
                std::cout << "6.Reverse list<--" << std::endl;
                std::cout << "7.Sort list" << std::endl;
                std::cout << "8.Exit" << std::endl;
                break;
            case 6:
                std::cout << "Press down arrow to move down" << std::endl;
                std::cout << "Press up arrow to move up" << std::endl;
                std::cout << "Press enter to select option" << std::endl << std::endl;
                std::cout << "1.Insert Element" << std::endl;
                std::cout << "2.Remove element" << std::endl;
                std::cout << "3.Insert several random elements" << std::endl;
                std::cout << "4.Remove several elements" << std::endl;
                std::cout << "5.Remove list" << std::endl;
                std::cout << "6.Reverse list" << std::endl;
                std::cout << "7.Sort list<--" << std::endl;
                std::cout << "8.Exit" << std::endl;
                break;
            case 7:
                std::cout << "Press down arrow to move down" << std::endl;
                std::cout << "Press up arrow to move up" << std::endl;
                std::cout << "Press enter to select option" << std::endl << std::endl;
                std::cout << "1.Insert Element" << std::endl;
                std::cout << "2.Remove element" << std::endl;
                std::cout << "3.Insert several random elements" << std::endl;
                std::cout << "4.Remove several elements" << std::endl;
                std::cout << "5.Remove list" << std::endl;
                std::cout << "6.Reverse list" << std::endl;
                std::cout << "7.Sort list" << std::endl;
                std::cout << "8.Exit<--" << std::endl;
                break;
        }
        cmd = reader.scan_key();
        switch(cmd){
            case 'D':
                system("cls");
                option++;
                break;
            case 'U':
                system("cls");
                option--;
                break;
            case 'E':
                system("cls");
                enter = true;
                break;
            default:
                system("cls");
                break;
        }
        if(option > 7) option = 0;
        if(option < 0) option = 7;
        if(enter && option == 0){
            system("cls");
            enter = false;
            constructor.insert_element();
        }
        if(enter && option == 1){
            constructor.output();
            system("cls");
            enter = false;
            constructor.remove_element();
        }
        if(enter && option == 2){
            system("cls");
            enter = false;
            constructor.partial_insert();
        }
        if(enter && option == 3){
            system("cls");
            enter = false;
            constructor.partial_removal();
        }
        if(enter && option == 4){
            system("cls");
            enter = false;
            constructor.list_removal();
        }
        if(enter && option == 5){
            system("cls");
            enter = false;
            constructor.list_reversing();
        }
        if(enter && option == 6){
            system("cls");
            enter = false;
            constructor.list_sorting();
        }
        if(enter && option == 7){
            system("cls");
            enter = false;
            power_on = false;
        }
    }

}