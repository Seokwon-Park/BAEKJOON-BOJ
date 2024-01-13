#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	unordered_map<string, int> um;//num, index;
	int k, l;
	cin >> k >> l;
	for (int i = 0; i < l; i++)
	{
		string str;
		cin >> str;
		um[str] = i;
	}

	vector<pair<string, int>> mvec(um.begin(), um.end());
	sort(mvec.begin(), mvec.end(), [](const auto& a, const auto& b)
		{
			return a.second < b.second;
		});

	int range = mvec.size() < k ? mvec.size() : k;
	for (int i = 0; i < range; i++)
	{
		cout << mvec[i].first << '\n';
	}

	return 0;
}
