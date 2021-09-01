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
    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    vector<int> num(n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(c[i]%c[j]==0) num[i]++;
        }
    }
    double ans = 0.0;
    for(int i = 0; i < n; i++){
        if(num[i]%2){
            ans += (double)1/2;
        }else{
            ans += (double)(num[i]+2)/(2*(num[i]+1));
        }
        //cout << "ans: " << ans << endl;
    }
    printf("%.7f\n", ans);
    return 0;
}