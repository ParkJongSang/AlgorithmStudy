#include <string>
#include <iostream>

using namespace std;

int to_second(int hour, int min, int sec){
    return hour * 3600 + min * 60 + sec;
}
string solution(string start, string end) {
    string answer = "";
    string start_prifix = start.substr(0, 2);
    int start_hour = atoi(start.substr(3, 2).c_str());
    if(start_prifix == "PM") start_hour += 12;
    int start_min = atoi(start.substr(6, 2).c_str());
    int start_second = atoi(start.substr(9, 2).c_str());
    string end_prifix = end.substr(0, 2);
    int end_hour = atoi(end.substr(3, 2).c_str());
    if(end_prifix == "PM") end_hour += 12;
    int end_min = atoi(end.substr(6, 2).c_str());
    int end_second = atoi(end.substr(9, 2).c_str());
    
    int one_day = to_second(24, 0, 0);
    int left = to_second(start_hour, start_min, start_second);
    int right = to_second(end_hour, end_min, end_second);
    int ret = 0;
    //xcout <<one_day<<" " << left << " " << right << endl;
    if(left > right){
        ret = one_day - left;
        ret += right;
    }else{
        ret = right - left;
    }
    string ret_hour;
    if(ret / 60 < 10) ret_hour = '0' + to_string(ret/3600);
    else ret_hour = to_string(ret/3600);
    ret %= 3600;
    string ret_min;
    if(ret / 60 < 10) ret_min = '0' + to_string(ret/60);
    else ret_min = to_string(ret/60);
    ret %= 60;
    string ret_sec;
    if(ret < 10) ret_sec = '0' + to_string(ret);
    else ret_sec = to_string(ret);
    
    answer = ret_hour+":"+ret_min+":"+ret_sec;
    
    return answer;
}
int main(void){
    string tmp, tmp_2;
    getline(cin, tmp);
    getline(cin, tmp_2);
    cout << solution(tmp, tmp_2) << endl;
    return 0;
}