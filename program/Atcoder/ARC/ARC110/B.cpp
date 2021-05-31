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
    string t;
    cin >> t;
    int cnt[2] = {0, 0};
    int num = 0;
    int z = 0;
    for(int i = 0; i < n; i++){
        if(t[i] == '0') num++;
        if(i == 0 || i == 1 || i == 2){
            cnt[t[i]-'0']++;
            if(cnt[0] >= 2){
                cout << z << endl;
                return 0;
            }
        }
        if(t[i] != t[i%3]){
            cout << z << endl;
            return 0;
        }
    }
    ll V = 10000000000LL;
    if(n == 1){
        if(t[0] == '1'){
            cout << 2*V << endl;
        }
        return 0;
    }
    if(t[n-1] == '0'){
        cout << V - num +1 << endl;
    }else{
        cout << V - num << endl;
    }
    return 0;
}