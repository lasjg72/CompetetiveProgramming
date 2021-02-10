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
    vector<pair<int, int>> a, b;
    //vector<int> b(n);
    bool g = false;
    int a1 = 0, b1 = 0;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a[i] = {x, i};
        if(x == -1) a1++;
        b[i] = {y, i};
        if(y == -1) b1++;
    }
    queue<pair<int, int>> qa, qb;
    int ast, bst;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        if(a[i].first != -1) {
            ast = i;
            break;
        }
    }
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++){
        if(b[i].first != -1) {
            bst = i;
            break;
        }
    }

    for(int i = 0; i < n; i++){
        if()
    }
    if(g){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}