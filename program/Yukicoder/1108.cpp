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
    int n, h;
    cin >> n >> h;
    vector<int> t(n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
        t[i] += h;
    }
    for(int i = 0; i < n; i++){
        cout << t[i] << " ";
    }
    cout << endl;
    return 0;
}