#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

vector<int> alpha(26,0);
vector<int> acpy(26,0);


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (auto c : s)
	{
		alpha[c - 'A']++;
	}
	vector<string> cmp(n - 1);
	for (int i = 0; i < n-1; i++)
	{
		cin >> cmp[i];
	}

	int ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		acpy = alpha;
		int diff = 0;
		bool isSim = true;
		for (auto c : cmp[i])
		{
			if (acpy[c - 'A'])
				acpy[c - 'A']--;
			else
				diff++;
			if (diff > 1) isSim = false;
		}
		if (count(acpy.begin(), acpy.end(), 1) > 1)
			isSim = false;
		if (isSim) ans++;
	}
	cout << ans;


	return 0;
}
