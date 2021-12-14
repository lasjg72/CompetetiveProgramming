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
    ll k;
    string a, b;
    cin >> k >> a >> b;
    ll na = 0, nb = 0, tmp = 1;
    for(int i = a.size()-1; i >= 0; i--){
        na += (a[i]-'0')*tmp;
        tmp *= k;
    }
    tmp = 1;
    for(int i = b.size()-1; i >= 0; i--){
        nb += (b[i]-'0')*tmp;
        tmp *= k;
    }
    cout << na*nb << endl;
    return 0;
}