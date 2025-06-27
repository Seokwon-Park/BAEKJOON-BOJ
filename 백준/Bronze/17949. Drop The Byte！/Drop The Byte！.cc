#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int hexToDec(char c)
{
	if (c >= 'a')
	{
		return 10 + c - 'a';
	}
	return c - '0';
}

ll toDecimal(string s)
{
	ll exp = 1;
	ll res = 0;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		res += exp * hexToDec(s[i]);
		exp *= 16;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int cursor = 0;
	for (int i = 0; i < n; i++)
	{
		string tmp = "";
		int size = 0;
		if (v[i] == "char")
		{
			size = 2;
		}
		else if (v[i] == "int")
		{
			size = 8;
		}
		else if (v[i] == "long_long")
		{
			size = 16;
		}
		tmp = s.substr(cursor, size);
		cursor += size;

		cout << toDecimal(tmp) << ' ';
	}

	return 0;
}