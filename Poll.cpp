//Poll.cpp
#include <iostream>
#include "Poll.hpp"
#include <cstring>
using namespace std;
/**
 * @param: reference to an int num whic represents the vote for n poll
 * 
 */
bool Poll::votePoll(int& num){
    // if num is greater than the number of options return false

    // vote 1,2 or whatever number is in the string vector. if they vote 3 its not there return false. if it is there we go to that string 
    // vector, we get the amount of votes it has, and increment it. 
    if (num > poll_options.size() || num < 0) return false;
    else{
       number_of_votes_inside[num]++;
    }
    return true;
}
/**
 *@param: int reference that refers to the option getting changed
 * @param: int reference that refers to the poll option thats getting replaced or added
 */
void Poll::changePollOption(int& new_poll_option, int& replaced_or_added){
    if ((replaced_or_added + 1) > poll_options.size()){
        poll_options.push_back(to_string(replaced_or_added));
        number_of_votes_inside.push_back(1);
        number_of_votes_inside[new_poll_option]--;
    }
    else if(replaced_or_added <= poll_options.size()) {
        number_of_votes_inside[new_poll_option]--;
        number_of_votes_inside[replaced_or_added]++;
    }
}

/**
 * @post: return the options and the amount of votes it has in the format o votes in option_n where o is the amount of votes and n are the different options
 */
void Poll::getPollOptions()const{
    for(int i = 0; i < poll_options.size(); i++){
        cout << number_of_votes_inside[i] << " votes for: option_" << poll_options[i] << endl;
    }
}

/**
 * @param: the index of an option
 * @return: returns the amount of votes in the specified index
 */
int Poll::getPollVotes(int index_of_option)const{
    return number_of_votes_inside[index_of_option];
}

/**
 * 
 * @post: a method that prints out the body, title, and time of the post. As well as printing the options and how many votes it has
 */
void Poll::displayPost(){
    char * time_pointer =asctime(localtime(&current_time)) ;
    string date_formated;
    //A for loop to go through the char pointer and to remove the \n that is attached to the asctime() function. The purpose to is make the date look more appealing
    for (int i = 0; i < strlen(time_pointer) -1; i++){
        date_formated+=*(time_pointer+i);
    }
    string x = Post::getTitle();
    string y = Post::getBody();
    cout << "\n" << x << " at "<< date_formated << ":\n" << y << "\n";
    getPollOptions(); 
}