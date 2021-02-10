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
    int m, d;
    cin >> m >> d;
    int ans = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= d; j++){
            if(j / 10 >= 2 && j % 10 >= 2 && (j / 10) * (j % 10) == i){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}