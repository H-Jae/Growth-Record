#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(nullptr)->sync_with_stdio(false);

using namespace std;

const int R = 1e6;
int n;
pair<int, int> idx[R + 1];
vector<int>dp(2 * R + 5);

int main() {

	fastio;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int v, k;
		cin >> v >> k;
		idx[i].second = v ? 1 : -1;
		idx[i].first = k;
	}

	fill(dp.begin(), dp.end(), -1);
	sort(idx + 1, idx + n + 1);

	int sum = 0, ans = 0;

	dp[R] = 0;

	for (int i = 1; i <= n; ++i) {
		sum += idx[i].second;
		int& x = dp[R + sum];
		if (x == -1) x = i;
		else ans = max(ans, idx[i].first - idx[x + 1].first);
	}
	cout << ans;

	return false;
}