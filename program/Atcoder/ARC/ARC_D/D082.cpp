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
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(p[i] == i+1){
            swap(p[i], p[i+1]);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}