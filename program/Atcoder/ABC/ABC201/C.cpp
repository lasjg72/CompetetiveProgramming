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

vector<vector<int>> ans(100, vector<int>(100));

std::vector<std::vector<int>> comb(int n, int r) {
  std::vector<std::vector<int>> v(n + 1,std::vector<int>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}

int main()
{
    string s;
    cin >> s;
    map<char, int> mp;
    for(int i = 0; i < 10; i++){
        mp[s[i]]++;
    }
    int tmp = 4;
    ll an = 0;
    if(mp['o'] > 4) cout << 0 << endl;
    else{
        
        if(mp['o'] == 1){
            // 4回使う時
            an += 1;
            // 3回使う時
            an += 4*mp['?'];
            // 2回使う時
            if(mp['?'] >= 2){
                ans = comb(mp['?'], 2);
                an += 12*ans[mp['?']][2];
            }else{
                an += 6;
            }
            // 1回使う時
            if(mp['?'] >= 3){
                ans = comb(mp['?'], 3);
                an += 24*ans[mp['?']][3];
            }else if(mp['?'] == 2){
                
            }else{

            }
        }else if(mp['o'] == 2){
            
            // 両方1回ずつしか使わない時
            ans = comb(mp['?'], 2);
            an += ans[mp['?']][2];
            // 片方を2回使う時
            an += 12*mp['?']*2;
            // 両方を2回ずつ使う時
            an += 6;
            // 片方を3回使う時
            an += 8;
        }else if(mp['o'] == 3){
            an += 36;
            an += 24*mp['?'];
        }else{
            an += 24;
        }
        cout << an << endl;
    } 
    
    return 0;
}