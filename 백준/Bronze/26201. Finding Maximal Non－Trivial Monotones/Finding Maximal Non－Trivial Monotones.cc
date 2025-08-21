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
	
	int n;
	cin >> n;

	string s;
	cin >> s;
	int cont = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'a')
		{
			cont++;
		}
		else
		{
			if (cont > 1)
			{
				ans += cont;
			}
			cont = 0;
		}
	}
	if (cont > 1)
	{
		ans += cont;
	}

	cout << ans;


	return 0;
}