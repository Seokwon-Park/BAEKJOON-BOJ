#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a;
	int b;
	cin >> a >> b;
	sort(a.begin(), a.end());
	int ans = -1;
	do
	{
		if (*a.begin() == '0')continue;
		int res = stoi(a);
		if (res >= b)continue;
		ans = max(ans, res);
	} while (next_permutation(a.begin(), a.end()));

	cout << ans;

	return 0;
}