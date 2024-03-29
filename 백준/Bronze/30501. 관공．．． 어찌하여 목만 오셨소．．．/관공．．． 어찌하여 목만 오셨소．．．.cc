#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string ans;
	while (n--)
	{
		string s;
		cin >> s;
		if (s.find('S') != string::npos)
		{
			ans = s;
		}
	}
	cout << ans;

	return 0;
}