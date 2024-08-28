#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

string strdp[1005];

void check(int n, string s)
{
	if (strdp[n].size() == s.size())
	{
		if (strdp[n] > s)
			strdp[n] = s;
	}
	else if (strdp[n].size() > s.size())
	{
		strdp[n] = s;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	fill(strdp, strdp + 1005, "999999999999999999999999999999");
	strdp[1] = "12";
	strdp[2] = "34";
	strdp[3] = "56";

	for (int i = 4; i <= 1000; i++)
	{
		string tmp = "";
		if (i % 2 == 0)
		{
			tmp = '1' + strdp[i / 2] + '2';
			check(i, tmp);
		}
		if (i % 3 == 0)
		{
			tmp = '3' + strdp[i / 3] + '4';
			check(i, tmp);
		}
		if (i % 5 == 0)
		{
			tmp = '5' + strdp[i / 5] + '6';
			check(i, tmp);
		}
		for (int j = 1; j < i; j++)
		{
			tmp = strdp[j] + strdp[i - j];
			check(i, tmp);

			tmp = strdp[i - j]+ strdp[j];
			check(i, tmp);
		}
	}

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		string tmp = strdp[n];
		for (auto& c : tmp)
		{
			if (c == '1')
				c = '(';
			if (c == '2')
				c = ')';
			if (c == '3')
				c = '{';
			if (c == '4')
				c = '}';
			if (c == '5')
				c = '[';
			if (c == '6')
				c = ']';
		}
		cout << tmp << '\n';
	}

	return 0;
}