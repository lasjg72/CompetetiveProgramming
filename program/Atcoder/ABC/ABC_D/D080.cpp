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
    int n, c;
    cin >> n >> c;
    vector<vector<int>> num(c, vector<int>(100005, 0));
    for(int i = 0; i < n; i++){
        int s, t, ch;
        cin >> s >> t >> ch;
        s--; t--; ch--;
        if(num[ch][s] != 0){
            num[ch][s] = 0;
        }else{
            num[ch][s] = 1;
        }
        if(num[ch][t] != 0){
            num[ch][t] = 0;
        }else{
            num[ch][t] = -1;
        }
    }
    vector<int> p(100005, 0);
    for(int i = 0; i < c; i++){
        for(int j = 0; j <= 100000; j++){
            if(num[i][j] == 1){
                p[j]++;
            }
            if(num[i][j] == -1){
                p[j+1]--;
            }
            //cout << "i, j: " << i << " " << j << " num[i][j]: " << num[i][j] << endl;
        }
    }
    for(int i = 0; i <= 100000; i++){
        p[i+1] += p[i];
    }
    int ans = 0;
    for(int i = 0; i <= 100000; i++){
        ans = max(ans, p[i]);
    }
    cout << ans << endl;
    return 0;
}