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
    int h, w, k;
    cin >> h >> w >> k;
    // vector<vector<int>> s(h, vector<int>(w));
    // for(int i = 0; i < h; i++){
    //     for(int j = 0; j < w; j++){
    //         cin >> s[i][j];
    //     }
    // }
    vector<string> s(h);
    for(int i = 0; i < h; i++){
        cin >> s[i];
    }
    int ans = 1001001001;
    for(int bit = 0; bit < (1<<h-1); bit++){
        int groupId = 0;
        vector<int> id(h);
        for(int i = 0; i < h; i++){
            id[i] = groupId;
            if(bit>>i&1) groupId++;
        }
        groupId++;
        vector<vector<int>> a(groupId, vector<int>(w, 0));
        int tmp = groupId-1;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                a[id[i]][j] += (s[i][j]-'0');
            }
        }
        vector<int> num(groupId, 0);
        for(int i = 0; i < w; i++){
            for(int j = 0; j < groupId; j++){
                num[j] += a[j][i];
            }
            for(int j = 0; j < groupId; j++){
                if(num[j] > k){
                    tmp++;
                    num = vector<int>(groupId, 0);
                    for(int l = 0; l < groupId; l++){
                        num[l] += a[l][i];
                    }
                    for(int l = 0; l < groupId; l++){
                        if(num[l] > k){
                            tmp = 1001001001;
                            break;
                        }
                    }
                }
            }
        }
        //cout << "tmp: " << tmp << endl;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}