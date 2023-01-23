#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define endl '\n'
#define fastio std::cin.tie(nullptr)->sync_with_stdio(false)

using namespace std;
typedef long long ll;

constexpr ll MOD = 1000000007;

map<ll, ll> f;
ll n, m;

ll fibo(ll n) {	
	if (n == 0) return 0;
	if (n == 1 || n == 2) return 1;
	if (f.count(n) > 0) return f[n];

	if (!(n & 1)) {
		ll m = n >> 1;
		ll tmp1 = fibo(m - 1), tmp2 = fibo(m);
		f[n] = ((2LL * tmp1 + tmp2) * tmp2) % MOD;
		return f[n];
	}
	ll m = (n + 1) >> 1;
	ll tmp1 = fibo(m), tmp2 = fibo(m - 1);
	f[n] = (tmp1 * tmp1 + tmp2 * tmp2) % MOD;
	return f[n];
}

int main(void) {

	fastio;

	cin >> n;
	cout << fibo(n);

	return false;
}