// BOJ 2447 별찍기 - 10
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define endl '\n'
#define fastio std::cin.tie(nullptr)->sync_with_stdio(false)

using namespace std;

int n;

void solve(int i, int j, int n)
{
    if ((i / n) % 3 == 1 && (j / n) % 3 == 1) {
        cout << ' ';
    }
    else {
        if (n / 3 == 0)
            cout << '*';
        else
            solve(i, j, n / 3);
    }
}
int main() {

    fastio;

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) solve(i, j, n);
        cout << endl;
    }
}