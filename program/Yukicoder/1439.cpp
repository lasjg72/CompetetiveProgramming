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
    int n, q;
    string s, t;
    cin >> n >> s >> t >> q;
    set<int> num;
    for(int i = 0; i < n; i++){
        if(s[i] != t[i]) num.insert(i);
    }
    while(q--){
        char c, y;
        int x;
        cin >> c >> x >> y;
        x--;
        int now;
        if(c == 'S'){
            s[x] = y;
            if(s[x] != t[x]){
                num.insert(x);
            }else{
                num.erase(x);
            }
            now = *num.begin();
        }else{
            t[x] = y;
            if(s[x] != t[x]){
                num.insert(x);
            }else{
                num.erase(x);
            }
            now = *num.begin();
        }
        if(s[now]-'0' > t[now] -'0'){
            cout << '>' << endl;
        }else if(s[now]-'0' < t[now] -'0'){
            cout << '<' << endl;
        }else{
            cout << '=' << endl;
        }
    }
    return 0;
}