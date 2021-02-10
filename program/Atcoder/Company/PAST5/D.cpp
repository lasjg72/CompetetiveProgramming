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
    vector<pair<int, int>> p(n);
    for(int i = 0; i < n; i++){
        //cout << "ko" << endl;
        string s;
        cin >> s;
        //cout << "s: " << s << endl;
        int num = 0;
        while(s.size() > 0 && s[0] == '0'){
            num++;
            s.erase(0, 1);
        }
        if(s.size() == 0){
            p[i] = {0, 0};
        }else{
            int tmp = stoi(s);
            //cout << tmp << endl;
            p[i] = {tmp, num};
        }
    }
    sort(p.begin(), p.end());

    for(int i = 0; i < n; i++){
        for(int j = 0; j < p[i].second; j++){
            cout << '0';
        }
        cout << p[i].first << endl;
    }
    return 0;
}