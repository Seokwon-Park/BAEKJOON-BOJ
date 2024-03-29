#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int ans = 0;
	while (n--)
	{
		string s;
		cin >> s;
		int d = stoi(s.substr(2));
		if (d <= 90)
			ans++;
	}
	cout << ans;

	return 0;
}