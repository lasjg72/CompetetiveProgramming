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
    vector<int> f(n);
    for(int i = 0; i < n; i++){
        cin >> f[i];
        f[i]--;
    }
    int num = 0;
    vector<int> res(n, 0);
    for(int i = 0; i < n; i++){
        if(res[i] > 0) continue;
        int now = i;
        while(f[now] != i && f[now] != now){
            if(res[f[now]] > 0){
                
            }
            res[f[now]]++;
            now = f[now];
        }
        num++;
    }
    return 0;
}