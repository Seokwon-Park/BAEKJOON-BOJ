#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int dec = 10;
	while (n >= dec)
	{
		if ((n % dec) >= dec / 2)
		{
			n /= dec;
			n *= dec;
			n += dec;
		}
		else
		{
			n /= dec;
			n *= dec;
		}
		dec *= 10;
	}
	cout << n;

	return 0;
}