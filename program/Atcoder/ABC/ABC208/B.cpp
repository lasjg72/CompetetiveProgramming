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
    int p;
    cin >> p;
    int ans = 0;
    while(p > 0){
        int now = 1;
        for(int i = 1; i <= 11; i++){
            if(now*i > p) break;
            now *= i;
        }
        //cout << "now: " << now << endl; 
        int num = 1, tmp = now;
        for(int i = 1; i < 100; i++){
            if(now+tmp > p) break;
            now += tmp;
            num++;
        }
        //cout << "num: " << num << endl;
        p -= now;
        ans += num;
    }
    cout << ans << endl;
    return 0;
}