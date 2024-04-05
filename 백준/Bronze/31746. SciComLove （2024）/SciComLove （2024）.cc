#include <bits/stdc++.h>

using namespace std;

using ll = long long;

double dp[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s = "SciComLove";
	if (n % 2)
	{
		for (int i = 0; i < s.size() / 2; i++)
		{
			swap(s[i], s[s.size() - i - 1]);
		}
	}
	cout << s;

	return 0;
}
