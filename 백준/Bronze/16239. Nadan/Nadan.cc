#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int sum = 0;
	for (int i = 1; i <= k - 1; i++)
	{
		sum += i;
		cout << i << '\n';
	}
	cout << n - sum;
	

	return 0;
}