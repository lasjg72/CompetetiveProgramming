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
    vector<int> l(n);
    for(int i = 0; i < n; i++){
        cin >> l[i];
    }
    int ans = 0;
    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for(int k = j+1; k < n; k++){
                if(l[i] != l[j] && l[i] != l[k] && l[j] != l[k]){
                    if(l[i] < l[j] + l[k] && l[j] < l[i] + l[k] && l[k] < l[j] + l[i]) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}