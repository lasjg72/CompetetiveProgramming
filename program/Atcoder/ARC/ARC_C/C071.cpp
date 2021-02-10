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

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    map<char, int> t;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
    }
    int ans = 0;
    for(int i = 'a'-'0'; i <= 'z'-'0'; i++){
        char now = i + '0';
        //cout << "now = " << now << endl;
        int num = 0;
        for(int j = 0; j < n; j++){
            int tmp = 0;
            for(int k = 0; k < s[j].size(); k++){
                if(s[j][k] == now){
                    tmp++;
                }
            }
            if(tmp == 0){
                num = 0;
                break;
            }
            if(j == 0){
                num = tmp;
            }else{
                num = min(num, tmp);
            }
        }
        t[now] += num;
    }

    for(int i = 'a'-'0'; i <= 'z'-'0'; i++){
        //cout << "t[i]: " << t[i+'0'] << endl;
        for(int j = 0; j < t[i+'0']; j++){
            char now = i + '0';
            cout << now;
        }
    }
    cout << endl;
    return 0;
}