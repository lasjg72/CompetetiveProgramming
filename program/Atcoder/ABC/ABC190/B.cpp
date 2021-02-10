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
    int n, s, d;
    cin >> n >> s >> d;
    bool flag = false;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if(x < s && y > d){
            flag = true;
        }
    }
    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}