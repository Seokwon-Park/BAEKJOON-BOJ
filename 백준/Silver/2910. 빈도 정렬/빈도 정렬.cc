#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_map <int, int> hsh;
	unordered_map <int, int> ix;
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		int n;
		cin >> n;
		if (ix.find(n) == ix.end())
		{
			ix[n] = i;
		}
		hsh[n]++;
	}

	vector<pair<int, int>> mvec(hsh.begin(), hsh.end());

	sort(mvec.begin(), mvec.end(), [&ix](auto& a, auto& b)
		{
			if (a.second == b.second)
			{
				return ix[a.first] < ix[b.first];
			}
			return a.second > b.second;
		});

	for (auto p : mvec)
	{
		for (int i = 0; i < p.second; i++)
		{
			cout << p.first << ' ';
		}
	}


	return 0;
}
