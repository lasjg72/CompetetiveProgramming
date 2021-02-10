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
    int a, b;
    cin >> a >> b;
    int min = b*10;
    int max = (b+1)*10;
    for(int i = min; i<max; i++){
            if(floor(i*0.08) == a){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}