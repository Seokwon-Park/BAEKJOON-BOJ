#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	if (n > 7)
	{
		cout << n - 7;
	}
	else
	{
		int month =  14 - n + m;
		int left = 7 - (month - m);
		if (left > 0)
			cout << left;
		else
			cout << month + left;
	}


	return 0;
}