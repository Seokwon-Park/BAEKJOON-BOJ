#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	string hp;
	cin >> hp;
	vector<bool> isEaten(n, false);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (hp[i] == 'P')
		{
			int mix = min(n - 1, k + i);
			for (int j = max(0, i - k); j <= mix; j++)
			{
				if (hp[j] == 'H' && !isEaten[j])
				{
					isEaten[j] = true;
					ans++;
					break;
				}
			}
		}
	}
	cout << ans;
	
	return 0;
}