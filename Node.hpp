/*
Node class interface for term projects
CSCI 235 Fall 2022
Hunter College
*/


#ifndef Node_
#define Node_

#include <iostream>

template<typename T>
class Node {

    public:
        /*
            Default Constructor
        */
        Node();

        /*
            Parametarized Constructor
            @param item - the item to be constructed
            @param next_node - the next node to point to
         */
        Node(const T& item, Node<T> *next_node = nullptr);

        /*
            Setter function for node item
            @param anItem - the item to be set in item_
        */
        void setItem(const T &anItem);

        /*
            Setter function for pointer to next node in chain
            @param nextNodePtr - the nextNodePtr to be set in next_
        */
        void setNext(Node<T> *nextNodePtr);

        /*
            @return returns the value for item_
        */
        T getItem() const;


        /*
            @return returns the value for next_
        */
        Node<T> *getNext() const;


    private:
        T item_;
        Node<T> *next_;
};

#include "Node.cpp"
#endif