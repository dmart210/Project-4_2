//General.hpp

#include <iostream>
#include "Post.hpp"
using namespace std;
// enum with all the reactions as an int
enum Reactions:int{LIKE, DISLIKE, LAUGH, WOW ,SAD , ANGRY }; 
//General class inherited but the post class
class General: public Post{
    private:
        //react refers to the amount of reactions which are initialized to 0. and it is private
        int react[6];
        time_t current_time;
    public:  
        bool reactToPost(const Reactions& reaction);
        void getReactions() const;
        void displayPost()override ;
        /** @note: This method is overriden so if a Post pointer of type General was called and it was to displayPost(),
        *          then it would use the displayPost() of its most derived form which, in this case, is General.
        */
        General(string _title, string _body, string _username): Post (_title, _body, _username){
            for (int i = 0; i<= 5; i++){
                react[i] = 0;
            }
            time(&current_time);
        }
};