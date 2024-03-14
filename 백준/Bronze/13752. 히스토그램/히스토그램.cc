#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for (auto i : v)
	{
		for (int j = 0; j < i; j++)
		{
			cout << '=';
		}
		cout << '\n';
	}

	return 0;
}