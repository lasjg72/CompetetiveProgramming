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
    int n;
    long long d;
    cin >> n >> d;

    int tw = 0, th = 0, fi = 0;
    while (d != 1)
    {
        if (d % 2 == 0)
        {
            tw++;
            d /= 2;
            continue;
        }
        else if (d % 3 == 0)
        {
            th++;
            d /= 3;
            continue;
        }
        else if (d % 5 == 0)
        {
            fi++;
            d /= 5;
            continue;
        }
    }
    cout << "tw: " << tw << endl;
    cout << "th: " << th << endl;
    cout << "fi: " << fi << endl;
    double dp[n + 1][tw + 1][th + 1][fi + 1];

    int x, y, z;
for(int i = 0; i< n+1; i++){
    for (int j = 0; j < fi+1; j++)
        {
            for (int k = 0; k < th+1; k++)
            {
                for (int l = 0; l < tw+1; l++)
                {   
                    if(i == 0)
                    dp[i][l][k][j] = 1;
                    else dp[i][l][k][j] = 0;
                }
            }
        }
}

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < fi+1; j++)
        {
            for (int k = 0; k < th+1; k++)
            {
                for (int l = 0; l < tw+1; l++)
                {
                    cout << "i: " << i << endl;

                    dp[i + 1][l][k][j] += dp[i][l][k][j] / 6;
                    cout << "1: " << dp[i + 1][l][k][j] << endl;

                    dp[i + 1][l + 1][k][j] += dp[i][l][k][j] / 6;
                    cout << "2: " << dp[i + 1][l+1][k][j] << endl;

                    dp[i + 1][l + 1][k + 1][j] += dp[i][l][k][j] / 6;
                    cout << "3: " << dp[i + 1][l+1][k+1][j] << endl;

                    dp[i + 1][l + 2][k][j] += dp[i][l][k][j] / 6;
                    cout << "4: " << dp[i + 1][l+2][k][j] << endl;

                    dp[i + 1][l][k + 1][j] += dp[i][l][k][j] / 6;
                    cout << "5: " << dp[i + 1][l][k+1][j] << endl;

                    dp[i + 1][l][k][j + 1] += dp[i][l][k][j] / 6;
                    cout << "6: " << dp[i + 1][l][k][j+1] << endl;
                }
            }
        }
    }

    cout << dp[n][tw][th][fi] << endl;
    return 0;
}