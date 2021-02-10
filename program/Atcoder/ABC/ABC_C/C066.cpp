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
    vector<int> a(n), b(n);
    for(int i = 0; i< n; i++){
        cin >> a[i];
    }
    if(n%2==0){
        for(int i = 0; i< n; i++){
            if(i % 2 == 0) b[n/2+i/2] = a[i];
            else b[n/2-(i+1)/2] = a[i];
        }
    }else{
        for(int i = 0; i< n; i++){
            if(i % 2 == 0) b[n/2-i/2] = a[i];
            else b[n/2+(i+1)/2] = a[i];
        }
    }
    for(int i = 0; i< n; i++){
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}