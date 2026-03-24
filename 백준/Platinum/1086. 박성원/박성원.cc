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

string v[15];
ll dp[1 << 15][100];
int d[55];
int mod[15];
int len[15];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int k;
	cin >> k;

	//뒤에 붙이기 위해서 원래 수를 밀어내야 하는데
	//최대 50자리 수니까 10^50까지의 모듈러를 구한다.
	d[0] = 1;
	for (int i = 1; i <= 50; i++)
	{
		d[i] = (d[i - 1] * 10) % k;
	}

	//숫자들을 k로 나눈 나머지를 미리 계산해둔다.
	for (int i = 0; i <n ;i++) 
	{
		int res = 0;
		for (auto c : v[i])
		{
			res = (res * 10 + (c - '0')) % k;// 모듈러는 분배법칙을 적용할 수 있다
		}
		len[i] = v[i].size(); // 길이도 미리 계산해둔다
		mod[i] = res;
	}

	dp[0][0] = 1; // 아무것도 선택하지 않고 나머지가 0인 경우 1가지
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (dp[i][j] == 0) continue;

			for (int l = 0; l < n; l++)
			{
				if (i & (1 << l)) continue;

				int nxt = (j * d[len[l]] + mod[l]) % k; 
				dp[i | (1 << l)][nxt] += dp[i][j];
			}
		}
	}

	ll ans = dp[(1 << n) - 1][0];

	ll deno = 1;
	for (ll i = 1; i <= n; i++)
	{
		deno *= i;
	}

	ll g = gcd(ans, deno);
	cout << ans / g << '/' << deno / g << '\n';

	return 0;
}