/**
 * @author: Dariel A. Martinez
 * @date: 23 September 2022
 * General.cpp 
 * Project 2: Using enums, inheritance, and regex to make polls. As well as using regex to authenticate a website
 */

#include <iostream>
#include <vector>
#include "General.hpp"
using namespace std;
/**
 * @param: A reaction refereence that refers to the reactions enum created in the .hpp files
 * @return: true if the reaction is in the enum, false other wise
 */
bool General::reactToPost(const Reactions& reaction){
    if (reaction >= 0 && reaction <6) react[reaction]++;
    return true;
}
/**
 * @post: Prints out the amount reaction each reaction has, ex Like: 1 (1 like)
 */
void General::getReactions()const{
    cout << "Like : " << react[0] << " | " << "Dislike : " << react[1] << " | " << "Laugh : " << react[2] << " | " << "Wow : " << react[3] << " | " << "Sad : " << react[4] << " | " << "Angry : " << react[5];
}
/**
 * @post: diplays the title, the body, the time the post was created, and as well as the reaction 
 * 
 */
void General::displayPost(){
    string x = getTitle();
    string z = getBody();

    cout << "\n" << x << " at ";
    getTimeStamp();
    cout << ":\n" << z << "\n";
    getReactions();
    cout << "\n";
}