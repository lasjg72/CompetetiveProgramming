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
    int n, x;
    cin >> n >> x;
    vector<int> a(n,0);
    int s = 0;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if(tmp == x) continue;
        else{
            a[s] = tmp;
            s++;
        }
    }
    if(s == 0){
        cout << " ";
    }else{
        for(int i = 0; i < s; i++){
            cout << a[i] << " ";
        }
    }
    return 0;
}