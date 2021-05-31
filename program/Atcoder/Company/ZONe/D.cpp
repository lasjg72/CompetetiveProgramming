#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>
#include <deque>

using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    deque<char> t;
    int num = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'R'){
            if(num == 0){
                num = 1;
            }else{
                num = 0;
            }
        }else{
            if(num == 0){
                if(!t.empty() && t.back() == s[i]){
                    t.pop_back();
                    continue;
                }
                t.push_back(s[i]);
                //cout << "push back: " << s[i] << endl;
            }else{
                if(!t.empty() && t.front() == s[i]) {
                    t.pop_front();
                    continue;
                }
                t.push_front(s[i]);
                //cout << "push front: " << s[i] << endl;
            }
        }
    }
    if(num == 0){
        while(!t.empty()){
            char now = t.front(); t.pop_front();
            if(now == t.front()){
                t.pop_front();
            }else{
                cout << now;
            }
        }
        cout << endl;
    }else{
        char pre;
        while(!t.empty()){
            char now = t.back(); t.pop_back();
            // cout << "now: " << now << endl;
            // cout << "pre: " << pre << endl;
            if(now == t.back() || now == pre){
                t.pop_back();
            }else{
                cout << now;
                pre = now;
            }
        }
        cout << endl;
    }
    return 0;
}