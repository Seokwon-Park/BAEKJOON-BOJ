#include <bits/stdc++.h>

using namespace std;

int func(int n)
{
	if (n == 1) return 1;
	return n + func(n - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		cout << func(n) << '\n';

	}
	return 0;
}