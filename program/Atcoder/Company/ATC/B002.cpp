#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

long long n, m;

long long expo(long long p){
    if(p==1) return n % m;
    if(p == 0) return 1;
    
    if(p % 2 == 0){
        long long t = expo(p/2);
        return t * t % m;
    }else{
        long long t = expo(p-1);
        return n * t % m;
    }
}

int main()
{
    long long p;
    cin >> n >> m >> p;
    long long ans = expo(p);
    cout << ans << endl;
    return 0;
}