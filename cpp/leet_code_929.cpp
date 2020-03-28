#include <map>

#define EMAIL_NAME 0
#define LOCAL_NAME 1
#define CORP_NAME 2

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int ret = 0;
        string email = "";
        string corp = "";
        
        set<string> emailSet;
        int state = EMAIL_NAME;
        
        for(int i = 0; i < emails.size(); i++) {
            email = "";
            corp = "";
            state = EMAIL_NAME;
            for(int j = 0; j < emails[i].size(); j++) {
                char curChar = emails[i][j];
                
                if (state == EMAIL_NAME) {
                    if(curChar == '.') {
                        continue;
                    } else if(curChar == '+') {
                        state = LOCAL_NAME;
                    } else if(curChar == '@') {
                        corp.push_back(curChar);
                        state = CORP_NAME;  
                    } else {
                        email.push_back(curChar);
                    }
                } else if (state == LOCAL_NAME) {
                    if(curChar == '@') {
                        corp.push_back(curChar);
                        state = CORP_NAME;
                    } else {
                        continue;
                    }
                } else if (state == CORP_NAME) {
                    corp.push_back(curChar);
                }
            }
            cout << email << corp << endl;
            emailSet.insert(email+corp);
        }
        
        ret = emailSet.size();
        
        return ret;
    }
};
