#include "LinkedList.hpp"
#include <iostream>

template<typename T>
LinkedList<T>::LinkedList() : head_{nullptr}, size_{0} {}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) : head_{nullptr}, size_{0} {
    if (!list.isEmpty()) {
        Node<T> *copyHead = list.getHeadPtr();
        int counter = 0;

        while (counter < list.getSize()) {
            insert(copyHead->getItem(), counter);
            counter++;
            copyHead = copyHead->getNext();
        }
    }
}

template<typename T>
Node<T>* LinkedList<T>::getHeadPtr() const {
    return head_;
}


template<typename T>
void LinkedList<T>::clear() {
    Node<T>* curr_item = head_;
    Node<T>* temp = curr_item;
    for(int i = 0; i<size_; i++) {
        temp = curr_item;
        curr_item = curr_item->getNext();
        delete temp;
    }
    temp = nullptr;
    size_ = 0;
}



template<typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template<typename T>
bool LinkedList<T>::insert(const T& item, const int &position){
    if((position < 0 || position > size_)){
        return false;
    }

    Node<T> *node = new Node<T>();
    node->setItem(item);

    if(size_ == 0){
        head_ = node;
    }
    else {
        Node<T> *iterator;

        if(position == 0){
            node->setNext(head_);
            head_ = node;
        }

        else if (position == size_){
            iterator = getAtPos(size_-1);
            iterator->setNext(node);
        }
        else {
            iterator = getAtPos(position-1);
            node->setNext(iterator->getNext());
            iterator->setNext(node);
        }
    }
    size_++;
    return true;
}

template <typename T>
bool LinkedList<T>::remove(const int&position) {
    if (position < 0 || position >= size_) {
        return false;
    }

    Node<T> *iterator;

    if (position == 0){
        iterator = head_;
        head_ = head_->getNext();
    }
    else {
        iterator = getAtPos(position-1);
        iterator->setNext(iterator->getNext()->getNext());
        iterator = iterator->getNext();
    }

    size_--;
    return true;

}

template <typename T>
void LinkedList<T>::reverseCopy(const LinkedList &a_list) {
    LinkedList<T> newList(a_list);

    Node<T> *current = newList.getHeadPtr();
    const int START = 0;
    const int END = newList.getSize();

    while (current != nullptr){
        insert(current->getItem(), START);
        current = current->getNext();
        remove(END);
    }
}

template<typename T>
int LinkedList<T>::getIndexOf(const T &item) const {
    Node<T>* curr_item = head_;
    int counter = 0;
    while(curr_item != nullptr) {
        if(curr_item->getItem() == item) {
            return counter;
        }
        counter++;
        curr_item = curr_item->getNext();
    }
    return -1;
}

template<typename T>
Node<T>* LinkedList<T>::getAtPos(const int &pos) const {

    if(pos < 0 || pos >= size_) {
        return nullptr;
    }

    Node<T>* curr_item = head_;
    int counter = 0;
    while(counter < pos && curr_item != nullptr) {
        counter++;
        curr_item = curr_item->getNext();
    }
    return curr_item;
}

template<typename T>
int LinkedList<T>::getSize() const {
    return size_;
}

template<typename T>
bool LinkedList<T>::isEmpty() const {
    return size_ == 0 ? true : false;
}

template <typename T>
bool LinkedList<T>::moveItem(int &current_position, int &new_position) {
    if(
        (current_position > -1 && current_position < size_) &&
        (new_position > -1 && new_position < size_)
    ) {
        if(new_position != current_position) {
            if(new_position < current_position) {
                T temp = this->getAtPos(current_position)->getItem();
                this->getAtPos(current_position)->setItem(this->getAtPos(current_position - 1)->getItem());
                this->getAtPos(current_position - 1)->setItem(temp);
                current_position--;
            }
            else {
                T temp = this->getAtPos(current_position)->getItem();
                this->getAtPos(current_position)->setItem(this->getAtPos(current_position + 1)->getItem());
                this->getAtPos(current_position + 1)->setItem(temp);
                current_position++;
            }

            return moveItem(current_position, new_position);
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}




template<typename T>
bool LinkedList<T>::moveItemToTop(const T& item){
    if (getIndexOf(item) < 1) return false; //If the item does not exist or it is already on top, return false
    else
    {
        Node<T>* new_head = new Node<T>(); //Create a new head Node
        new_head->setItem(item); //Set the value of the new head Node to the item you want to move
        remove(getIndexOf(item)); //Remove the item you want to move from the List
        new_head->setNext(head_); //Set the new head pointer's next value to the current head pointer
        head_ = new_head; //Set the List's head to the new head pointer
        return true;
    }
}
template<class T>
void LinkedList<T>::displayList(){
    while (head_ != nullptr){
        std::cout << head_->getItem() << "-> ";
        head_ = head_->getNext();
    }
    std::cout << endl;
}