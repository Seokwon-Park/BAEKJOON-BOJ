#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	getline(cin, s);
	string ans;
	int ix = 0;
	while(ix < s.size())
	{
		ans += s[ix];
		if (s[ix] == 'a' || s[ix] == 'e' || s[ix] == 'i' || s[ix] == 'o' || s[ix] == 'u')
			ix += 3;
		else
			ix++;
	}
	cout << ans;


	return 0;
}