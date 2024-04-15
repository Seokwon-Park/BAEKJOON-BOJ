#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string ans;
	if (n == 0)
		ans = "0";
	while (n)
	{
		ans += abs(n) % 2 + '0';
		n = ceil(n/-2.0);
	}

	cout << string(ans.rbegin(), ans.rend());

	return 0;
}