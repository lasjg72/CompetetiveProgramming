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
int num[1005];

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i] == b[j]) num[a[i]] = 1;
            else{
                if(num[a[i]] != 1) num[a[i]] = 2;
                if(num[b[j]] != 1) num[b[j]] = 2;
            }
        }
    }
    vector<int> ans;
    for(int i = 1; i <= 1000; i++){
        if(num[i] == 2) ans.push_back(i);
    }
    if(ans.size() == 0){
        cout << "" << endl;
    }else{
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}