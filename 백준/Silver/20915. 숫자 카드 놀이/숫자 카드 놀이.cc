#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

ll check(string s)
{
	int mx = 1 << (s.size() - 1);
	ll res = 0;
	for (int i = 1; i < mx; i++)
	{
		int tmp = i;
		string a, b;
		for (int j = 0; j < s.size(); j++)
		{
			if (tmp % 2 == 1)
			{
				a += s[j];
			}
			else
			{
				b += s[j];
			}
			tmp /= 2;
		}
		res = max(res, stoll(a) * stoll(b));
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		string cards;
		int zeros = 0;
		for (auto c : s)
		{
			if (c == '6')
			{
				cards += '9';
			}
			else if (c == '0')
			{
				zeros++;
			}
			else
			{
				cards += c;
			}
		}
		sort(cards.begin(),cards.end(), greater<char>());
		ll result = check(cards);
		for (int i = 0; i < zeros; i++)
		{
			result *= 10;
		}
		cout << result << '\n';

	}


	return 0;
}