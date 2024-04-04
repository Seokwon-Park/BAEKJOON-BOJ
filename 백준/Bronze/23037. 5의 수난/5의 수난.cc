#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	int ans = 0;
	for (auto c : s)
	{
		int n = c - '0';
		ans += n * n * n * n * n;
	}
	cout << ans;


	return 0;
}