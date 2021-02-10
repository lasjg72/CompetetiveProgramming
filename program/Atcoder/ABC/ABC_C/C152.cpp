#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i< n; i++){
        cin >> p[i];
    }

    int ans = 0;
    int min = p[0];
    auto cnt = [&](int i){
        if(p[i] <= min){
            ans++;
            min = p[i];
        }
    };

    for(int i = 0;i<n;i++){
        cnt(i);
    }
    cout << ans << endl;
    return 0;
}