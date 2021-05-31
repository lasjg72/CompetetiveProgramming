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
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    int m = 5;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int l = 0, r = 1001001001;
    while(r-l>1){
        int tar = (l+r)/2;
        vector<int> s;
        for(int i = 0 ; i < n; i++){
            int x = 0;
            for(int j = 0; j < m; j++){
                if(a[i][j] >= tar) x |= 1<<j;
            }
            s.push_back(x);
        }
        // delete multiple data in vector s
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        bool ok = false;
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < i+1; j++){
                for(int k = 0; k < j+1; k++){
                    if((s[i]|s[j]|s[k]) == (1<<m) -1) ok = true;
                }
            }
        }
        if(ok){
            l = tar;
        }else{
            r = tar;
        }
    }
    cout << l << endl;
    return 0;
}