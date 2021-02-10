#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;
string ans(n, 'S');
int n;

void check(int num, char c){
    int pre;
    if(num == 0){
        pre = n-1;
    }else{
        pre = num-1;
    }

    if(c == 'o'){
        if(ans[num]=='S'){
            ans[pre] = 'S';
            ans[num+1] = 'S';
        }else{
            if(ans[pre] == 'S'){
                ans[num+1] = 'W';
            }else if(ans[pre] == 'W'){
                ans[num+1] = 'S';
            }else if(ans[num+1] == 'S'){
                ans[pre] = 'W';
            }else{
                ans[pre] = 'S';
            }
        }
    }else{
        if(ans[num] == 'S'){
            if(ans[pre] == 'S'){
                ans[num+1] = 'W';
            }else if(ans[pre] == 'W'){
                ans[num+1] = 'S';
            }else if(ans[num+1]=='S'){
                ans[pre] = 'W';
            }else if(ans[num+1]=='W'){
                ans[pre] = 'S';
            }
        }else{
            
        }
    }
}

int main()
{
    string s;
    cin >> n >> s;

    return 0;
}