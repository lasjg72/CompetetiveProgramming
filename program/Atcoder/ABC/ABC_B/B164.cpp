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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    while(1){
        c = c-b;
        if(c <= 0){
            cout << "Yes" << endl;
            break;
        }
        a = a-d;
        if(a <= 0){
            cout << "No" << endl;
            break;
        }
    }

    return 0;
}
