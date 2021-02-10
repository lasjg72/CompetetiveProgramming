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
    int n, k;
    cin >> n >> k;
    string s; 
    cin >> s;
    int num = 0;
    for(int i = 0; i < n-1; i++) if(s[i] != s[i+1]) num++;
    cout << n-1-max(num - 2*k, 0) << endl;
    return 0;
}