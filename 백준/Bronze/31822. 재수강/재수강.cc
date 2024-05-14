#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		string k;
		cin >> k;
		if (s.substr(0, 5) == k.substr(0, 5))
			ans++;
	}

	cout << ans;

	return 0;
}