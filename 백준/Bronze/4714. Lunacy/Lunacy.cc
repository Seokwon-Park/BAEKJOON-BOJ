#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1)
	{
		double n;
		cin >> n;
		if (n < 0) break;
		cout << fixed;
		cout.precision(2);
		cout << "Objects weighing " << n << " on Earth will weigh " << n * 0.167 << " on the moon.\n";
	}



	return 0;
}