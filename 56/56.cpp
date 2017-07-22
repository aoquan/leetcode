#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class cmp{
    public:
        bool operator()(Interval i1, Interval i2){
            if(i1.start == i2.start) return i1.end < i2.end;
            return i1.start < i2.start;
        }
};
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp());
        //show(intervals);
        vector<Interval> result;
        int len = intervals.size();
        if(len == 0) return result;
        int i;
        int start = intervals[0].start, end = intervals[0].end;
        for(i = 1; i < len; i++){
            if(intervals[i].start <= end){
                if(intervals[i].end > end)
                end = intervals[i].end;
            }
            else{
                result.push_back(Interval(start,end));
                start  = intervals[i].start;
                end =  intervals[i].end;
            }
        }
        result.push_back(Interval(start,end));
        return result;
    }

    void show(vector<Interval>& itls){
        int len = itls.size();
        int i;
        for(i = 0; i < len; i++){
            cout<< itls[i].start<<" "<<itls[i].end<<endl;
        }
    }
};

int main(){
    Solution s;
    vector<Interval> itls,re;
    int m,n;
    while(cin>>m>>n){
        itls.push_back(Interval(m,n));
    }
    re = s.merge(itls);
    s.show(re);
}
