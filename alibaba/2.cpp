#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

/** 请完成下面这个函数，实现题目要求的功能 **/
 /** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
int findMeetingTime(vector < string > meetingTimeArray) {


}

int main() {
    int res;

    int _meetingTimeArray_size = 0;
    cin >> _meetingTimeArray_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _meetingTimeArray;
    string _meetingTimeArray_item;
    for(int _meetingTimeArray_i=0; _meetingTimeArray_i<_meetingTimeArray_size; _meetingTimeArray_i++) {
        getline(cin, _meetingTimeArray_item);
        _meetingTimeArray.push_back(_meetingTimeArray_item);
    }
    
    res = findMeetingTime(_meetingTimeArray);
    cout << res << endl;
    
    return 0;

}