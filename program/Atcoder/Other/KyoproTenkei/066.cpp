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
    vector<int> L(n), R(n);
    for(int i = 0; i < n; i++){
        cin >> L[i] >> R[i];
    }
    double ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int cnt = 0, sum = 0;
            for(int r1 = L[i]; r1 <= R[i]; r1++){
                for(int r2 = L[j]; r2 <= R[j]; r2++){
                    if(r1 > r2) cnt++;
                    sum++;
                }
            }
            ans += (double)cnt/sum;
        }
    }
    printf("%.8f\n", ans);
    return 0;
}