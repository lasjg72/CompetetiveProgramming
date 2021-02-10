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
    long long n, m, q;
    cin >> n >> m >> q;
    //cin.ignore();
    vector<string> s(q);
    // for(long long i = 0; i<q;i++){
    //     getline(cin, s[i]);
    // }

    vector<vector<long long>> score(n+1, vector<long long>()); // push_back problems are solved
    vector<long long> num(m+1, n); // #problems are solved

vector<long long> ans2;
    int a;
    long long person, problem;
    for(long long i = 0 ; i< q; i++){
        cin >> a;
        //cout << "a: " << a << endl;
        //if(s[i][0] == '1'){
        if(a == 1){
            long long ans = 0;
            //long long person = s[i][2] - '0';
            cin >> person;

            for(int j =0; j<score[person].size();j++){
                ans += num[score[person][j]];
            }
            //cout << ans << endl;
            ans2.push_back(ans);
        //}else if(s[i][0] == '2'){
        }else if(a == 2){
            //long long person = s[i][2]-'0';
            //long long problem = s[i][4]-'0';

            cin >> person >> problem;

            num[problem]--;
            score[person].push_back(problem);
        }
    }

    for(int i =0; i < ans2.size(); i++){
        cout << ans2[i] << endl;
    }
    return 0;
}