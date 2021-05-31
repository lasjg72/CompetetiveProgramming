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
    int n;
    cin >> n;
    vector<vector<ll>> a(3);
    for(int i = 0; i < 2*n; i++){
        ll na;
        char c;
        cin >> na >> c;
        if(c == 'R'){
            a[0].push_back(na);
        }else if(c == 'G'){
            a[1].push_back(na);
        }else{
            a[2].push_back(na);
        }
    }
    int n1 = a[0].size(), n2 = a[1].size(), n3 = a[2].size();
    if(n1%2 == 0 && n2%2==0 && n3%2 == 0){
        cout << 0 << endl;
        return 0;
    }
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    sort(a[2].begin(), a[2].end());
    if(n1%2==0){
        ll tmp = 1001001001001001001, tmp2 = 1001001001001001001, tmp3 = 1001001001001001001;
        for(int i = 0; i < n2; i++){
            ll now = a[1][i];
            auto it = lower_bound(a[2].begin(), a[2].end(), now);
            int pos = it-a[2].begin();
            if(pos == n3){
                tmp = abs(now-a[2][pos-1]);
            }
            else if(pos == n3-1){
                tmp = min(abs(now-a[2][pos]), abs(now-a[2][pos-1]));
            }else if(pos == 0){
                tmp = abs(now-a[2][0]);
            }else{
                tmp = min(abs(now-a[2][pos]), abs(now-a[2][pos-1]));
                tmp = min(tmp, abs(now-a[2][pos+1]));
            }
        }
        if(n1 == 0){
            cout << tmp << endl;
            return 0;
        }
        for(int i = 0; i < n2; i++){
            ll now = a[1][i];
            auto it = lower_bound(a[0].begin(), a[0].end(), now);
            int pos = it-a[0].begin();
            if(pos == n1){
                tmp2 = abs(now-a[0][pos-1]);
            }
            else if(pos == n1-1){
                tmp2 = min(abs(now-a[0][pos]), abs(now-a[0][pos-1]));
            }else if(pos == 0){
                tmp2 = abs(now-a[0][pos]);
            }else{
                tmp2 = min(abs(now-a[0][pos]), abs(now-a[0][pos-1]));
                tmp2 = min(tmp2, abs(now-a[0][pos+1]));
            }
        }

        for(int i = 0; i < n3; i++){
            ll now = a[2][i];
            auto it = lower_bound(a[0].begin(), a[0].end(), now);
            int pos = it-a[0].begin();
            if(pos == n1){
                tmp3 = abs(now-a[0][pos-1]);
            }
            else if(pos == n1-1){
                tmp3 = min(abs(now-a[0][pos]), abs(now-a[0][pos-1]));
            }else if(pos == 0){
                tmp3 = abs(now-a[0][0]);
            }else{
                tmp3 = min(abs(now-a[0][pos]), abs(now-a[0][pos-1]));
                tmp3 = min(tmp3, abs(now-a[0][pos+1]));
            }
        }

        tmp = min(tmp, tmp2+tmp3);
        cout << tmp << endl;

    }else if(n2%2==0){
        ll tmp = 1001001001001001001, tmp2 = 1001001001001001001, tmp3 = 1001001001001001001;
        for(int i = 0; i < n1; i++){
            ll now = a[0][i];
            auto it = lower_bound(a[2].begin(), a[2].end(), now);
            int pos = it-a[2].begin();
            if(pos == n3){
                tmp = abs(now-a[2][pos-1]);
            }
            else if(pos == n3-1){
                tmp = min(abs(now-a[2][pos]), abs(now-a[2][pos-1]));
            }else if(pos == 0){
                tmp = abs(now-a[2][0]);
            }else{
                tmp = min(abs(now-a[2][pos]), abs(now-a[2][pos-1]));
                tmp = min(tmp, abs(now-a[2][pos+1]));
            }
        }
        if(n2 == 0){
            cout << tmp << endl;
            return 0;
        }
        for(int i = 0; i < n1; i++){
            ll now = a[0][i];
            auto it = lower_bound(a[1].begin(), a[1].end(), now);
            int pos = it-a[1].begin();
            if(pos == n2){
                tmp2 = abs(now-a[1][pos-1]);
            }
            else if(pos == n2-1){
                tmp2 = min(abs(now-a[1][pos]), abs(now-a[1][pos-1]));
            }else if(pos == 0){
                tmp2 = abs(now-a[1][0]);
            }else{
                tmp2 = min(abs(now-a[1][pos]), abs(now-a[1][pos-1]));
                tmp2 = min(tmp2, abs(now-a[1][pos+1]));
            }
        }

        for(int i = 0; i < n3; i++){
            ll now = a[2][i];
            auto it = lower_bound(a[1].begin(), a[1].end(), now);
            int pos = it-a[1].begin();
            if(pos == n2){
                tmp3 = abs(now-a[1][pos-1]);
            }
            else if(pos == n2-1){
                tmp3 = min(abs(now-a[1][pos]), abs(now-a[1][pos-1]));
            }else if(pos == 0){
                tmp3 = abs(now-a[1][0]);
            }else{
                tmp3 = min(abs(now-a[1][pos]), abs(now-a[1][pos-1]));
                tmp3 = min(tmp3, abs(now-a[1][pos+1]));
            }
        }

        tmp = min(tmp, tmp2+tmp3);
        cout << tmp << endl;
    }else{
        ll tmp = 1001001001001001001, tmp2 = 1001001001001001001, tmp3 = 1001001001001001001;
        for(int i = 0; i < n1; i++){
            ll now = a[0][i];
            auto it = lower_bound(a[1].begin(), a[1].end(), now);
            int pos = it-a[1].begin();
            if(pos == n2){
                tmp = abs(now-a[1][pos-1]);
            }
            else if(pos == n2-1){
                tmp = min(abs(now-a[1][pos]), abs(now-a[1][pos-1]));
            }else if(pos == 0){
                tmp = abs(now-a[1][0]);
            }else{
                tmp = min(abs(now-a[1][pos]), abs(now-a[1][pos-1]));
                tmp = min(tmp, abs(now-a[1][pos+1]));
            }
        }
        if(n3 == 0){
            cout << tmp << endl;
            return 0;
        }
        for(int i = 0; i < n1; i++){
            ll now = a[0][i];
            auto it = lower_bound(a[2].begin(), a[2].end(), now);
            int pos = it-a[2].begin();
            if(pos == n3){
                tmp2 = abs(now-a[2][pos-1]);
            }
            else if(pos == n3-1){
                tmp2 = min(abs(now-a[2][pos]), abs(now-a[2][pos-1]));
            }else if(pos == 0){
                tmp2 = abs(now-a[2][0]);
            }else{
                tmp2 = min(abs(now-a[2][pos]), abs(now-a[2][pos-1]));
                tmp2 = min(tmp2, abs(now-a[2][pos+1]));
            }
        }
        //cout << "tmp2: " << tmp2 << endl;
        for(int i = 0; i < n2; i++){
            ll now = a[1][i];
            //cout << "now" << now << endl;
            auto it = lower_bound(a[2].begin(), a[2].end(), now);
            int pos = it-a[2].begin();
            //cout << "pos: " << pos << endl;
            if(pos == n3){
                tmp3 = abs(now-a[2][pos-1]);
            }
            else if(pos == n3-1){
                tmp3 = min(abs(now-a[2][pos]), abs(now-a[2][pos-1]));
            }else if(pos == 0){
                tmp3 = abs(now-a[2][0]);
            }else{
                tmp3 = min(abs(now-a[2][pos]), abs(now-a[2][pos-1]));
                tmp3 = min(tmp3, abs(now-a[2][pos+1]));
            }
        }
        // cout << tmp3 << endl;
        // cout << "tmp: " << tmp << " tmp2+tmp3: " << tmp2+tmp3 << endl;
        tmp = min(tmp, tmp2+tmp3);
        cout << tmp << endl;
    }
    return 0;
}