#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int n;
	cin >> n;
	int ans = 0;
	while(n--)
	{
		string s2;
		cin >> s2;
		if (s == s2)
			ans++;
	}
	cout << ans;

	return 0;
}