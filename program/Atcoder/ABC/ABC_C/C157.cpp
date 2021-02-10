#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n, m, s, c;
    cin >> n >> m;
    vector<pair<int, bool>> t(n, {0, false});
    for (int i = 0; i < m; i++)
    {
        cin >> s >> c;
        if (t[s - 1].second == false)
        {
            t[s - 1] = {c, true};
        }else if(t[s-1].first == c){
            continue;
        }else{
            cout << -1 << endl;
            exit(0);
        }
    }
    if(t[0].second == false && t.size() != 1) t[0].first = 1;

    if(t.size() != 1 && t[0].first == 0){
        cout << -1 << endl;
    }else{
        for(int i =0; i<n;i++){
            cout << t[i].first;
        }
        cout << endl;
    }
    return 0;
}