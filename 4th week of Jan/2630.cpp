// boj 2630 - 색종이 만들기

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define endl '\n'
#define fastio std::cin.tie(nullptr)->sync_with_stdio(false)

using namespace std;

int N;
int arr[200][200];
int dx[] = { 0,0,1,1 };
int dy[] = { 0,1,0,1 };
int ans[] = { 0,0 }; // W : 0, B : 1

bool monoTone(pair<int,int> pi, int len) {

    int x = pi.first, y = pi.second;

    int sum = 0;

    for (int i = x; i < x + len; ++i) for (int j = y; j < y + len; ++j) sum += arr[i][j];

    if (sum == 0) {
        ans[0]++;
        return false;
    }
    if (sum == len * len) {
        ans[1]++;
        return false;
    }

    return true;
}

void solve(pair<int,int> cord, int len) {

    int nL = len >> 1;
    if (nL == 0) return;

    for (int i = 0; i < 4; ++i) {
        pair<int, int> nC = { cord.first + dx[i] * nL, cord.second + dy[i] * nL };
        if (monoTone(nC, nL)) solve(nC, nL);
    }
}

int main() {

    fastio;
    cin >> N;

    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) cin >> arr[i][j];

    pair<int, int> cord = { 1, 1 };

    if (!monoTone(cord, N)) cout << ans[0] << endl << ans[1];
    else {
        solve(cord, N);
        cout << ans[0] << endl << ans[1];
    }
    return false;

}