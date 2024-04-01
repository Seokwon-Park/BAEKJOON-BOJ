#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int ans = 0;
	int cmp = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		vector<int> card(5);
		for (int j = 0; j < 5; j++)
		{
			cin >> card[j];
		}
		sort(card.begin(), card.end());
		vector<int> comb = { 0,0,1,1,1 };
		int mx = 0;
		do
		{
			int tmp = 0;
			for (int i = 0; i < 5; i++)
			{
				if (comb[i])
				{
					tmp += card[i];
				}
			}
			mx = max(mx, tmp % 10);
		} while (next_permutation(comb.begin(),comb.end()));
		if (cmp <= mx)
		{
			cmp = mx;
			ans = i;
		}
	}
	cout << ans;

	return 0;
}