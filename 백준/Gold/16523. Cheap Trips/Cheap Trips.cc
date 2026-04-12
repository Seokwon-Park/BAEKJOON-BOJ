#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

pii v[10005];

double dp[10005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int t, c;
		cin >> t >> c;
		v[i] = { t,c };
	}
	fill(dp, dp + n + 5, INF);
	dp[0] = 0.0;

	//1번째 여행을 할때 6번까지 환승이 되는지 확인해서 dp테이블 갱신
	for (int i = 1; i <= n; i++)
	{
		auto [t, c] = v[i];

		int curt = 0;
		double curc = 0.0;
		for (int j = 0; j < 6 && i + j <= n; j++)
		{
			curt += v[i + j].first;
			if (j == 0)
				curc += v[i + j].second;
			else if (j == 1)
				curc += v[i + j].second * 0.5;
			else
				curc += v[i + j].second * 0.25;

			dp[i + j] = min(dp[i + j], dp[i - 1] + curc);

			if (curt >= 120)
				break;
		}
	}

	cout << fixed << setprecision(2) << dp[n] << '\n';

	return 0;
}