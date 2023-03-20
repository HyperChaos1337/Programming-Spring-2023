#include "list.h"

List::List(){
    this->prev = this->cur = nullptr;
}
//Additional Funcs

Node* List::get_root(){
    Node* node = cur;
    if(node != nullptr) return node;
    else return nullptr;
}

void List::is_empty(){
    Node* node = cur;
    if(node == nullptr) std::cout << "List is empty" << std::endl;
    else std::cout << "Total elements: " << list_length() << std::endl;
}

unsigned List::list_length(){
    unsigned length = 0;
    for(Node* node = cur; node != nullptr; node = node->next){
        length++;
    }
    return length;
}

void List::print(){
    for(Node* node = cur; node != nullptr; node = node->next){
        std::cout << node->element << "->";
    }
    std::cout << std::endl;
}

Node* List::get_cur_element(int index){

    if (index < 0) return nullptr;
    Node* node = cur;
    int k = 0;
    while(node && index != k && node->next){
        node = node->next;
        k++;
    }
    return index == k ? node : nullptr;

}

//Func 1
void List::push_back(long long int element){
    Node* node = new Node(element);
    if (cur == nullptr) cur = node;
    if (prev != nullptr) prev->next = node;
    prev = node;
}
void List::push_front(long long int element){
    Node* node = new Node(element);
    node->next = cur;
    cur = node;
    if(prev == nullptr) prev = node;
}


//Func 2
void List::insert(int index, long long int element){
    if(index == -1){
        push_front(element);
        std::cout << "Element inserted: " << element << std::endl;
        return;
    }
    if(index == list_length() - 1){
        push_back(element);
        std::cout << "Element inserted: " << element << std::endl;
        return;
    }
    if(index > list_length() - 1 || index < -1){
        std::cout << "Index is out of range. Insertion cancelled" << std::endl;
        return;
    }
    Node* left_element = get_cur_element(index);
    if(left_element == nullptr) return;
    Node* right_element = left_element->next;
    Node* node = new Node(element);
    left_element->next = node;
    node->next = right_element;
    if (right_element == nullptr) cur = node;
}

//Func 3
void List::pop_front(){
    if (cur == nullptr) return;
    if (cur == prev){
        delete prev;
        cur = prev = nullptr;
        return;
    }
    Node* node = cur;
    cur = node->next;
    delete node;
}
void List::pop_back(){

    if(prev == nullptr) return;
    if(cur == prev){
        delete prev;
        cur = prev = nullptr;
        return;
    }
    Node *node = cur;
    for(; node->next != prev; node = node->next);
        node->next = nullptr;
        delete prev;
        prev = node;

}
void List::remove(int index, unsigned length){

    if(list_length() == 0){
        std::cout << "List is empty. There's nothing to remove" << std::endl;
        return;
    }
    if (index < 0 || index > list_length()-1){
        std::cout << "Index is out of bounds. Try again!" << std::endl;
        return;
    }
    if (index == 0){
        std::cout << "Root element removed" << std::endl;
        pop_front();
        return;
    }

    Node* left_element = get_cur_element(index-1);
    Node* node = left_element->next;
    if(node == nullptr) return;
    Node* right_element = node->next;
    left_element->next = right_element;
    if(node == cur) cur = left_element;
    delete node;
    std::cout << "Element on position " << index << " has been removed" << std::endl;
}

//Func 4
void List::erase(unsigned length){
    if(list_length() == 0){
        std::cout << "List is empty!" << std::endl;
        return;
    }
    for(int i = 0; i < length; i++){
        pop_front();
    }
    std::cout << "List has been erased!" << std::endl;
}

//Func 5
void List::add_elements(int start, int amount){
    if(start > list_length()-1 && start < -1){
        std::cout << "Start position is out of range. Insertion cancelled" << std::endl;
        return;
    }
    for(int i = start; i < start + amount; i++){
        long long int element = rand()%100 + 1;
        insert(i, element);
    }
}
//Func 6
void List::delete_elements(int start, int amount){
    if(list_length() - start < amount){
        std::cout << "Warning! Trying to get out of range. Removal cancelled" << std::endl;
        return;
    }
    if(start <= -1 || start >= list_length()){
        std::cout << "Index is out of bounds. Removal cancelled" << std::endl;
        return;
    }
    if(list_length() == 0){
        return;
    }
    for(int i = start; i < start + amount; i++) remove(start, list_length());
}
//Func 7
void List::reverse(){
    if (list_length() == 0) {
        std::cout << "List is empty. There's nothing to reverse" << std::endl;
        return;
    }
    Node* tmp = nullptr;
    Node* previous = nullptr;
    Node* current = cur;
    while (current != nullptr){
        tmp = current->next;
        current->next = previous;
        previous = current;
        current = tmp;
    }
    cur = previous;
    std::cout << "List has been reversed" << std::endl;
}
//Func 8
void List::sort(){
    if (list_length() == 0) {
        std::cout << "List is empty. There's nothing to sort" << std::endl;
        return;
    }
    if(!cur) return;
    Node *tmp1 = cur;
    Node *tmp2 = cur;
    while (tmp2){
        while (tmp1->next){
            if(tmp1->element > tmp1->next->element){
                long long int tmp_value = tmp1->element;
                tmp1->element = tmp1->next->element;
                tmp1->next->element = tmp_value;
            }
            tmp1 = tmp1->next;
        }
        tmp1 = cur;
        tmp2 = tmp2->next;
    }
    std::cout << "List has been sorted" << std::endl;
}