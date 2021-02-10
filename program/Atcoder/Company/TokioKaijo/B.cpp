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
    long long a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;
    if (v - w <= 0){
        cout << "NO" << endl;
    }
    else if( abs(b - a) <= t * (v-w))
    {
        cout << "YES" << endl;        
    }else{
        cout << "NO" << endl;
    }
 
    return 0;
}
