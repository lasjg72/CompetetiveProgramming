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
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }
    vector<int> ans;
    int tmp = 1;
    int mi = 0;
    for(int i = 0; i < n; i++){
        if(p[i] == mi){
            for(int j = i; j >= tmp; j--){
                swap(p[j], p[j-1]);
                ans.push_back(j);
            }
            for(int j = tmp-1; j < i; j++){
                if(p[j] != j){
                    cout << -1 << endl;
                    return 0;
                }
                mi = j+1;
            }
            tmp = i+1;
        }
    }
    if(ans.size() < n-1){
        cout << -1 << endl;
    }else{
        for(int i : ans){
            cout << i << endl;
        }
    }
    
    return 0;
}