#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int s, a, b;
	cin >> s >> a >> b;

	if (a >= s)
		cout << 250;
	else
	{
		int res = 250;
		s -= a;
		res += (s / b) * 100;
		if (s % b)
			res += 100;
		cout << res;

	}

	return 0;
}