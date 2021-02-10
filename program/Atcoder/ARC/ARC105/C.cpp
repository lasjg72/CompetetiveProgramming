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
    int n, m;
    cin >> n >> m;
    vector<int> w(n), l(m), v(m);
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    sort(w.rbegin(), w.rend());

    for(int i = 0; i < m; i++){
        cin >> l[i] >> v[i];
        if(v[i] < w[0]){
            cout << -1 << endl;
            return 0;
        }
    }
    vector<int> nv = v;
    sort(nv.begin(), nv.end());
    int mi = nv[0]; //ラクダグループの最小体重
    int numg = n;
    int tmp = w[0];
    int tn = 0;
    for(int i = 0; i < n-1; i++){
        if(nv[i] + tmp <= mi){
            numg--;
            tmp = nv[i] + tmp;
        }else{
            tn++;
            if(w[tn] == nv[i]){
                break;
            }
            tmp = w[tn];
        }
    }
    return 0;
}