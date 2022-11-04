#include <iostream>
#include "Post.hpp"
#include <vector>
#include <time.h>
#include <string>
using namespace std;

class Poll : public Post{
    private:
        //string vector of all the poll options
        vector<string> poll_options;
        //int vector that contains the votes in the specific option
        vector<int> number_of_votes_inside;
        time_t current_time;
    public:
        Poll(string _title, string _question, string _username, vector<string>options) : Post (_title, _question, _username){
            Post::setTitle(_title);
            Post::setBody(_question);
            Post::setUsername(_username);
            time(&current_time);
            for (int i = 0; i < options.size(); i++){
                poll_options.push_back(options[i]);
                number_of_votes_inside.push_back(0);
            }
        }
        bool votePoll(int& num);
        void changePollOption(int& new_poll_option, int& choice_num);
        void getPollOptions()const ;
        int getPollVotes(int index_of_option)const ;
        void displayPost()override;
        /** @note: This method is overriden so if a Post pointer of type Poll was called and it was to displayPost(),
        *          then it would use the displayPost() of its most derived form which, in this case, is Poll.
        */
};