#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		string s = to_string(i);
		for (auto c : s)
		{
			if (c == '3' || c == '6' || c == '9')
				cnt++;
		}
	}
	cout << cnt;

	return 0;
}