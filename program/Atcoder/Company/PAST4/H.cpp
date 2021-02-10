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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> s(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            s[i][j] = c - '0';
        }
    }
    int mi = min(n, m);
    //cout << "mi: " << mi << endl;
    for(int i = mi; i >= 2; i--){
        //cout << "i: " << i << endl;
        for(int x = 0; x <= n-i; x++){
            for(int y = 0; y <= m-i; y++){
                map<int, int> num;
                priority_queue<int> q;
                for(int a = x; a < x+i; a++){
                    for(int b = y; b < y+i; b++){
                        //cout << "s[a][b]: " << s[a][b] << endl;
                        num[s[a][b]]++;
                    }
                    //cout << "-------" << endl;
                }
                for(auto tmp: num){
                    //cout << "tmp second " << tmp.second << endl;
                    q.push(tmp.second);
                }
                q.pop();
                int tmp = 0;
                while(!q.empty()){
                    int now = q.top(); q.pop();
                    tmp += now;
                }
                if(tmp <= k){
                    cout << i << endl;
                    return 0;
                }
            }
        }
    }
    cout << 1 << endl;
    return 0;
}   