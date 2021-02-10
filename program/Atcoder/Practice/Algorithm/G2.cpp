#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

int n, X, Y;
int mX = 0, mY = 0;
vector<vector<int>> path(401, vector<int>(401, -1));
int ans = 1001001001;
bool flag = true;

int dfs(int x, int y, int num)
{
    cout << "num: " << num << endl;
    if (x == X && y == Y)
    {
        flag = false;
        ans = min(ans, num);
        return ans;
    }
    vector<int> moveX = {1, 0, -1, 1, -1, 0};
    vector<int> moveY = {1, 1, 1, 0, 0, -1};
    num++;
    for (int i = 0; i < 6; i++)
    {
        if (x + moveX[i] >= 0 && x + moveX[i] <= 2 * mX && y + moveY[i] >= 0 && y + moveY[i] <= 2 * mY)
        {
            if (path[x + moveX[i]][y + moveY[i]] == -1)
            {
                cout << "path: " << x + moveX[i] << y + moveY[i] << endl;
                path[x + moveX[i]][y + moveY[i]] = 0;
                dfs(x + moveX[i], y + moveY[i], num);
            }
        }
    }
    if(flag) return -1;
    else return min(ans, 1001001001);
}

int main()
{
    cin >> n >> X >> Y;
    mX = max(mX, abs(X));
    mY = max(mY, abs(Y));
    //X = X + 200;
    //Y = Y + 200;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        mX = max(mX, abs(x[i]));
        mY = max(mY, abs(y[i]));
        //x[i] = x[i] + 200;
        //y[i] = y[i] + 200;
        //path[x[i]][y[i]] = 0;
    }
    cout << "mx" << mX << mY << endl;
    X = X + mX;
    Y = Y + mY;
    for (int i = 0; i < n; i++)
    {
        path[x[i] + mX][y[i] + mY] = 0;
    }

    dfs(mX, mY, 0);
    cout << ans << endl;

    return 0;
}