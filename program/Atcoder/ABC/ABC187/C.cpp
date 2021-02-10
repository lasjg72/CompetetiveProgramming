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
    vector<string> S(n);
    map<string, int> tmp;
    bool flag = false;
    string ans = "";
    for(int i = 0; i < n; i++){
        cin >> S[i];
        tmp[S[i]]++;
        if(S[i][0] == '!'){
            S[i].erase(S[i].begin());
            if(tmp[S[i]] >= 1){
                ans = S[i];
                flag = true;
            }else{
                S[i].insert(S[i].begin(), '!');        
            }
        }else{
            S[i].insert(S[i].begin(), '!');
            if(tmp[S[i]] >= 1){
                S[i].erase(S[i].begin());
                ans = S[i];
                flag = true;
            }else{
                S[i].erase(S[i].begin());
            }
        }
    }
    if(flag){
        cout << ans << endl;
    }else{
        cout << "satisfiable" << endl;
    }
    return 0;
}