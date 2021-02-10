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
    vector<int> x(n, 0);
    for(int i =0 ; i< n;i++){
        cin >> x[i];
    }
    sort(x.begin(), x.end());

    long long tmp =0, ans = 0;
    for(int i = x[0]; i< x[n-1]; i++){
        for(int j = 0; j<n;j++){
            tmp += pow(abs(i-x[j]), 2);
        }
        if(i == x[0]) ans = tmp;
        else ans = min(tmp, ans);

        tmp = 0;
    }
    cout << ans << endl;
    return 0;
}