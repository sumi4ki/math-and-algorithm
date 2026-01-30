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
        if(w[0] <= j) dp[0][j] = w[0];
    }
    // １行目　品物が 0, 1 で、
    for(int j=0; j<W; j++) {
        // 品物 1 が選べないときは、品物 0 までのdpから変化なし
        if(w[0] > j) dp[1][j] = dp[0][j];
        // 品物 1 が選べるときは、
        else {
            // pattern 1: 品物0, 1 を両方所持できる
            if()
            // pattern 2: 品物1 しか所持できない
        }
    }

    // 品物 i までで
    for(int i=0; i<N; i++) {
        // 重量は j まで
        for(int j=0; j<W; j++) {
            // 品物 i の重量が j 以下なら選択できる
            if(w[i] <= j) {
                dp[i][j] = 
            }
            dp[i][j] = 
        }
    }
    return 0;
}