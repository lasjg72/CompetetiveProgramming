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

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int a, b;
    cin >> a >> b;
    vector<int> ans(4, 1);
    ans[a] = 0;
    ans[b] = 0;
    for(int i = 1; i< 4; i++){
        if(ans[i] != 0){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}