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

	string s;
	cin >> s;
	int l = -1;
	int ll = -1;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
		{
			if (l == -1)
			{
				l = i + 1;
			}
			else
			{
				if (ll == -1)
				{
					ll = i + 1;
					break;
				}
			}
		}
	}
	int n = s.size() - 1;
	if (s[n] == 'a' ||
		s[n] == 'e' ||
		s[n] == 'i' ||
		s[n] == 'o' ||
		s[n] == 'u' ||
		s[n] == 'n' ||
		s[n] == 's')
	{
		cout << ll;
	}
	else
	{
		cout << l;
	}

	return 0;
}