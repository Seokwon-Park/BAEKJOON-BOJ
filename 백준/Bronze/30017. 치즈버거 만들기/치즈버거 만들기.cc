#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	if (a > b)
		cout << b * 2 + 1;
	else
		cout << (a - 1) * 2 + 1;


	return 0;
}