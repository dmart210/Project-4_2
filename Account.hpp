/**
 * @file: Account.hpp
 * @post: design of account with all the methods and private members. 
 * @post: we also define the all_posts LinkedList which will contain Post pointers that will contain the different Post in the Accounts. 
 */
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Network.hpp"
#include "Post.hpp"
#include "LinkedList.hpp"
#include "Node.hpp"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
class Account{
    private:
        string username; //username of account
        string password; //password of account
        LinkedList<Post*> all_posts; //A new LinkedList that will store Post pointers. 
        time_t current_time; // time_t object that gets the time
        Network<Account>* account_in_network;//pointer to the network
        vector<string> usernames_of_following; //vector of all usernames the Account follows
    public:
        /**
         * @post: default constructor that initializes all the private members and sets the time of when it got created, as well as setting new 
         *        private member [account_in_network] to nullptr.
         */
        Account(){
            username = "";
            password = "";
            time(&current_time);
            account_in_network = nullptr;
        }
        /**
         * @param: the username and password the user input
         * @note: Sets the username and password the user input as the actual username and password of the account. 
         *        Also "pushes back" a spot for the vector
         */
        Account(string _username, string _password){
            username = _username;
            password = _password;
            
        }
        /**
         * @return: return the username of Account
         */
        string getUsername()const;
        /**
         * @return: return password of the Account
         */
        string getPassword() const;
        /**
         * @return: the network the account is in 
         */
        Network<Account>* getNetwork();
        /**
         * @post: print the time the Account was created
         */
        void getTimeStamp() const;
        /**
         * @param: a const reference to the username that is going to be changed, with return by reference
         */
        void setUsername(const string& _username);
        /**
         * @param: a const reference to the password thats going to be changed, with return by reference
         */
        void setPassword(const string& _password);
        /**
         * @param: the network pointer, which will be the Network the account is in
         */
        void setNetwork(Network<Account>* network_ptr);
        /**
         * @param: two const reference which are the title and body of the post thats going to be created
         * @post: it will add the post to the all_posts vector, and as well add it to the network feed if the account is in the feed 
         */
        bool addPost(const Post* post); // didnt pass
        /**
         * @post: view all the posts in the Account
         */
        void viewPosts() const;
        /**
         * @param: the username that the account will follow
         * @return: it will return true if it was able to follow the account, false otherwise
         */
        bool followAccount(const string& username_to_follow); // didnt pass 
        /**
         * @return: the vector of all the following 
         */
        vector<string> viewFollowing() const;

        /**
         * @param: Post pointer
         * @param: the new string title
         * @param: the new string body
         */
        void updatePost(const Post* post_ptr, const string& new_title,const string& new_body);

        bool removePost(Post* post_ptr);
};
#endif
