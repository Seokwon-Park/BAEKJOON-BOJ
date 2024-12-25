#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	double s;
	cin >> n >> s >> k;
	int cur = 1;
	double ans = 0.0f;
	for (int i = 0; i < k; i++)
	{
		int m;
		double l;
		cin >> m >> l;
		ans += ((m - cur) * 4.0) / (s / 60.0f);
		cur = m;
		s = l;
	}
	ans += ((n - cur+1) * 4.0) / (s / 60.0f);

	cout << fixed << setprecision(12);
	cout << ans;

	return 0;
}