#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int h, l, a, b;
	cin >> h >> l >> a >> b;
	if (a <= h * 2 && b <= l)
	{
		cout << "YES";
	}
	else if (b <= h * 2 && a <= l)
	{
		cout << "YES";
	}
	else
		cout << "NO";

	return 0;
}
