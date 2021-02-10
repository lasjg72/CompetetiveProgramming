#include <iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

long long MX = 1e18;

int main()
{
    int n;
    long long a;
    cin >> n;
    long long ans =1;
    bool flag = false;
    for(int i = 0; i<n;i++){
        cin >> a;
        if(a==0){
            cout << 0 << endl;
            return 0;
        }
        if(flag || MX/ans < a){
            flag = true;
        }
        ans *= a;
    } 
    if(flag) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
