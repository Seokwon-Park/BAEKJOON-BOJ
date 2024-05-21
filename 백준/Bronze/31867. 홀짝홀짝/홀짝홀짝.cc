#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string k;
	cin >> n >> k;

	int odd = 0;
	int even = 0;
	for (auto c : k)
	{
		int n = c - '0';
		if (n % 2)
			odd++;
		else
			even++;
	}
	if (even > odd)
		cout << 0;
	else if (even < odd)
		cout << 1;
	else
		cout << -1;

	return 0;
}
