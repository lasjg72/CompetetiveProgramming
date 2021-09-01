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
    bool ng = false;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    h[0]--;
    for(int i = 1; i < n; i++){
        if(h[i-1] > h[i]){
            cout << "No" << endl;
            return 0;
        }else if(h[i-1] < h[i]){
            h[i]--;
        }
    }
    cout << "Yes" << endl;
    return 0;
}