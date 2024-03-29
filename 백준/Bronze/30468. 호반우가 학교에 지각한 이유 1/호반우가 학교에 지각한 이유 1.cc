#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		int ab;
		cin >> ab;
		sum += ab;
	}
	int n;
	cin >> n;
	cout << max(0, n * 4 - sum);

	return 0;
}