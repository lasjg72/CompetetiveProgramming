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
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a), q(b), r(c);
    for (int i = 0; i < a; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < b; i++)
    {
        cin >> q[i];
    }
    for (int i = 0; i < c; i++)
    {
        cin >> r[i];
    }
    sort(p.rbegin(), p.rend());
    sort(q.rbegin(), q.rend());
    sort(r.rbegin(), r.rend());

    vector<int> tmp(x + y + c);
    for (int i = 0; i < x; i++)
    {
        tmp[i] = p[i];
    }
    for (int i = x; i < x + y; i++)
    {
        tmp[i] = q[i - x];
    }
    for (int i = x + y; i < x + y + c; i++)
    {
        tmp[i] = r[i - x - y];
    }
    sort(tmp.rbegin(), tmp.rend());
    long long ans = 0;
    for(int i = 0; i < x+y;i++){
        //cout << tmp[i] << endl;
        ans += tmp[i];
    }
    cout << ans << endl;
    return 0;
}