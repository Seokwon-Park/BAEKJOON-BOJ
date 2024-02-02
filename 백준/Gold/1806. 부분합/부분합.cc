#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, s;
	cin >> n >> s;
	vector<int> pfsum(n+1, 0);
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		pfsum[i] = pfsum[i - 1] + num;
	}

	int st = 1;
	int ed = 1;

	int mn = INT_MAX;
	while (ed <= n)
	{
		int res = pfsum[ed] - pfsum[st - 1];
		if (res >= s)
		{
			mn = min(mn, ed - st + 1);
			st++;
		}
		else
		{
			ed++;
		}
	}

	if (mn == INT_MAX)
		cout << 0;
	else
		cout << mn;


	return 0;
}