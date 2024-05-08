#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	int cursz = n;
	for (int i = 0; i < n; i++)
	{
		v[i] = i + 1;
	}

	while (cursz != 1)
	{
		for (int i = 0; i < cursz/2; i++)
		{
			v[i] = v[i * 2 + 1];
		}
		cursz /= 2;
	}

	cout << v[0];

	return 0;
}