#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		int div = n % 100;
		if ((n + 1) % div == 0)
			cout << "Good";
		else
			cout << "Bye";
		cout << '\n';
	}

	return 0;
}