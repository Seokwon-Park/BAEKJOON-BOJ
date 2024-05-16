#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	if ((n - 2LL) % 7LL == 0 || (n - 2LL) % 7LL == 5)
		cout << "CY";
	else
		cout << "SK";


	return 0;
}
