#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    int ans = 0, g = n;
    for(int i = 1; i <= n; i++){
        if(g-i >= i+1) g = g-i;
        if(g==i) {
            ans = i;
            break;
        } 
    }
    cout << ans << endl;
    return 0;
}