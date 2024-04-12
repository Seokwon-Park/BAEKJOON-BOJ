#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int s, p;
	string dna;
	int a, c, g, t;
	cin >> s >> p;
	cin >> dna;
	cin >> a >> c >> g >> t;

	int ca = 0, cc = 0, cg = 0, ct = 0;

	int ans = 0;
	for (int i = 0; i < dna.size() - p + 1; i++)
	{
		if (i == 0)
		{
			string tmp = dna.substr(i, p);
			for (char c : tmp)
			{
				if (c == 'A') ca++;
				if (c == 'C') cc++;
				if (c == 'G') cg++;
				if (c == 'T') ct++;
			}
		}
		else
		{
			if (dna[i - 1] == 'A') ca--;
			if (dna[i - 1] == 'C') cc--;
			if (dna[i - 1] == 'G')cg--;
			if (dna[i - 1] == 'T')ct--;

			if (dna[i +p-1] == 'A') ca++;
			if (dna[i +p-1] == 'C') cc++;
			if (dna[i +p-1] == 'G')cg++;
			if (dna[i +p-1] == 'T')ct++;
		}
		if (ca >= a && cc >= c && cg >= g && ct >= t) ans++;
	}
	cout << ans;

	return 0;
}