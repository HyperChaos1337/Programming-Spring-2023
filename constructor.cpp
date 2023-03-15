#include "constructor.h"

void Constructor::output(){
    std::cout << "List: ";
    list.print();
}

void Constructor::length(){
    std::cout << "Length: " << list.list_length() << std::endl;
}

void Constructor::input(){
    std::cout << "Enter list size (size <= 20):" << " "; std::cin >> size;
    while(std::cin.fail() || size < 0 || size > MAX_SIZE){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again" << std::endl;
        std::cout << "Enter list size (size <= 20):" << " "; std::cin >> size;
    }
    if(!std::cin.fail() && size > 0 && size <= MAX_SIZE) std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Input list elements. Extra data will be removed" << std::endl;
    while (size){
        long long int num;
        std::cin >> num;
        while(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again" << std::endl;
            std::cout << "Input list elements. Extra data will be removed" << std::endl; std::cin >> num;
        }
        if(!std::cin.fail()) list.push_back(num);
        size--;
    }
    if(!std::cin.fail()) std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Constructor::insert_element(){

    int index;
    long long int element;
    std::cout << "Enter index. To insert in the front of list, use -1:" << " "; std::cin >> index;
    while(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again" << std::endl;
        std::cout << "Enter index. To insert in the front of list, use -1:" << " "; std::cin >> index;
    }
    if(!std::cin.fail()) std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter element:" << " "; std::cin >> element;
    while(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again" << std::endl;
        std::cout << "Enter element:" << " "; std::cin >> element;
    }
    if(!std::cin.fail()) std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    list.insert(index, element);
}

void Constructor::remove_element(){
    int index;
    std::cout << "Enter index:" << " "; std::cin >> index;
    while(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again" << std::endl;
        std::cout << "Enter index:" << " "; std::cin >> index;
    }
    if(!std::cin.fail()) std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    list.remove(index,size);
}

void Constructor::list_removal(){
    list.erase(list.list_length());
}

void Constructor::partial_insert(){
    int start, amount;
    std::cout << "Enter start position. To insert in the front of list, use -1:" << " "; std::cin >> start;
    while(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again" << std::endl;
        std::cout << "Enter start position. To insert in the front of list, use -1:" << " "; std::cin >> start;
    }
    if(!std::cin.fail()) std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter amount of elements:" << " "; std::cin >> amount;
    while(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again" << std::endl;
        std::cout << "Enter amount of elements:" << " "; std::cin >> amount;
    }
    if(!std::cin.fail()) std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    list.add_elements(start, amount);
}

void Constructor::partial_removal(){
    int start, amount;
    std::cout << "Enter start position:" << " "; std::cin >> start;
    while(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again" << std::endl;
        std::cout << "Enter start position:" << " "; std::cin >> start;
    }
    if(!std::cin.fail()) std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter amount of elements to remove:" << " "; std::cin >> amount;
    while(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again" << std::endl;
        std::cout << "Enter amount of elements to remove:" << " "; std::cin >> amount;
    }
    if(!std::cin.fail()) std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    list.delete_elements(start, amount);
}

void Constructor::list_reversing(){
    list.reverse();
}

void Constructor::list_sorting(){
    list.sort();
}