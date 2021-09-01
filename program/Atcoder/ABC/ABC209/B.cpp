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
    int n, x;
    cin >> n >> x;
    int tot = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if((i+1)%2 == 0){
            a--;
        }
        tot += a;
    }
    if(x >= tot) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}