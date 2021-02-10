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
    char s;
    cin >> s;
    if(s == 'A'){
        cout << 'T' << endl;
    }else if(s == 'T'){
        cout << 'A' << endl;
    }else if(s == 'C'){
        cout << 'G' << endl;
    }else if(s == 'G'){
        cout << 'C' << endl;
    }
    return 0;
}