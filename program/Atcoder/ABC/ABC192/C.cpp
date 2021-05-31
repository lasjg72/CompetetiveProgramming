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
    int n, k;
    cin >> n >> k;
    for(int p = 0; p < k; p++){
        string ns = to_string(n);
        string ns1, ns2;
        vector<int> a(ns.size(), 0), na1, na2;
        for(int i = 0; i < ns.size(); i++){
            a[i] = ns[i];
        }
        sort(a.begin(), a.end());
        na1 = a;
        for(int i = 0; i < na1.size(); i++){
            ns1 += na1[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        na2 = a;
        for(int i = 0; i < na2.size(); i++){
            ns2 += na2[i];
        }
        //cout << "ns1: " << ns1 << " 2: " << ns2 << endl;
        n = stoi(ns2) - stoi(ns1);
    }
    cout << n << endl;
    return 0;
}