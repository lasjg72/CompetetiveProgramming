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

int edit_distance_dp(const string& str1, const string& str2)
    {
        static int d[1000][1000];

        for (int i = 0; i < str1.size() + 1; i++) d[i][0] = i;
        for (int i = 0; i < str2.size() + 1; i++) d[0][i] = i;
        for (int i = 1; i < str1.size() + 1; i++)
            for (int j = 1; j < str2.size() + 1; j++)
                d[i][j] = min(min(d[i-1][j], d[i][j-1]) + 1, d[i-1][j-1] + (str1[i-1] == str2[j-1] ? 0 : 1));

        return d[str1.size()][str2.size()];
    }

int main()
{
   int n, m;
   cin >> n >> m;
//    vector<int> a(n), b(m);
//    for(int i = 0; i < n; i++){
//        cin >> a[i];
//    }
//    for(int i = 0; i < m; i++){
//        cin >> b[i];
//    }
    string a, b;
    cout << edit_distance_dp(a, b) << endl;;
   return 0;
}