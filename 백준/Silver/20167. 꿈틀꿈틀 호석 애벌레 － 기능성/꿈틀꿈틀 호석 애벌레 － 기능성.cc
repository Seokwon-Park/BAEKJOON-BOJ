#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int n, k;
int ans;
int v[25];

void dfs(int x, int eat, int score)
{
	if (eat >= k)
	{
		score += eat - k;
		eat = 0;
	}
	if (x >= n)
	{
		ans = max(score, ans);
		return;
	}
	if (eat == 0)
	{
		dfs(x + 1, eat, score);
	}
	dfs(x + 1, eat + v[x], score);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	cin >> n >> k;


	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	dfs(0, 0, 0);
	cout << ans;

	return 0;
}