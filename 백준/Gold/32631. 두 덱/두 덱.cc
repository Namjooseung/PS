#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

using i64 = long long;

auto get_dp = [](int n, const auto& p) {
	vector dp(n + 1, 1LL << 60);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			i64 val = p[j] - p[i - 1];
			dp[j - i + 1] = min(dp[j - i + 1], val);
		}
	}
	return dp;
};

int main() {
	fastio;
	int n, k; cin >> n >> k;
	vector a(n + 1, 0LL), b(n + 1, 0LL);
	for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
	for (int i = 1; i <= n; i++) cin >> b[i], b[i] += b[i - 1];
	a = get_dp(n, a);
	b = get_dp(n, b);
	i64 res = 1LL << 60;
	for (int i = 0; i <= n; i++) {
		int j = 2 * n - k - i;
		if (j < 0 || j > n) continue;
		res = min(res, max(a[i], b[j]));
	}
	cout << res << '\n';
}