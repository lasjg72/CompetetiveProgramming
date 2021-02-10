#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int n;
int ans = 0;

int main()
{
    cin >> n;
    queue<ll> q;
    q.push(3); q.push(5); q.push(7);
    int ans = 0;
    while(1){
        ll now = q.front(); q.pop();
        if(now > n) break;
        q.push(10*now + 3); q.push(10*now + 5); q.push(10*now + 7);
        vector<int> a(3,0);
        while(now != 0){
            if(now%10 == 3){
                a[0] = 1;
                now = now/10;
            }else if(now%10 == 5){
                a[1] = 1;
                now = now/10;
            }else if(now%10 == 7){
                a[2] = 1;
                now = now/10;
            }
        }
        if(a[0] == 1 && a[1] == 1 && a[2] == 1){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}