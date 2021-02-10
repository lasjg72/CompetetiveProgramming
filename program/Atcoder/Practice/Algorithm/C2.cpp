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
    long long a, r, n;
    cin >> a >> r >> n;
    long long ans = a;
    for(int i =0; i<n-1; i++){
        if(ans * r > 1e9){
            cout << "large" << endl;
            return 0;
        }
        ans *= r; 
    }
    cout << ans << endl;
    return 0;
}