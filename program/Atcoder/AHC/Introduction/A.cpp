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
#include <time.h>
#include <random>

using namespace std;
using ll = long long;

int D;
int s[366][27];
int t[366], c[27], last[27];

ll score(int d, int q){
    t[d] = q;
    int ans = 0;
    for(int i = 1; i <= D; i++){
        ans += s[i][t[i]];
        int res = 0;
        last[t[i]] = i;
        for(int j = 1; j <= 26; j++){
            res += c[j]*(i-last[j]);
        }
        ans -= res;
    }
    return ans;
}

ll score(){
    int ans = 0;
    for(int i = 1; i <= D; i++){
        ans += s[i][t[i]];
        int res = 0;
        last[t[i]] = i;
        for(int j = 1; j <= 26; j++){
            res += c[j]*(i-last[j]);
        }
        ans -= res;
    }
    return ans;
}

int main()
{
    clock_t start = clock();
    const double T = 1.9;
    
    cin >> D;
    for(int i = 1; i <= 26; i++) cin >> c[i];
    for(int i = 1; i <= D; i++){
        for(int j = 1; j <= 26; j++) cin >> s[i][j];
    }
    for(int i = 1; i <= D; i++){
        t[i] = 1;
    }

    int ans = 0;
    for(int i = 1; i <= D; i++){
        ans += s[i][t[i]];
        int res = 0;
        last[t[i]] = i;
        for(int j = 1; j <= 26; j++){
            res += c[j]*(i-last[j]);
        }
        ans -= res;
    }
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<> randD(0, D-1);
    uniform_int_distribution<> randQ(0, 25);
    clock_t now = clock();
    while(((double)(now - start) / CLOCKS_PER_SEC) < T){
        uniform_int_distribution<> rand(0, 1);
        if(rand(mt)){
            int d = randD(mt)+1, q = randQ(mt)+1;
            for(int i = 1; i <= 26; i++) last[i] = 0;
            int old = t[d];
            t[d] = q;
            int new_score = score(d, q);
            if(new_score > ans){
                // clock_t update = clock();
                // cout << "Update!: " << (double)(update - start) / CLOCKS_PER_SEC << endl;
                ans = new_score;
            }
            else t[d] = old;
        }else{
            int d1 = randD(mt)+1;
            uniform_int_distribution<> randD2(((d1+1)%D)+1, min(((d1+1)%D)+16, D));
            int d2 = randD2(mt);
            cout << "d1: " << d1 << " " << d2 << endl;
            //cout << "t[d1]: " << t[d1] << " " << t[d2] << endl;
            swap(t[d1], t[d2]);
            //cout << "t[d1]: " << t[d1] << " " << t[d2] << endl;
            for(int i = 1; i <= 26; i++) last[i] = 0;
            int new_score = score();
            if(new_score > ans){
                ans = new_score;
            }
            else swap(t[d1], t[d2]);
        }
        now = clock();
    }
    for(int i = 1; i <= D; i++) cout << t[i] << endl;
    return 0;
}