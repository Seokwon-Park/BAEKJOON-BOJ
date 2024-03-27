#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1)
	{
		int n;
		cin >> n;
		if (!n) break;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		for (int i = 0; i < n / 2; i++)
		{
			swap(v[i], v[n - i - 1]);
		}
		for (int i : v)
			cout << i << '\n';
		cout << "0\n";
	}
	return 0;
}