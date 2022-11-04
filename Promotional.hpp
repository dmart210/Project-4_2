//Promotional.hpp


#include <iostream>
#include "Post.hpp"

using namespace std;

class Promotional:public Post{
    private: 
        string url;
        time_t current_time;
    public:
        Promotional (const string _title,const string _body, const string _username, const string link);
        string getLink()const;
        bool setLink(const string& _link);
        void displayPost() override; 
        /** @note: This method is overriden so if a Post pointer of type Promotional was called and it was to displayPost(),
        *          then it would use this diplayPost which contains the properties of the Promotional children class.
        */

};