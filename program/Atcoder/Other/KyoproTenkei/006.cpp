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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> num(s.size(), vector<int>(26, 0));
    for(int i = s.size()-1; i >= 0; i--){
        //cout << "char: " << s[i] << endl;
        for(char c = 'a'; c <= 'z'; c++){
            if(c == s[i]){
                num[i][s[i]-'a'] = i;
            }else{
                if(i == s.size()-1){
                    num[i][c-'a'] = -1;
                }else{
                    num[i][c-'a'] = num[i+1][c-'a'];
                }
            }
            //cout << "num[i][c-'a']: " << num[i][c-'a'] << endl;
        }
        
    }
    string ans(k, 'a');
    int pos = 0;
    for(int i = 0; i < k; i++){
        for(char c = 'a'; c <= 'z'; c++){
            // cout << "i: " << i << endl;
            // cout << "num[i][c-'a']: " << num[i][c-'a'] << endl;
            if(num[pos][c-'a'] == -1) continue;
            if(n-(k-i) >= num[pos][c-'a']){
                ans[i] = c;
                pos = num[pos][c-'a']+1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}