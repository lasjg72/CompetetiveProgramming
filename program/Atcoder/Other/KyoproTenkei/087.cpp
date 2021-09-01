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

const int INF = 1001001001;


int main()
{
    int n, p, K;
    cin >> n >> p >> K;
    vector<vector<ll>> a(n, vector<ll>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    ll r = 5000000000LL, l = 1;
    ll tar = 5000000000LL;
    for(int num = 0; num < 40; num++){
        vector<vector<ll>> dist(n, vector<ll>(n, INF));
        ll now = (l+r)/2;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] == -1) dist[i][j] = now;
                else dist[i][j] = a[i][j];
            }
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(dist[i][j] <= p) cnt++;
            }
        }
        //cout << "cnt: " << cnt << endl;
        if(cnt <= K){
            r = now;
            tar = min(tar, now);
        }//else if(cnt < K) r = now;
        else l = now; 
        //cout << "l: " << l << " r: " << r << endl;
    }
    //cout << "--- part2 ---" << endl;
    l = 1; r = 5000000000LL;
    ll tar2 = 5000000000LL;
    for(int num = 0; num < 40; num++){
        vector<vector<ll>> dist(n, vector<ll>(n, INF));
        ll now = (l+r)/2;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] == -1) dist[i][j] = now;
                else dist[i][j] = a[i][j];
            }
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(dist[i][j] <= p) cnt++;
            }
        }
        //cout << "cnt: " << cnt << endl;
        if(cnt <= K-1){
            r = now;
            tar2 = min(tar2, now);
        }//else if(cnt < K-1) r = now;
        else l = now; 
        //cout << "l: " << l << " r: " << r << endl;
    }
    if(tar2-tar >= 2000000001LL) cout << "Infinity" << endl;
    else cout << tar2-tar << endl;
    return 0;
}