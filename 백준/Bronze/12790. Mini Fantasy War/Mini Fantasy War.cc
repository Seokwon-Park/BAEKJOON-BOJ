#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

using bigint = vector<int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int hp, mp, atk, def, hpp, mpp, atkk, deff;
		cin >> hp >> mp >> atk >> def >> hpp >> mpp >> atkk >> deff;
		int fhp = max(hp + hpp, 1);
		int fmp = max(mp + mpp, 1);
		int fatk = max(atk + atkk, 0);
		int fdef = def + deff;

		cout << 1 * fhp + 5 * fmp + 2 * fatk + 2 * fdef << '\n';

	}

	return 0;
}