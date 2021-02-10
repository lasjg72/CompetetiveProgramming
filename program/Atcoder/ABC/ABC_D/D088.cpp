#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;
char s[50][50];
int value[50][50];
bool mark[50][50];

int main()
{
    int h, w;
    cin >> h >> w;
    int num = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> s[i][j];
            value[i][j] = 1001001001;
            mark[i][j] = false;
            if (s[i][j] == '#')
                num++;
        }
    }

    queue<pair<int, int>> que;
    int x = 0, y = 0;
    value[0][0] = 0;
    que.push({x, y});

    int sx[4] = {1, 0, -1, 0};
    int sy[4] = {0, 1, 0, -1};

    while (!que.empty())
    {
        pair<int, int> now = que.front();
        que.pop();
        x = now.first;
        y = now.second;
        for (int i = 0; i < 4; i++)
        {
            if (x + sx[i] < h && 0 <= x + sx[i] && y + sy[i] < w && 0 <= y + sy[i])
            {
                if (mark[x+sx[i]][y+sy[i]]==false && s[x + sx[i]][y + sy[i]] == '.')
                {
                    mark[x+sx[i]][y+sy[i]]=true;
                    //cout << value[x+sx[i]][y+sy[i]] << endl;
                    value[x+sx[i]][y+sy[i]] = min(value[x+sx[i]][y+sy[i]], value[x][y]+1);
                    //cout << value[x+sx[i]][y+sy[i]] << endl;
                    que.push({x+sx[i], y+sy[i]});
                }
            }
        }
    }

    if(value[h-1][w-1] == 1001001001){
        cout << -1 << endl;
        return 0;
    }

        int ans = h * w - (value[h - 1][w - 1] + 1) - num;

        cout << ans << endl;
        return 0;
}