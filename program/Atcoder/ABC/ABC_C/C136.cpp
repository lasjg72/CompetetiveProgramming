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
    int n, pre;
    cin >> n;
    for(int i = 0; i < n; i++){
        int h;
        cin >> h;
        if(i != 0 && i != n-1){
            if(h < pre || abs(h-pre) >= 2){
                cout << "No" << endl;
                return 0;
            }
        }
        if(i == n-1 && h >= pre) cout << "Yes" << endl;
        else cout << "No" << endl;
        if(h-pre == 1) pre = h-1;
        else pre = h;
    }
    return 0;
}