#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
 
using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;
    map<int, int> p;
    int tmp =0;
    for(int i =0; i< n; i++){
        cin >> tmp;
        p[tmp]++;
    }

    int ans = 1001001001;
    for(int i = 0; i< n+1; i++){
        if(p[x+i] == 0){
            ans = min(ans, x +i);
        }
        
        if(p[x-i] == 0){
            ans = min(ans,x-i);
        }

        if(ans < 1001001001){
            cout << ans << endl;
            exit(0);
        }
    }

    return 0;
}