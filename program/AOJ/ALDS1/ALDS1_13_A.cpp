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
#include <numeric>

using namespace std;
using ll = long long;

int main()
{
    int k;
    cin >> k;
    vector<int> a(k), b(k), num(8);
    vector<vector<char>> c(8, vector<char>(8, '.'));
    for(int i = 0; i < k; i++){
        cin >> a[i] >> b[i];
        c[a[i]][b[i]] = 'Q';
    }
    iota(num.begin(), num.end(), 0);
    do{
        bool ok = true;
        for(int i = 0; i < k; i++){
            if(b[i] != num[a[i]]){
                ok = false;
                break;
            }
        }
        if(ok){
            vector<vector<bool>> used(8, vector<bool>(8, false));
            bool ok2 = true;
            for(int i = 0; i < 8; i++){
                if(used[i][num[i]]){
                    ok2 = false;
                    break;
                }
                used[i][num[i]] = true;
            }
            if(ok2){
                cout << "num: ";
                for(int i = 0; i < 8; i++){
                    c[i][num[i]] = 'Q';
                    cout << num[i] << " ";
                }
                cout << endl;
                break;
            }
        }
    }while(next_permutation(num.begin(), num.end()));
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << c[i][j];
        }
        cout << endl;
    }
    return 0;
}