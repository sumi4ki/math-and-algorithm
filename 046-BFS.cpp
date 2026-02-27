#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

struct Point {
    int y;
    int x;
    Point() : y(0), x(0) {}
    Point(int y, int x) : y(y), x(x) {}
};

int main() {
    // 入力
    int H, W;
    cin >> H >> W;
    Point S, G;
    cin >> S.y >> S.x >> G.y >> G.x;
    S.y--; S.x--; G.y--; G.x--;

    vector<string> maze(H);
    for(int i=0; i<H; i++) cin >> maze[i];
    
    // 方向ベクトル
    vector<int> dy{-1, 0, 1, 0}, dx{0, 1, 0, -1};

    // 初期化
    vector<vector<int>> dist(H, vector<int>(W));
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            dist[i][j] = -1;
        }
    }
    queue<Point> Q;
    Q.push(S);
    dist[S.y][S.x] = 0;
    // BFS
    while(!Q.empty()) {
        // 先頭要素を調べて
        auto cur = Q.front();
        // 取り出す
        Q.pop();
        // 現在位置から4方向調べる
        for(int i=0; i<4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            
            // 範囲内か、壁でないか、未訪問かをチェック
            if(ny >= 0 && nx >= 0 && ny < H && nx < W) {
                if(maze[ny][nx] != '#') {
                    if(dist[ny][nx] == -1) {
                        dist[ny][nx] = dist[cur.y][cur.x] + 1;
                        Q.push(Point(ny, nx));
                    }
                }
            }
        }
    }
    
    // ゴール地点の dist が最小の手数になっている
    cout << dist[G.y][G.x];
    return 0;
}