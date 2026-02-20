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

ll dp[1 << 15];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	cin.ignore();
	string s;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i < 1 << 15; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
		if (dp[i] >= 1LL << 32) break;
	}


	while (n--)
	{
		getline(cin, s);
		istringstream iss(s);
		string tmp;
		vector<ll> v;
		while (getline(iss, tmp, ' '))
		{
			v.push_back(stoll(tmp));
		}
		bool isNaut = true;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] != dp[i])
			{
				isNaut = false;
				break;
			}
		}
		cout << (isNaut ? "NAUTILUS" : "SNAIL") << '\n';
	}


	return 0;
}
