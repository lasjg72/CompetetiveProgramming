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
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    P p = {0, 0}, q = {0, 0};
    for(int i = 2; i <= n; i++){
        int dist;
        cout << "?: " << 1 << " " << i << endl;
        cin >> dist;
        if(p.first < dist) p = {dist, i};
    }
    for(int i = 1; i <= n; i++){
        if(i == p.second) continue;
        int dist;
        cout << "?: " << p.second << " " << i << endl;
        cin >> dist;
        if(q.first < dist) q = {dist, i};
    }
    cout << "! " << q.first << endl;
    return 0;
}