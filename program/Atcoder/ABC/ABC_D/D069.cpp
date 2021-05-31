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
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    queue<int> q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 0; j < a[i]; j++){
            q.push(i+1);
        }
    }
    vector<vector<int>> ans(h, vector<int>(w));
    for(int i = 0; i < h; i++){
        if(i%2){
            for(int j = w-1; j >= 0; j--){
                ans[i][j] = q.front();
                q.pop();
            }
        }else{
            for(int j = 0; j < w; j++){
                ans[i][j] = q.front();
                q.pop();
            }
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}