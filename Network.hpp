/**
 * 
 * @file: Network.hpp
 * @purpose: A design template class that has all the private data members like temp_items that are all {T} items which in this project will
 *           be the different Accounts. As well as the static const capacity that wont change throughout implementation or design. The item_count
 *           is also a private members which is either added if an account is added to the network, or subtracted if an account is removed. 
 *           this is our way of keeping track of how many items are in the Account.
 */
#ifndef NETWORK_H
#define NETWORK_H
#include "Post.hpp"
#include "LinkedList.hpp"
#include "Account.hpp"
#include <iostream>
#include <vector>
#include<string>
using namespace std;

template <class T>
class Network{
    private:
        static const int DEFAULT_CAPACITY = 200; //default capacity of how many items can be in a network
        const T* temp_items[DEFAULT_CAPACITY]; // temp_items being the amount of accounts in the network. Which are all pointers to the Accounts
        int item_count; //keep count of the amount of items being removed or added to the network
        LinkedList<Post*> feed; // a LinkedList called feed that will store pointers to Post, which will be how we will keep track of the post in the accounts. 
        int getIndexOf(const T* _username); // private method that gets the index of where in the temp_items the _username is found if it is there.
    public:
        void printVector(const T& vec);
        /**
         * @post: default constructor
         */
        Network();
        /**
         * @return: the size of Network
         */
        int getSizeOfNetwork() const; // works
        /**
         * @return: returns true if network is empty
         */
        bool isEmpty() const; // works
        /**
         * @return: returns true if item was able to be added
         */
        bool addAccount(const T* item_being_added); //works
        /**
         * @param: const pointer to the item being removed
         * @return: returns true if it was able to remove Account
         */
        bool removeAccount(const T* item_being_removed); //works
        /**
         * @post: clears the size of the network 
         * 
         */
        void clear();// works
        /**
         * @param: const pointer of item to check if the network contains that item
         * @return: returns true if the network contains the item
         */
        bool containsAccount(const T* contains_item); // works
        /**
         * @param: the name of the file
         * @post:  will go through the file, find the username and password, and then create Accounts using the usernames and passwords found.
         */
        void populateNetwork(const string fileName);
        /**
         * @param: const reference of another network
         * @return: the {this} network that doesnt have the items another_net has
         */
        Network<T>& operator -=(const Network<T>& another_net);
        /**
         * @param: const reference of account being displayed
         * @post: prints out the feed of the accounts
         */
        void printFeedForAccount( T& account_being_displayed);
        /**
         * @param: const reference of an Account and the username that the Account would like to follow
         * @return: true if the Account was able to follow said username
         */
        bool authenticateFollow (T& _account, const string username);
        /**
         * @param: reference to the Post being added to the feed
         * @return: returns true if it was able to addToFeed
         * 
         */
        bool addToFeed (Post* post_added_to_feed);

        int removeIfContains(const string& phrase_sensitive);

        LinkedList<Post*> getFeed();
        void setFeed(LinkedList<Post*> list);
};
//since its a template, the Network cpp is included at the bottom
#include "Network.cpp"
#endif
