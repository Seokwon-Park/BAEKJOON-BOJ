#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;
	if (b <= a)
	{
		cout << b;
	}
	else // a < b
	{
		cout << a + 1;
	}

	return 0;
}
