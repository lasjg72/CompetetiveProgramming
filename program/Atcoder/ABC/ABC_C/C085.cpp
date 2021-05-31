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
    int n, y;
    cin >> n >> y;
    for(int i = 0; i <= min(y/10000, n); i++){
        for(int j = 0; j <= min(y/5000, n); j++){
            int now = n-i-j;
            if(now < 0) continue;
            if(10000*i+5000*j+1000*now == y){
                cout << i << " " << j << " " << now << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}