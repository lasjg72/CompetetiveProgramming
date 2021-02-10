#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;
char map[10][10] = {'x'};
bool mark[10][10] = {false};
int num = 0;
int car;
bool flag = false;

bool dfs(int x, int y)
{
    //cout << "car: " << car << endl;
    int tox[4] = {1, 0, -1, 0};
    int toy[4] = {0, 1, 0, -1};
    // cout << "x: " << x << "y: " << y << endl;
    // cout << mark[x][y] << endl;
    if (map[x][y] == 'x')
    {
        //cout << "not enter" << endl;
        return false;
    }
    if (car == num+1)
    {
        flag = true;
        return true;
    }

    for (int i = 0; i < 4; i++)
    {
        if (x + tox[i] >= 0 && y + toy[i] >= 0 && x + tox[i] < 10 && y + toy[i] < 10)
        {
            if (map[x + tox[i]][y + toy[i]] == 'o' && !(mark[x + tox[i]][y + toy[i]]))
            {
                car++;
                mark[x + tox[i]][y + toy[i]] = true;
                dfs(x + tox[i], y + toy[i]);
            }
        }
    }
    return false;
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'o')
                num++;
        }
    }
    //cout << num << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            car = 0;
            if (map[i][j] == 'x')
            {
                map[i][j] = 'o';
                //mark[i][j] = true;
                dfs(i, j);
                if (flag)
                {
                    cout << "YES" << endl;
                    exit(0);
                }
                map[i][j] = 'x';
                for(int k = 0; k<10; k++){
                    for(int l = 0; l<10; l++){
                        mark[k][l] = false;
                    }
                }
                //bool mark[10][10] = {false};
            }
            
        }
    }
    cout << "NO" << endl;
    return 0;
}