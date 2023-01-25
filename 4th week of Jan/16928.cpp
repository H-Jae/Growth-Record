#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define endl '\n'
#define fastio std::cin.tie(nullptr)->sync_with_stdio(false)

using namespace std;

int n, m;
int u, v;
int ans;
int Move[102];
queue<int>q;
int cnt[102];

int main() {

	fastio;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> u >> v;
		Move[u] = v;
	}

	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		Move[u] = v;
	}

	q.push({ 1 });
	

	fill(cnt, cnt + 102, -1);

	cnt[1] = 0;

	while (!q.empty()) {

		int cur = q.front();
		
		q.pop();

		for (int i = 1; i <= 6; ++i) {
			int next = cur + i;
			if (next > 100) continue;
			
			if (Move[cur]) {
				q.push(Move[cur]);
				cnt[Move[cur]] = cnt[cur];
				break;
			}
			
			if (cnt[next] == -1) {
				q.push({ cur + i });
				cnt[next] = cnt[cur] + 1;
			}
			else if (cnt[next] > cnt[cur] + 1) {
				q.push({ cur + i });
				cnt[next] = cnt[cur] + 1;
			}
		}
	//	cout << cur << " " << cnt[cur] << endl;
	}

	cout << cnt[100];

	return false;
}