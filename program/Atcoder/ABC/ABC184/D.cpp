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
    double a, b, c;
    cin >> a >> b >> c;
    if(a == 0 && b == 0){
        cout << 100-c << endl;
    }else if(a == 0 && c == 0){
        cout << 100 - b << endl;
    }else if(b == 0 && c == 0){
        cout << 100 - a << endl;
    }else{
        int saidai = 298-(a+b+c);
        int mx = max(max(a, b), c);
        int saishou = 100 - mx;
        double ans = 0;
        for(int i = saishou; i <= saidai; i++){
             
        }
    }
    return 0;
}