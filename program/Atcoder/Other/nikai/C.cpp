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
    int a, b;
    cin >> a >> b;
    vector<int> num(b+1, 0);
    for(int i = b; i >= a; i--){
        for(int j = 1; j*j <= i; j++){
            if(i%j==0) {
                num[j]++;
                if(i/j != j) num[i/j]++;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= b; i++){
        if(num[i] > 1) ans = max(ans, i);
    }
    cout << ans << endl;
    return 0;
}