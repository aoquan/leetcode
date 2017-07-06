#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <cstring>
using namespace std;

void convert2RPN(string &s) {
    stringstream ss;
    stack<char> stk;
    for (size_t i = 0; i < s.length(); i++) {
        if (isdigit(s.at(i))) {
            ss << s.at(i);
            if ((i < s.length() - 1 && !isdigit(s.at(i + 1)))
                    || i == s.length() - 1) {
                ss << ' ';
            }
        }
        else {
            if (stk.empty()) {
                stk.push(s.at(i));
            }
            else {
                switch (s.at(i)) {
                case '(':
                    stk.push(s.at(i));
                    break;
                case ')':
                    while (stk.top() != '(') {
                        ss << stk.top();
                        stk.pop();
                    }
                    stk.pop();
                    break;
                case '+':
                case '-':

                    while (!stk.empty() && stk.top() != '(') {
                        ss << stk.top();
                        stk.pop();
                    }
                    stk.push(s.at(i));
                    break;
                case '*':
                case '/':

                    while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
                        ss << stk.top();
                        stk.pop();
                    }
                    stk.push(s.at(i));
                    break;
                }
            }
        }
    }

    while (!stk.empty()) {
        ss << stk.top();
        stk.pop();
    }
    s = ss.str();
}


float calculateRPN(const string &s) {
    stack<float> stk;
    for (size_t i = 0; i < s.length(); i++) {

        if (isdigit(s.at(i))) {
            int e = atoi(&s.at(i));
            int t = e / 10;
            while (t > 0) {
                i++;
                t /= 10;
            }
            i++;
            stk.push(e);
        }
        else {
            float r = stk.top();
            stk.pop();
            float l = stk.top();
            stk.pop();
            float result;
            switch (s.at(i)) {
            case '+':
                result = l + r;
                break;
            case '-':
                result = l - r;
                break;
            case '*':
                result = l * r;
                break;
            case '/':
                result = l / r;
                break;
            }
            stk.push(result);
        }
    }
    return stk.top();
}

int testRPN(string str) {

    string s = str;
    convert2RPN(s);
    return calculateRPN(s);
}

char graph[5][10000];
int cur = 0;

void print(){
    cur = cur-2;
    for(int i = 0 ; i < 5 ; i ++){
        for(int j = 0 ; j < cur ; j ++){
            cout << graph[i][j];
        }
        cout << endl;
    }
}

int main(){
    char str[1000];
    cin.getline(str, 1000);
    memset(graph, ' ', 5*10000);
    string mystr(str);
    int re = testRPN(mystr);

    stringstream ss;
    ss << re;
    mystr += '='+ss.str();

    for(int i = 0 ; i < mystr.size() ; i ++){
        switch (mystr[i]){
        case '-':
            graph[2][cur] = '*';
            graph[2][cur+1] = '*';
            graph[2][cur+2] = '*';
            cur += 5;
            break;
        case '+':
            graph[2][cur] = '*';
            graph[1][cur+1] = '*';
            graph[2][cur+1] = '*';
            graph[3][cur+1] = '*';
            graph[2][cur+2] = '*';
            cur += 5;
            break;
        case '*':
            graph[1][cur] = '*';
            graph[1][cur+2] = '*';
            graph[2][cur+1] = '*';
            graph[3][cur] = '*';
            graph[3][cur+2] = '*';
            cur += 5;
            break;
        case '/':
            graph[1][cur+2] = '*';
            graph[2][cur+1] = '*';
            graph[3][cur] = '*';
            cur += 5;
            break;
        case '=':
            graph[1][cur] = '*';
            graph[1][cur+1] = '*';
            graph[1][cur+2] = '*';
            graph[1][cur+3] = '*';
            graph[3][cur] = '*';
            graph[3][cur+1] = '*';
            graph[3][cur+2] = '*';
            graph[3][cur+3] = '*';
            cur += 6;
            break;
        case '.':
            graph[3][cur] = '*';
            graph[3][cur+1] = '*';
            graph[4][cur] = '*';
            graph[4][cur+1] = '*';
            cur += 4;
            break;
        case '1':
            graph[0][cur] = '*';
            graph[1][cur] = '*';
            graph[2][cur] = '*';
            graph[3][cur] = '*';
            graph[4][cur] = '*';
            cur += 3;
            break;
        case '2':
            graph[0][cur] = '*';
            graph[2][cur] = '*';
            graph[3][cur] = '*';
            graph[4][cur] = '*';
            graph[0][cur+1] = '*';
            graph[2][cur+1] = '*';
            graph[4][cur+1] = '*';
            graph[0][cur+2] = '*';
            graph[1][cur+2] = '*';
            graph[2][cur+2] = '*';
            graph[4][cur+2] = '*';
            cur += 5;
            break;
        case '3':
            graph[0][cur] = '*';
            graph[2][cur] = '*';
            graph[4][cur] = '*';
            graph[0][cur+1] = '*';
            graph[2][cur+1] = '*';
            graph[4][cur+1] = '*';
            graph[0][cur+2] = '*';
            graph[1][cur+2] = '*';
            graph[2][cur+2] = '*';
            graph[3][cur+2] = '*';
            graph[4][cur+2] = '*';
            cur += 5;
            break;
        case '4':
            graph[0][cur] = '*';
            graph[1][cur] = '*';
            graph[2][cur] = '*';
            graph[2][cur+1] = '*';
            graph[0][cur+2] = '*';
            graph[1][cur+2] = '*';
            graph[2][cur+2] = '*';
            graph[3][cur+2] = '*';
            graph[4][cur+2] = '*';
            cur += 5;
            break;
        case '5':
            graph[0][cur] = '*';
            graph[1][cur] = '*';
            graph[2][cur] = '*';
            graph[4][cur] = '*';
            graph[0][cur+1] = '*';
            graph[2][cur+1] = '*';
            graph[4][cur+1] = '*';
            graph[0][cur+2] = '*';
            graph[2][cur+2] = '*';
            graph[3][cur+2] = '*';
            graph[4][cur+2] = '*';
            cur += 5;
            break;
        case '6':
            graph[0][cur] = '*';
            graph[1][cur] = '*';
            graph[2][cur] = '*';
            graph[3][cur] = '*';
            graph[4][cur] = '*';
            graph[0][cur+1] = '*';
            graph[2][cur+1] = '*';
            graph[4][cur+1] = '*';
            graph[0][cur+2] = '*';
            graph[2][cur+2] = '*';
            graph[3][cur+2] = '*';
            graph[4][cur+2] = '*';
            cur += 5;
            break;
        case '7':
            graph[0][cur] = '*';
            graph[0][cur+1] = '*';
            graph[0][cur+2] = '*';
            graph[1][cur+2] = '*';
            graph[2][cur+2] = '*';
            graph[3][cur+2] = '*';
            graph[4][cur+2] = '*';
            cur += 5;
            break;
        case '8':
            graph[0][cur] = '*';
            graph[1][cur] = '*';
            graph[2][cur] = '*';
            graph[3][cur] = '*';
            graph[4][cur] = '*';
            graph[0][cur+1] = '*';
            graph[2][cur+1] = '*';
            graph[4][cur+1] = '*';
            graph[0][cur+2] = '*';
            graph[1][cur+2] = '*';
            graph[2][cur+2] = '*';
            graph[3][cur+2] = '*';
            graph[4][cur+2] = '*';
            cur += 5;
            break;
        case '9':
            graph[0][cur] = '*';
            graph[1][cur] = '*';
            graph[2][cur] = '*';
            graph[4][cur] = '*';
            graph[0][cur+1] = '*';
            graph[2][cur+1] = '*';
            graph[4][cur+1] = '*';
            graph[0][cur+2] = '*';
            graph[1][cur+2] = '*';
            graph[2][cur+2] = '*';
            graph[3][cur+2] = '*';
            graph[4][cur+2] = '*';
            cur += 5;
            break;
        case '0':
            graph[0][cur] = '*';
            graph[1][cur] = '*';
            graph[2][cur] = '*';
            graph[3][cur] = '*';
            graph[4][cur] = '*';
            graph[0][cur+1] = '*';
            graph[4][cur+1] = '*';
            graph[0][cur+2] = '*';
            graph[1][cur+2] = '*';
            graph[2][cur+2] = '*';
            graph[3][cur+2] = '*';
            graph[4][cur+2] = '*';
            cur += 5;
            break;
        default:
            break;
        }

    }
    print();

    return 0;
}
