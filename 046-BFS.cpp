#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int H, W;

struct Point {
    int y;
    int x;
    int val;
};

int main() {
    // 入力
    cin >> H >> W;
    vector<int> S(2), G(2);
    cin >> S[0] >> S[1] >> G[0] >> G[1];
    S[0]--; S[1]--; G[0]--; G[1]--;

    vector<string> maze(H);
    for(int i=0; i<H; i++) cin >> maze[i];
    
    // 初期化
    vector<Point> dist;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(maze[i][j] == '.') {
                dist.push_back(Point{i, j, -1});
            }
        }
    }
    queue<Point> Q;
    auto s = Point{S[0], S[1], 0};
    Q.push(s);
    
    // BFS
    while(!Q.empty()) {
        // 先頭要素を調べて
        Point p_cur = Q.front();
        // 取り出す
        Q.pop();
        
        // 現在位置
        vector<int> cur{p_cur.y, p_cur.x};
        // 現在位置から4方向調べる
        for(int dir=0; dir<4; dir++) {
            vector<int> nex;
            switch(dir) {
                case 0: // up
                    nex = {cur[0] - 1, cur[1]};
                    break;
                case 1: // right
                    nex = {cur[0], cur[1] + 1};
                    break;
                case 2: // down
                    nex = {cur[0] + 1, cur[1]};
                    break;
                case 3: // left
                    nex = {cur[0], cur[1] - 1};
            }
            // 到達可能かつ未訪問であるか調べる
            for(auto& d : dist) {
                // dist に nex の座標があれば、必ず床である
                if(nex[0] == d.y && nex[1] == d.x && d.val == -1) {
                    d.val = p_cur.val + 1;
                    Q.push(d);
                }
            }
        }
    }
    
    // ゴール地点の dist が最小の手数になっている
    for(const auto& d : dist) {
        if(d.y == G[0] && d.x == G[1]) cout << d.val << endl; // endl がないと通らない
        // cout << d.y << " " << d.x << " " << d.val << endl;
    }
    return 0;
}