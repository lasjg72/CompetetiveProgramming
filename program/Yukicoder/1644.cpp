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
    int k;
    cin >> k;
    int ans = 0;
    vector<int> n(8);
    for(int i = 1; i <= 8; i++) n[i-1] = i;
    do{
        int tmp = 10000000;
        int now = n[7];
        for(int i = 0; i < 7; i++){
            now += n[i]*tmp;
            tmp /= 10;
        }
        if(now%k == 0) ans++;
    }while(next_permutation(n.begin(), n.end()));
    cout << ans << endl;
    return 0;
}