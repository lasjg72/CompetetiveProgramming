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
    int n, q;
    cin >> n;
    cin >> q;
    cin.ignore();
    vector<vector<char>> a(n, vector<char>(n, 'N'));
    vector<string> s(q);
    for (int i = 0; i < q; i++)
    {
        getline(cin, s[i]);
    }

    for (int i = 0; i < q; i++)
    {
        if (s[i][0] == '1')
        {
            a[(s[i][2] - '0') - 1][(s[i][4] - '0') - 1] = 'Y';
        }
        else if (s[i][0] == '2')
        {
            int c = s[i][2] - '0';
            for (int j = 0; j < n; j++)
            {
                if (a[j][c - 1] == 'Y')
                {
                    a[c - 1][j] = 'Y';
                }
            }
        }
        else if (s[i][0] == '3')
        {
            vector<int> tmp(6, 0);
            int c = s[i][2] - '0';
            for (int j = 0; j < n; j++)
            {
                if (a[c - 1][j] == 'Y')
                {
                    tmp[j]++;
                }
            }

            for (int j = 0; j < n; j++)
            {
                if (tmp[j] != 0)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (a[j][k] == 'Y')
                        {
                            a[c - 1][k] = 'Y';
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}