#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M), dist(M);
    vector<vector<int>>  G(M,vector<int>(M));
    for(int i=0; i<M; i++) {
        cin >> A[i] >> B[i];
        G[A[i]][i] = B[i];
        G[B[i]][i] = A[i];
    }

    // 幅優先探索の初期化（dist[i] = -1 のとき、未到達の白色頂点
    for(int i = 0; i <= N; i++) dist[i] = -1;
    queue<int> Q;
    Q.push(1); dist[1] = 0;     // Q に 1 を追加(操作1)

    // BFS 
    while(!Q.empty()) {
        int pos = Q.front();   // 先頭要素を調べる (操作 2)
        Q.pop();    // Q の先頭要素を取りだす (操作 3)
        // 隣接かつ未訪問の点のdistを現在のdist + 1 で更新してキューに入れる
        for(int i=0; i<(int)G[pos].size(); i++) {
            int nex = G[pos][i];
            if(dist[nex] == -1) {
                dist[nex] = dist[pos] + 1;
                Q.push(nex);    // Q に nex を追加（操作1)
            }
        }
    }

    // 頂点 1 から各頂点までの最短距離を出力
    for(int i = 1; i<=N; i++) cout << dist[i] << endl;
}