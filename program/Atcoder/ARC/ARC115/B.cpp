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
    int n;
    cin >> n;
    vector<vector<ll>> c(n, vector<ll>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c[i][j];
        }
    }
    // for(int i = 0; i < n-1; i++){
    //     int num = c[i][0] - c[i+1][0];
    //     for(int j = 1; j < n; j++){
    //         if(c[i][j]-c[i+1][j] != num){
    //             cout << "No" << endl;
    //             return 0;
    //         }
    //     }
    // }
    vector<ll> a(n), b(n);
    if(n == 1){
        a[0] = c[0][0];
        b[0] = 0;
    }else{
        a[0] = c[0][0] - c[1][0];
        for(int i = 1; i < n; i++){
            a[i] = a[0]-(c[0][0]-c[i][0]);
        }
        for(int i = 0; i < n; i++){
            b[i] = c[0][i]-a[0];
        }
    }
    ll mi=0;
    bool ab = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i]+b[j] != c[i][j]){
                cout << "No" << endl;
                //cout << "ko" << endl;
                return 0;
            }
            if(a[i] < 0) {
                mi = min(mi, a[i]);
                ab = true;
            }
            if(b[i] < 0) {
                mi = min(mi, b[i]);
                ab = false;
            }
        }
    }
    if(mi < 0){
        if(ab == true){
            for(int i = 0; i < n; i++){
                a[i] -= mi;
                b[i] += mi;
            }
        }else{
            for(int i = 0; i < n; i++){
                a[i] += mi;
                b[i] -= mi;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i] < 0 || b[i] < 0){
            //cout << "i: " << i << "a[i]: " << a[i] << endl; 
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    for(int i = 0; i < n; i++){
        if(i == n-1) cout << a[i];
        else cout << a[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        if(i == n-1) cout << b[i];
        else cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}