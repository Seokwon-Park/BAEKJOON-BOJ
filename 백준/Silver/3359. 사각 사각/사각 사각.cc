#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int dp[1005][2]; // a쪽으로 눕히고 시작하는 경우, b쪽으로 눕히고 시작하는 경우

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pii> v(n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v[i] = { a,b };
	}

	dp[0][0] = v[0].first;
	dp[0][1] = v[0].second;



	for (int i = 1; i < n; i++)
	{
		dp[i][0] = max(dp[i - 1][0] + abs(v[i - 1].second - v[i].second), dp[i - 1][1] + abs(v[i - 1].first - v[i].second)) + v[i].first;
		dp[i][1] = max(dp[i - 1][0] + abs(v[i - 1].second - v[i].first), dp[i - 1][1] + abs(v[i - 1].first - v[i].first)) + v[i].second;
	}

	cout << max(dp[n - 1][0], dp[n - 1][1]);

	return 0;
}

