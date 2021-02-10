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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 0;
    int k = 0;
    for(int j = 2; j <= 1000; j++){
        bool ok = false;
        int tmp = 0;
        for(int i = 0; i < n; i++){
            if(a[i] % j == 0) {
                tmp++;
            }   
        }
        if(tmp >= ans){
            ans = tmp;
            k = j;
        }
    }
    cout << k << endl;
    return 0;
}