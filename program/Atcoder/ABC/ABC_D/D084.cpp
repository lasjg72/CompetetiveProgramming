#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>

using namespace std;

bool is_Prime(int p)
{
    if (p == 0 || p == 1)
        return false;
    else if (p == 2)
        return true;
    else if (p % 2 == 0)
        return false;
    for (int i = 3; i * i <= p; i += 2)
    {
        if (p % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int q;
    cin >> q;
    vector<int> l(q), r(q);
    for (int i = 0; i < q; i++)
    {
        cin >> l[i] >> r[i];
    }
    vector<int> car(1e5, 0);
    int num = 0;
    for (int i = 3; i < 1e5; i += 2)
    {
        if (is_Prime(i) && is_Prime((i + 1) / 2))
        {
            num++;
        }
        car[i] = num;
    }
    for (int i = 0; i < q; i++)
    {
        if(is_Prime(l[i]) && is_Prime((l[i]+1)/2)){
            cout << car[r[i]] - car[l[i]] + 1 << endl;
        }else{
            cout << car[r[i]] - car[l[i]] << endl;
        }
    }
    return 0;
}