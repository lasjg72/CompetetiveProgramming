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
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(n,0);
    int sum = 0;
    for(int i = 1; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    int goal = n*m;
    if(goal - sum > k){
        cout << -1 << endl;
        return 0;
    }else{
        if(goal - sum < 0){
            cout << 0 << endl;
            return 0;
        }
        cout << goal -sum << endl;
    }
    return 0;
}