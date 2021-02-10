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
    int n, m;
    cin >> n >> m;
    vector<pair<bool,int>> cor(n, {false, 0});

    int ac = 0, wa = 0;
    auto cnt = [&](int i, string s){
        if(s == "AC" && !cor[i-1].first){
            ac++;
            wa += cor[i-1].second;
            cor[i-1].first = true;
        }
        else if (s == "WA" && !cor[i-1].first){
            cor[i-1].second++;
        }
    };
    int p;
    string s;
    for(int i = 0; i< m;i++){
        cin >> p >> s;
        cnt(p, s);
    }

    cout << ac << " " << wa << endl;

    return 0;
}