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
const int M = 60;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    //cout << "ko" << endl;
    vector<vector<int>> to(M, vector<int>(n, 0));
    //cout << "ko" << endl;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
        to[0][i] = a[i];
    }
    //cout << "ko" << endl;
    for(int i = 0; i < M-1; i++){
        for(int j = 0; j < n; j++){
            to[i+1][j] = to[i][to[i][j]];
            //cout << to[i+1][j] << endl;
        }
    }
    int M = log2(k);
    //cout << "M" << M << endl;
    ll tar = 0;
    for(int i = 0; i < M+1; i++){
        if(k & (1LL << i)){
            //cout << i << endl;
            tar = to[i][tar];
            //cout << "tar: " << tar << endl;
        }
    }
    cout << tar+1 << endl;
    return 0;
}