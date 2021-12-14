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
    vector<int> p(n), q(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
        q[p[i]-1] = i+1;
    }
    for(int i : q) cout << i << endl;
    return 0;
}