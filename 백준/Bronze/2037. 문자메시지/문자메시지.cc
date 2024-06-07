#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int get_group(int n)
{
	if (n < 15)
	{
		return n / 3*3;
	}
	else if (n < 19)
		return 15;
	else if (n < 22)
		return 19;
	else
		return 22;
}

int get_pos_in_group(int n)
{
	return n - get_group(n);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int p, w;
	cin >> p >> w;
	cin.ignore();
	string s;
	getline(cin, s);
	int prevgroup = -1;
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if (c == ' ')
		{
			ans += p;
			prevgroup = -1;
			continue;
		}
		int curgroup = get_group(c - 'A');
		if (prevgroup == -1 || prevgroup != curgroup)
		{
			prevgroup = curgroup;
		}
		else
		{
			ans += w;
		}
		ans += p * (get_pos_in_group(c - 'A') + 1);
	}
	
	cout << ans;
	
	return 0;
}