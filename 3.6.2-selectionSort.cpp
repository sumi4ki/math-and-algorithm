#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void Swap(int& l, int& r) {
    int tmp = l;
    l = r;
    r = tmp;
}

int main()
{
    vector<int> A(10, 0), B(10, 0);

    for(int i=0; i<A.size(); i++) {
        cin >> A[i];
        B[i] = A[i];
    }
    /* この方法は、スワップの回数が多い（最小値が更新されるたびに入れ替えてるから）*/
    /* 条件を満たすたびにswap. <- Exchange Sortというらしい
    /* 内側のループを j = 0 にすると 2021 年の論文（Stanley P.Y. Fungさん）と同じものになる https://arxiv.org/pdf/2110.01111*/
    for(int i=0; i<A.size() - 1; i++) {
        for(int j = i+1; j<A.size(); j++) {
            if(A[j] < A[i]) {
                int tmp;
                tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }

    /* 最小値が更新されてもスワップは行わず、最後に１回だけ行う <= これが本当の選択ソート*/
    for(int i=0; i<B.size() - 1; i++) {
        int min = B[i], minIndex = i;
        for(int j=i+1; j<B.size(); j++) {
            if(B[j] < min) {
                min = B[j];
                minIndex = j;
            }
        }
        Swap(B[i], B[minIndex]);
    }
    for(auto &a : A) cout << a << " ";
    cout << endl;
    for(auto &b : B) cout << b << " ";
    
    return 0;
}