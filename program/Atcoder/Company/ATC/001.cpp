#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

int gx, gy;
int h, w;
char c[500][500];
bool mark[500][500];

void dfs(int sx, int sy)
{
    if (sx == gx && sy == gy)
    {
        cout << "Yes" << endl;
        exit(0);
    }

    int x[4] = {1, 0, -1, 0};
    int y[4] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        if (sx + x[i] < h && sy + y[i] < w)
        {
            if (c[sx + x[i]][sy + y[i]] == '.' || c[sx + x[i]][sy + y[i]] == 'g')
            {
                if (mark[sx + x[i]][sy + y[i]] != true)
                {
                    //cout << "x:" << sx + x[i] << "y: " << sy + y[i] << endl;
                    mark[sx + x[i]][sy + y[i]] = true;
                    dfs(sx + x[i], sy + y[i]);
                }
            }
        }
    }
}

int main()
{
    cin >> h >> w;
    int sx, sy;
    //char c[h][w];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == 's')
            {
                sx = i;
                sy = j;
            }
            if (c[i][j] == 'g')
            {
                gx = i;
                gy = j;
            }
        }
    }

    dfs(sx, sy);

    cout << "No" << endl;
    return 0;
}