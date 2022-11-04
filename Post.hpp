//Post.hpp
#ifndef POST_HPP
#define POST_HPP

#include <iostream>
#include <time.h>
using namespace std;

class Post{
    /**
     * @note: Private Access Identifier,which includes variables that can only changed or accessed through getters and setters
     */
    private:
        string title;
        string body;
        time_t current_time;
        string username;

    /**
     * 
     * @brief:Public acccess Identifier, which includes all public methods that are accessible for the the user. 
     *        Also includes the constructor which sets the title and body of the post to its respective values, as well 
     *        and stamping the time it was created
     * 
     */
    public:
        string getBody() const ;
        string getTitle()const ;
        string getUsername() const ;
        void getTimeStamp() const;
        void setUsername(const string& _username);
        void setBody(const string& _body);
        void setTitle(const string& _title);
        virtual void displayPost() = 0; // A pure virutal function that wont be implemented in the Post class itself. But when called, it will call the most derived version i.e its children classes. 
        Post(string _title, string _body, string _username){
            title = _title;
            body  = _body;
            username = _username;
            time(&current_time);
        }

};

#endif