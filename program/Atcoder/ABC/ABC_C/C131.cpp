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

ll gcd(ll a, ll b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}

int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll divc, divd;
    if(a%c == 0) divc = ((b-b%c)-(a-a%c))/c +1;
    else divc = ((b-b%c)-(a-a%c+c))/c +1;
    if(a%d == 0) divd = ((b-b%d)-(a-a%d))/d +1;
    else divd = ((b-b%d)-(a-a%d+d))/d +1;
    ll num = 1, tmp = c;
    // while(c % d != 0){
    //     num++;
    //     c = tmp * num;
    // }
    gcd(c, d);
    c = lcm(c, d);
    ll div;
    //cout << "gcd: " << c << endl;
    if(a%d == 0) div = ((b-b%c)-(a-a%c))/c +1;
    else div = ((b-b%c)-(a-a%c+c))/c +1;
    //cout << "div: " << div << endl;
    cout << (b-a+1) - (divc + divd - div) << endl;
    return 0;
}