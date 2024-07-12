#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int o = 0;
	int z = 0;
	for (auto c : s)
	{
		if (c == '0')
			z++;
		else
			o++;
	}

	vector<bool> del(s.size(), false);

	int d = 0;
	int ix = 0;
	while (d < o/2)
	{
		if (s[ix] == '1')
		{
			del[ix] = true;
			d++;
		}
		ix++;
	}

	d = 0;
	ix = s.size()-1;
	while (d < z / 2)
	{
		if (s[ix] == '0')
		{
			del[ix] = true;
			d++;
		}
		ix--;
	}

	for (int i = 0; i < s.size(); i++)
	{
		if (!del[i])		
		{	
			cout << s[i];
		}
	}

	return 0;
}
