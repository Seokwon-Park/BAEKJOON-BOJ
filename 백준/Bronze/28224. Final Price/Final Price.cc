#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		res += input;
	}
	cout << res;

	return 0;
}