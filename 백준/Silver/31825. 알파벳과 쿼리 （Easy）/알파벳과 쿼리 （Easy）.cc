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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	for (int i = 0; i < q; i++)
	{
		int x, l, r;
		cin >> x >> l >> r;
		l--, r--;
		if (x == 1)
		{
			int group = 1;
			int prev = s[l];
			for (int i = l; i <= r; i++)
			{
				if (prev != s[i])
				{
					group++;
					prev = s[i];
				}
			}
			cout << group << '\n';
		}
		else
		{
			for (int i = l; i <=r ; i++)
			{
				s[i] = (s[i] - 'A' + 1) % 26 + 'A';
			}
		}

	}

	return 0;
}