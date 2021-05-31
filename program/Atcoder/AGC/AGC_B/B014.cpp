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
    int n, m;
    cin >> n >> m;
    vector<int> num(n+1, 0);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        num[a]++;
        num[b]++;
    }
    for(int i = 1; i <= n; i++){
        if(num[i]%2){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}