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
    int n, k, s;
    cin >> n >> k >> s;
    vector<int> ans(n, 0);
    if(s != 1e9){
        for(int i = 0; i < k; i++){
            ans[i] = s;
        }
        for(int i = k; i < n; i++){
            ans[i] = s+1;
        }
    }else{
        for(int i = 0; i < k; i++){
            ans[i] = s;
        }
        for(int i = k; i< n; i++){
            ans[i] = 1;
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}