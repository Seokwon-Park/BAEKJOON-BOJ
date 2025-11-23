//풀이를 참고해서 풀었음
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

int dp[405][405][405];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v1(1, 0), v2(1, 0);

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x) v1.push_back(x);
	}
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x) v2.push_back(x);
	}

	int size1 = v1.size() - 1;
	int size2 = v2.size() - 1;

	for (int i = 1; i <= n; i++) //i 열까지 채운다고 했을때 
	{
		for (int j = 1; j <= min(i, size1); j++) // 배열1에는 j개만큼의 숫자 그외에는 0
		{
			for (int k = 1; k <= min(i, size2); k++) // 배열2에는 k개만큼의 숫자 그외에는 영
			{
				if (j >= i && k >= i)
				{
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + v1[j] * v2[k]; // 이전 최고 값에서 무조건 2개를 곱해서 넣어야 함
				}
				else if (j >= i)
				{
					dp[i][j][k] = max(dp[i - 1][j - 1][k], dp[i - 1][j - 1][k - 1] + v1[j] * v2[k]); // 이전 최고값에서 2개를 곱해서 넣거나 v1에서는 반드시 넣어야 하지만 v2는 이미 앞에서 다쓰고 0일 수 있음
				}
				else if (k >= i)
				{
					dp[i][j][k] = max(dp[i - 1][j][k - 1], dp[i - 1][j - 1][k - 1] + v1[j] * v2[k]); // 이전 최고값에서 2개를 곱해서 넣거나 v2에서는 반드시 넣어야 하지만 v1는 이미 앞에서 다쓰고 0일 수 있음
				}
				else
				{
					dp[i][j][k] = max({ dp[i - 1][j - 1][k],dp[i - 1][j][k - 1], dp[i - 1][j - 1][k - 1] + v1[j] * v2[k] }); // 앞의 3가지 경우중 최댓값
				}
			}
		}
	}

	cout << dp[n][size1][size2];


	return 0;
}