#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>

using namespace std;

bool is_Prime(long long p)
{
    if(p < 2) return false;
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
    long long n;
    cin >> n;
    int num = 0;
    long long p = n;
    //vector<int> b(sqrt(n), 0);

    for (long long i = 2; i * i <= n; i++)
    {
        if (is_Prime(i) && p % i == 0)
        {
            //cout << p << endl;
            p = p / i;
            // cout << "p: " << p << endl;
            // cout << "num" << num << endl;
            num++;
            //b[i]++;
            if (p == 1)
            {
                break;
            }
        }
    }
    if (num == 0 && n != 1)
    {
        num = 1;
    }
    cout << num << endl;
    return 0;
}
