#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	n--;
	int res = n % 8 + 1;
	if (res > 5)
	{
		cout << 5 - (res - 5);
	}
	else
	{
		cout << res;
	}

	return 0;
}