#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
vector<int> h(1E5);

int main ()
{
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> h[i];
    }
    vector<int> dp(N);

    // init
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);

    for(int i=2; i<N; i++) {
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]),
                    dp[i-2] + abs(h[i] - h[i-2]));
    }

    cout << dp[N-1];
    return 1;
}