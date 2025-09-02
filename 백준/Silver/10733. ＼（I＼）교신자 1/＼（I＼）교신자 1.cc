#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll I, a, b, c, k;
	cin >> I >> a >> b >> c >> k;

	vector<int> v;
	for (int i = 0; i < a; i++)v.push_back(0);
	for (int i = 0; i < b; i++)v.push_back(1);
	for (int i = 0; i < c; i++)v.push_back(2);

	vector<ll> ans(k + 1);
	do
	{
		vector<ll> stk(41, I);
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == 0)
				stk.push_back(I);
			else if (v[i] == 1)
			{
				ll tmp1 = stk.back();
				stk.pop_back();
				ll tmp2 = stk.back();
				stk.pop_back();
				stk.push_back((tmp1 + tmp2) % MOD);
			}
			else
			{

				ll tmp1 = stk.back();
				stk.pop_back();
				ll tmp2 = stk.back();
				stk.pop_back();
				stk.push_back((tmp1 * tmp2) % MOD);
			}

		}
		for (int i = 1; i <= k; i++)
		{
			ans[i] += stk[stk.size() - i];
			ans[i] %= MOD;
		}

	} while (next_permutation(v.begin(), v.end()));

	for (int i = 1; i <= k; i++)
	{
		cout << ans[i] << '\n';
	}

	return 0;
}