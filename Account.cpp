
/**
 * @author: Dariel A. Martinez
 * @date:  4 November 2022
 * @post: 
 * @file: Account.cpp
 */
#include "Account.hpp"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


/**
 * @return: A getter that returns the username of the account created. (As string)
 */
string Account::getUsername()const {
    return username;
}

/**
 * @return: A getter that returns the password of the account created. (As string)
 */
string Account::getPassword()const{
    return password;
}
/**
 * @return: returns the current network the Account is in
 */
Network<Account>* Account::getNetwork(){
    return account_in_network;
}
/**
 * @param: sets the current Account to a the network {net_ptr} is pointing to 
 */
void Account::setNetwork(Network<Account>* net_ptr){
    account_in_network = net_ptr;
}

/**
 * @param: the string named _username that the user wants to set the username as.
 */
void Account::setUsername(const string& _username){
    username = _username;
}
/**
 * @param: the string named _password that the user wants to set the password as.
 */

void Account::setPassword(const string& _password){
    password = _password;
}

void Account::getTimeStamp() const{
    cout << asctime(localtime(&current_time));
}

/**
 * @param: A Post Pointer that refers to a Post of type General, Promotional, or Poll
 * @return: It will return true if it was able to insert the Post Pointer into the LinkedList, it will return false if either the title or the 
 *          body is empty. 
 * @note: This will also insert that same Post pointer into the feed of the Network.
 */

bool Account::addPost(const Post* post) {
    Post* post1 = const_cast<Post *>(post);
    if (post1->getTitle() == "" || post1->getBody() == "") return false;
    else{
        all_posts.insert(post1,0);
        account_in_network->addToFeed(post1);
        return true;
    }
}


/**
 * @note: This method gets the head pointer of the LinkedList, and then iterates through the List and get the Item(Post of either children classes),
 *        and then use the Polymorphised displayPost method which will print out their respective displayPost function. 
 */

void Account::viewPosts() const {
    Node<Post*>* iterator;
    iterator = all_posts.getHeadPtr();
    while (iterator != nullptr){
        Post* ptr = iterator->getItem();
        ptr->displayPost();
        iterator = iterator->getNext();
    }

}
/**
 * 
 */
bool Account::followAccount(const string& username_to_follow){
    unsigned int vecSize = usernames_of_following.size();
    bool already_following = false;
    for (unsigned int i = 0; i < vecSize;i++){
        if (usernames_of_following[i] == username_to_follow) already_following = true;
    }
    if (already_following == false && account_in_network != nullptr) {
        usernames_of_following.push_back(username_to_follow);
    }
    return false;
}

/**
 * @return:
 */
vector<string> Account::viewFollowing() const{
    cout << usernames_of_following.size() << endl;
    return usernames_of_following;
}


/**
 * 
 * @param: Post pointer
 * @param: the new string title
 * @param: the new string body
 * @post: Creates a new post pointer that will set the title and body to the new_title and new_body strings. And that post pointer will have a new
 *        body and new title. We will also iterate through the post LinkedList and if we find the post pointer in the list, we will remove it and 
 *        then add the new pointer which will be at the beginning of the list. 
 */
void Account::updatePost(const Post* post_ptr,const string& new_title,const  string& new_body){
    // LinkedList<Post*> feed_ = account_in_network->getFeed();
    Post* new_ptr = const_cast<Post *>(post_ptr);
    new_ptr->setTitle(new_title);
    new_ptr->setBody(new_body);
    Node<Post*>* iterator;
    // Node<Post*>* feed_iterator = feed_.getHeadPtr();
    iterator = all_posts.getHeadPtr();
    while (iterator != nullptr){
        if (iterator->getItem() == post_ptr){
            all_posts.remove(all_posts.getIndexOf(iterator->getItem()));
            all_posts.insert(new_ptr,0);
        }
        iterator = iterator->getNext();
    }
    // while (feed_iterator != nullptr){
    //     if (feed_iterator->getItem() == post_ptr){
    //         feed_.remove(feed_.getIndexOf(feed_iterator->getItem()));
    //         feed_.insert(new_ptr,0);
    //     }
    //     feed_iterator = feed_iterator->getNext();
    // }
}   

/**
 * 
 * @param: A Post pointer
 * @return: This will remove the Post from the Account LinkedList as well as the LinkedList in the network.
 * @note: We will get the list from the Network pointer, remove the Post from the List, then set the feed to the feed_ which doesnt contain
 *        the Post pointer in the parameter. 
 */
bool Account::removePost(Post* post_ptr){
    all_posts.remove(all_posts.getIndexOf(post_ptr));
    // LinkedList<Post*> feed_ = account_in_network->getFeed();
    // feed_.remove(feed_.getIndexOf(post_ptr));
    // account_in_network->setFeed(feed_);
    return true;
}