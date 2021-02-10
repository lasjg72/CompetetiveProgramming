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
    int k;
    cin >> k;
    queue<long long> que;
    for(int i = 1; i < 10; i++) que.push(i);
    int num = 0;
    while(!que.empty()){
        long long now = que.front();
        que.pop();
        num++;
        if(num == k){
            cout << now << endl;
            return 0;
        }
        if(now%10 != 0){
            que.push(10*now + now%10 -1);
        }
        que.push(10 * now + now%10);
        if(now%10 != 9){
            que.push(10 * now + now%10 +1);
        }
    }
    return 0;
}