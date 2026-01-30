#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;

int main ()
{
    cin >> N;
    N++;

    vector<int> dp(N);
    for(int i=0; i<N; i++) {
        if(i==0) dp[i] = 0;
        if(i==1) dp[1] = 1;
        if(i==2) dp[i] = 2;
        if(i>=3) dp[i] = dp[i-2] + dp[i-1];
    }
    cout << dp[N-1];
    return 0;
}