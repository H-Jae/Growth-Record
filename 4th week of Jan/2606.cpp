#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define endl '\n'
#define fastio std::cin.tie(nullptr)->sync_with_stdio(false)

using namespace std;

constexpr int N = 1e2;
int n, k;
bool node[N + 2];
vector<pair<int, int>> edge;

void dfs(int cx) {

	if (node[cx] == true) return;

	node[cx] = true;

	for (auto x : edge) if (x.first == cx) dfs(x.second);

	return;
}

int main() {

	fastio;

	cin >> n >> k;
	
	for (int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
		edge.push_back({ x, y });
		edge.push_back({ y,x });
	}

	dfs(1);

	int ans = -1;

	for (auto x : node) if (x) ans++;

	cout << ans;

	return false;
}