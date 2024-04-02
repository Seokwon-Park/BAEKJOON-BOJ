#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		bool findPel = false;
		for (int i = 2; i <= 64; i++)
		{
			int tmp = n;
			vector<int> v;
			while (tmp)
			{
				v.push_back(tmp % i);
				tmp /= i;
			}
			bool isPel = true;
			for (int j = 0; j < v.size() / 2; j++)
			{
				if (v[j] != v[v.size() - j - 1])
				{
					isPel = false;
					break;
				}
			}
			if (isPel)
			{
				findPel = true;
				break;
			}
		}
		if (findPel)
			cout << 1;
		else
			cout << 0;
		cout << '\n';
	}

	return 0;
}