#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> l(q), r(q);
    for (int i = 0; i < q; i++)
    {
        cin >> l[i] >> r[i];
    }
    vector<int> car(s.size(), 0);
    int num = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i - 1] == 'A' && s[i] == 'C')
        {
            num++;
        }
        car[i] = num;
    }

    for(int i = 0; i<q;i++){
        cout << car[r[i]-1] - car[l[i]-1] << endl;
    }
    return 0;
}