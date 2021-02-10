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
    vector<vector<int>> t(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> t[i][j];
        }
    }
    vector<int> c(n-1);
    for(int i = 1; i < n; i++){
        c[i-1] = i;
    }
    // for(int i = 0; i < n-1; i++){
    //     cout << "i: " << i  << "c: " << c[i] << endl;
    // }
    int ans = 0;
    do{
        ll tmp = t[0][c[0]];
        //cout << "tmp1: " << tmp << endl;
        for(int i = 1; i < n-1; i++){
            tmp += t[c[i-1]][c[i]];
        }
        //cout << "tmp2: " << tmp << endl;
        tmp += t[c[n-2]][0];
        //cout << "tmp3: " << tmp << endl;
        if(tmp == k){
            ans++;
        }
    }while(next_permutation(c.begin(), c.end()));
    cout << ans << endl;
    return 0;
}