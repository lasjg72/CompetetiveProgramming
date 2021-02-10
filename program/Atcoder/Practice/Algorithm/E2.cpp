#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;
using P = pair<int, int>;

int main()
{
    int n, m ,q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n, vector<int>(n, 0));
    vector<int> c(n,0);
    vector<vector<int>> s(q);
    for(int i = 0; i<m;i++){
        int u, v;
        cin >> u >> v;
        a[u-1][v-1] = 1;
        a[v-1][u-1] = 1;
    }
    for(int i = 0; i<n;i++){
        cin >> c[i];
    }
    for(int i =0; i< q;i++){
        int num;
        cin >> num;
        if(num == 1){
            s[i].push_back(num);
            int tmp;
            cin >> tmp;
            s[i].push_back(tmp);
        }else{
            s[i].push_back(num);
            int tmp;
            cin >> tmp;
            s[i].push_back(tmp);
            cin >> tmp;
            s[i].push_back(tmp);
        }
    }

    for(int i =0; i<q;i++){
        if(s[i][0] == 1){
            int vertex = s[i][1];
            cout << c[vertex-1] << endl;
            for(int j =0; j< n;j++){
                if(a[vertex-1][j] == 1){
                    c[j] = c[vertex-1];
                }
            }
        }else if(s[i][0] == 2){
            int vertex = s[i][1];
            int color = s[i][2];
            cout << c[vertex-1] << endl;
            c[vertex-1] = color;
        }
    }
    return 0;
}