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
    string s;
    cin >> s;
    string t = "";
    for(int i = 0; i < n; i++){
        char c = s[i];
        if(t.size() == 0){
            t.push_back(c);
            continue;
        }
        int j = 0;
        while(t.size() > j){
            if(t[j] == c){
                t.erase(j, 1);
                //cout << "erase: " << t << endl;
                continue;
            }
            j++;
        }
        t.push_back(c);
        //cout << t << endl;
    }
    cout << t << endl;
    return 0;
}