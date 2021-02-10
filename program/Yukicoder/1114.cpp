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
    int n;
    cin >> n;
    if(n == 1) cout << 1 << endl;
    else{
        if(n % 2 == 0){
            for(int i = n/2 + 1; i <= n; i++){
                cout << i << " ";
            }
            cout << endl;
        }else{
            for(int i = (n+1)/2; i<=n; i++){
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}