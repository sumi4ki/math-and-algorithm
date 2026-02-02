#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, 
vector<int> A(200009), C(200009, 0);

void MergeSort(int l, int r) 
{

}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];

    MergeSort(0, N-1);

    return 0;
}