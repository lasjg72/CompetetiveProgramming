#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
    int h, a;
    cin >> h >> a;
    int ans = 0;
    if(h%a==0){
        ans = h/a;
    }else{
        ans = h/a + 1;
    }
    cout << ans << endl;
    return 0;
}
