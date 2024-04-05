#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int freq[51][4]; // ACGT = 0123

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j< m; j++)
		{
			char c = s[j];
			if (c == 'A')
				freq[j][0]++;
			if (c == 'C')
				freq[j][1]++;
			if (c == 'G')
				freq[j][2]++;
			if (c == 'T')
				freq[j][3]++;
		}
	}

	string ans = "";
	int dist = 0;
	for (int i = 0; i < m; i++)
	{
		int ix = max_element(freq[i], freq[i] + 4) - freq[i];
		if (ix == 0)
			ans += 'A';
		if (ix == 1)
			ans += 'C';
		if (ix == 2)
			ans += 'G';
		if (ix == 3)
			ans += 'T';
		dist += n - freq[i][ix];
	}

	cout << ans << '\n';
	cout << dist;


	return 0;
}