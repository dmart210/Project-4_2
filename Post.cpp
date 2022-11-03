//Post.cpp

#include "Post.hpp"
#include <iostream>
#include <cstring>
using namespace std;

/**
 * 
 * @note: Getter method that returns the body of the object being called
 * @returns: returns the Posts body
 */
string Post::getBody()const {
    return body;
}
/**
 * 
 * @note: Getter method that returns the title of the object being called
 * @returns: returns the Posts title
 */
string Post::getTitle()const{
    return title;
}
string Post::getUsername()const {
    return username;
}

/**
 * 
 * @note: Getter method that returns the time the post was created
 * @returns: returns the time the Post was created 
 */
void Post::getTimeStamp() const{
    char * time_pointer =asctime(localtime(&current_time)) ;
    string date_formated;
    //A for loop to go through the char pointer and to remove the \n that is attached to the asctime() function. The purpose to is make the date look more appealing
    for (int i = 0; i < strlen(time_pointer) -1; i++){
        date_formated+=*(time_pointer+i);
    }
    cout << date_formated;
}

/**
 * 
 * @param: the body the user inserted, is the methods parameter 
 * @return: the body the user inserted is then set as the Post, private, "body" which can only be accessed using the getBody method
 */
void Post::setBody(const string& _body){
    body = _body;
}
/**
 * 
 * @param: the title the user inserted, is the methods parameter 
 * @return: the title the user inserted is then set as the Post, private, "title" which can only be accessed using the getTtile method
 */
void Post::setTitle(const string& _title){
    title = _title;
}
void Post::setUsername(const string& _username){
    username = _username;
}

/**
 * @return: this returns a concatenated string which includes the title of the post,
 *          the time it was created(which was casted from integer to string), and the body of the post.  
 * 
 */

