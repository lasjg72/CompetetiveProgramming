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
#include <stack>

using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    stack<char> q;
    q.push(s[0]);
    int num = 0;
    if(n <= 2){
        cout << n << endl;
        return 0;
    }else{
        while(num<n){
            num++;
            char now = q.top();
            // cout << "now: " << now << endl;
            // cout << "num: " << num << endl;
            // cout << "q.size: " << q.size() << endl;
            if(num+1 < n && now == 'f' && s[num]=='o' && s[num+1]=='x'){
                q.pop();
                num += 2;
                if(num>=n) break;
                q.push(s[num]);
            }else if(now == 'o'){
                q.pop();
                if(q.size() == 0){
                    q.push('o');
                    if(num>=n) break;
                    q.push(s[num]);
                    continue;
                }
                char tmp = q.top();
                if(tmp == 'f' && s[num] == 'x'){
                    q.pop();
                    num++;
                    if(num>=n) break;
                    q.push(s[num]);
                }else{
                    q.push('o');
                    if(num>=n) break;
                    q.push(s[num]);
                }
            }else if(now == 'x'){
                q.pop();
                if(q.size() == 0){
                    q.push('x');
                    if(num>=n) break;
                    q.push(s[num]);
                    continue;
                }
                char tmp1 = q.top();
                if(tmp1=='o'){
                    q.pop();
                    if(q.size() == 0){
                        q.push('o');
                        q.push('x');
                        if(num>=n) break;
                        q.push(s[num]);
                        continue;
                    }
                    char tmp2 = q.top();
                    if(tmp2 == 'f'){
                        q.pop();
                        if(num>=n) break;
                        q.push(s[num]);
                    }else{
                        q.push('o');
                        q.push('x');
                        if(num>=n) break;
                        q.push(s[num]);
                    }
                }else{
                    q.push('x');
                    if(num>=n) break;
                    q.push(s[num]);
                }
            }
            else{
                if(num>=n) break;
                q.push(s[num]);
            }
        }
        cout << q.size() << endl;
    }
    return 0;
}