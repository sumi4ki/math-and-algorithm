#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, W;

int main ()
{
    cin >> N >> W;
    vector<int> w(N+1, 0), v(N+1, 0); // weight, value
    // dpテーブルは、品物を選ばない i = 0 も必要。ナップザックは0オリジンじゃない
    for(int i=1; i<N+1; i++) cin >> w[i] >> v[i];
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));

    // 0 行目の初期化
    dp[0][0] = 0;
    for(int j=1; j<W+1; j++) dp[0][j] = -(1 << 10);

    for(int i = 1; i < N+1; i++) {
        for(int j = 0; j < W+1; j++) {
        
            // 重さ j に満たないなら、選べないから前の行と同じ
                    // ※ ここの条件文の向き、間違えて40分消えたから注意
            if(j < w[i]) dp[i][j] = dp[i-1][j];
            // 重さが j 以上なら、商品 i を選ぶか選ばないかを判定する
            if(j >= w[i]) {
                // 漸化式 （前の行の重さjの価値）　と　（前の行の重さj-w[i]の時の価値+v[i] の比較）
                        // つまり、商品 i を追加したときに「なかった時（前の行）より価値が増えるなら追加する」
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }

    // 答えの出力
    int ans = 0;
    for(int i=0; i<W+1; i++) ans = max(ans, dp[N][i]);
    cout << ans;
    
    return 0;
    
}