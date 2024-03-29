#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		int pppp = n / 5;
		string ans;
		for (int i = 0; i < pppp; i++)
			ans += "++++ ";
		for (int i = 0; i < n % 5; i++)
			ans += '|';
		cout << ans << '\n';
	}

	return 0;
}