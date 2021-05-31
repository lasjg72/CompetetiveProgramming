#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>

using namespace std;
using ll = long long;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }
    vector<int> x, y;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w-1; j++){
            //cout << "a[i][j]: " << a[i][j] << endl;
            if(a[i][j]%2){
                x.push_back(i+1);
                y.push_back(j+1);
                x.push_back(i+1);
                y.push_back(j+2);
                a[i][j+1]++;
                a[i][j]--;
            }
        }
    }
    for(int i = 0; i < h-1; i++){
        if(a[i][w-1]%2){
            x.push_back(i+1);
            y.push_back(w);
            x.push_back(i+2);
            y.push_back(w);
            a[i+1][w-1]++;
            a[i][w-1]--;
        }
    }
    cout << x.size()/2 << endl;
    for(int i = 0; i < x.size(); i += 2){
        cout << x[i] << " " << y[i] << " " << x[i+1] << " " << y[i+1];
        cout << endl;
    }
    return 0;
}