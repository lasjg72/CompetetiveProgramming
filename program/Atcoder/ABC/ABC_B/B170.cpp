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
    int x, y, kame = 0;
    int total = 0;
    cin >> x >> y;
    if(y%2 != 0){
        cout << "No" << endl;
        exit(0);
    }
    if(y-2*x < 0){
        cout << "No" << endl;
        exit(0);
    }
    kame = (y- 2 * x)/2;
    if(x-kame>=0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}