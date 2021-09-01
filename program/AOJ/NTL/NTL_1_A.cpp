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

vector<P> solve(int n){
    vector<P> res;
    for(int i = 2; i*i <= n; i++){
        int num = 0;
        while(n%i == 0){
            n /= i;
            num++;
        }
        if(num != 0){
            res.push_back(P(i, num));
        }
    }
    if(n != 1) res.push_back(P(n, 1));
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << n << ":";
    vector<P> ans = solve(n);
    for(P p : ans){
        for(int i = 0; i < p.second; i++){
            cout << " " << p.first;
        }
    }
    cout << endl;
    return 0;
}