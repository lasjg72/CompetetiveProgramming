#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

int main()
{
    ll h;
    cin >> h;
    ll ans =1, num = 1;
    if(h == 1){
        cout << ans << endl;
        return 0;
    }
    do{
        ans += 2*num;
        num *= 2;
        h = h/2;
    }while(h != 1);

    cout << ans << endl;

    return 0;
}