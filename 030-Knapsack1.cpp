#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, W;

int main ()
{
    cin >> N >> W;
    vector<int> w(N), v(N); // weight, value
    for(int i=0; i<N; i++) cin >> w[i] >> v[i];
       
    vector<vector<int>> dp(N, vector<int>(W, 0));

    // ０行目 品物が１つだから選択できるなら、選択した方がいい
    for(int j=0; j<W; j++) {
        if(w[0] <= j) dp[0][j] = v[0];
    }
    // １行目　品物が 0, 1 で、
    for(int j=0; j<W; j++) {
        // 品物 1 が選べないときは、品物 0 までのdpから変化なし
        if(w[0] > j) dp[1][j] = dp[0][j];
        // 品物 1 が選べるときは、
        else {
            // pattern 1: 品物1 しか所持できない
            if(W - w[1] < w[0]) {
                if(dp[0][j] < v[1]) {
                    dp[1][j] = v[1];
                }
                else {
                    dp[1][j] = dp[0][j];
                }
            }
            // pattern 2: 品物0, 1 を両方所持できる
            else {
                dp[1][j] = dp[0][j] + v[1];
            }
        }
    }
    // 2 行目　品物が 0,1,2で
    for(int j=0; j<W; j++) {
        // 品物 1 が選べないときは、品物 0 までのdpから変化なし
        if(w[2] > j) dp[2][j] = dp[1][j];
        // 品物 2 が選べるときは、
        else {
            if(dp[1][j] < v[2]) {
                dp[2][j] += v[2];
                j -= w[2];

            }
            // pattern 1: 品物2 しか所持できない
            if(W - w[1] < w[0]) {
                if(dp[0][j] < w[1]) {
                    dp[1][j] = w[1];
                }
                else {
                    dp[1][j] = dp[0][j];
                }
            }
            // pattern 2: 品物0, 1 を両方所持できる
            else {
                dp[1][j] = dp[0][j] + w[1];
            }
        }
    }
    
    
    return 0;
}