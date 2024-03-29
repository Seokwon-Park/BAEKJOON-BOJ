#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s;
	int ans = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> s >> n;
		if (s == "Es")
		{
			ans += n * 21;
		}
		else
		{
			ans += n * 17;
		}
	}
	cout << ans;

	return 0;
}