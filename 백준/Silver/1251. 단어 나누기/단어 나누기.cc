#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	string ans(s.size(), 'z');
	for (int i = 1; i < s.size()-1; i++)
	{
		string a, b, c;
		a = s.substr(0, i);
		for (int j = i+1; j < s.size(); j++)
		{
			b = s.substr(i, j - i);
			c = s.substr(j);
			string ns = string(a.rbegin(), a.rend()) + string(b.rbegin(), b.rend()) + string(c.rbegin(), c.rend());
			ans = min(ans, ns);
		}

	}
	cout << ans;

	return 0;
}
