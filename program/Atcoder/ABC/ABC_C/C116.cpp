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
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    int ans = 0;
    while(1){
        //cout << "max: " << *max_element(h.begin(), h.end()) << endl;
        if(*max_element(h.begin(), h.end()) == 0) break;

        int i = 0;
        while(i < n){
            if(h[i] == 0) i++;
            else{
                ans++;
                while(i < n && h[i] > 0){
                    h[i]--;
                    i++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}