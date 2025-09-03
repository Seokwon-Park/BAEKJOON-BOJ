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
	
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<ll> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		vector<char> s(n);
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
		}
		
		ll cur = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (s[i] == 'T')
			{
				cur += v[i];
			}
			else
			{
				cur -= v[i];
				cur = max(cur, 0LL);
			}
		}

		cout << cur << '\n';
	}

	return 0;
}