// boj 12865 - 평범한 배낭

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define endl '\n'
#define fastio std::cin.tie(nullptr)->sync_with_stdio(false)

using namespace std;
typedef pair<int, int> pi;

int n, k;
pi obj[101];
int arr[101][100001];


int main() {

    fastio;
    
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> obj[i].first >> obj[i].second;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            arr[i][j] = arr[i - 1][j];
            if (obj[i].first <= j) arr[i][j] = max(obj[i].second + arr[i - 1][j - obj[i].first], arr[i][j]);
        }
    }
    cout << arr[n][k];

    return false;
}