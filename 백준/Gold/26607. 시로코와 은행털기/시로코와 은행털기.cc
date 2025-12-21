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

int dp[85][16005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, x;
	cin >> n >> k >> x;

	vector<int> a(n);
	int b;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b;
	}

	dp[0][0] = true;

	for (int i = 0; i < n; i++) // 첫번째 사람부터 보기
	{
		for (int j = k - 1; j >= 0; j--) // 0명 ~ k-1명의 사람 뽑았을 때 경우 살펴보기
		{
			for (int l = 0; l <= j * x; l++) // 가능한 무게
			{
				if (dp[j][l]) // 만약 j명 뽑았을때 a의 무게 합이 l인 경우가 있으면 
				{
					dp[j + 1][l + a[i]] = true;
				}
			}
		}
	}

	int ans = 0;
	for (int j = 0; j <= k * x; j++) 
	{
		if (dp[k][j])
		{
			ans = max(ans, j * (k * x - j));
		}
	}

	cout << ans;

	return 0;
}