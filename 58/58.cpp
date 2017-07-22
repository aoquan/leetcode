class Solution {
public:
    int lengthOfLastWord(string s) {
        int i;
        int  len = s.length();
        if(len == 0) return 0;
        int result = 0;
        for(i = len-1; i >=0 && s[i] == ' '; i--);
        for(; i >=0 && s[i] != ' '; i--){
            result ++;
        }
        return result;
    }
};