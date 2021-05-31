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
    vector<vector<int>> p(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        p[a].push_back(i);
    }
    for(int i = 0; i < n; i++){
        int pos = -1;
        p[i].push_back(n);
        for(int j : p[i]){
            if(j-pos > m){
                cout << i << endl;
                return 0;
            }
            pos = j;
        }
    }
    cout << n << endl;
    return 0;
}