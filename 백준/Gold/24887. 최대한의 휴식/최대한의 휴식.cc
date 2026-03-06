
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

ll v[200005];
int n, m;


bool solve(int x)
{
	vector<ll> dp(n); // i일에 일한다고 했을때 최소 x일씩 쉬면서 할 수 있는 일의 양의 최대값
	ll mxdp = 0;
	for (int i = 0; i < n; i++)
	{
		if (i - x - 1 >= 0) // 만약 x일 쉬고 오늘 일하는 경우
		{
			mxdp = max(mxdp, dp[i - x - 1]); // x일 쉬고 그 이전 날짜들 중에 할 수 있는 일의 최대값
		}
		dp[i] = mxdp + v[i]; // 그값에 오늘 일하는 양을 추가
	}

	for (int i = 0; i < n; i++)
	{
		if (dp[i] >= m)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	ll total = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		if (v[i] >= m)
		{
			cout << "Free!";
			return 0;
		}
		total += v[i];
	}
	if (total < m)
	{
		cout << -1;
		return 0;
	}

	int st = 0;
	int en = n - 1;
	while (st + 1 < en)
	{
		int mid = (st + en) / 2;
		if (solve(mid))
		{
			st = mid;
		}
		else
		{
			en = mid;
		}
	}

	cout << st;

	return 0;
}
