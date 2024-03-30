#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string n;
	cin >> n;
	
	int digits = 0;
	int alphas= 0;
	int ans = 1;
	for (int i = 0; i < n.size(); i++)
	{
		if (n[i] == 'd')
		{
			digits++;
			int comb = 1;
			for (int i = 0; i < alphas; i++)
			{
				if (i == 0)
					comb *= 26;
				else
					comb *= 25;
			}
			ans *= comb;
			alphas = 0;
		}
		else
		{
			alphas++;
			int comb = 1;
			for (int i = 0; i < digits; i++)
			{
				if (i == 0)
					comb *= 10;
				else
					comb *= 9;
			}
			ans *= comb;
			digits = 0;
		}
	}
	if (alphas)
	{
		int comb = 1;
		int dec = 26;
		for (int i = 0; i < alphas; i++)
		{
			if (i == 0)
				comb *= 26;
			else
				comb *= 25;
		}
		ans *= comb;
	}
	if (digits)
	{
		int comb = 1;
		int dec = 10;
		for (int i = 0; i < digits; i++)
		{
			if (i == 0)
				comb *= 10;
			else
				comb *= 9;
		}
		ans *= comb;
	}

	cout << ans;

	return 0;
}