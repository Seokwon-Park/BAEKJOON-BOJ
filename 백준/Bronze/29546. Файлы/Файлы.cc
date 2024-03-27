#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		for (int j = a - 1; j <= b - 1; j++)
		{
			cout << s[j] << '\n';
		}
	 }

	return 0;
}