#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ds, ys, dm, ym;
	cin >> ds >> ys >> dm >> ym;

	int sun = ys - ds;
	int moon = ym - dm;
	
	while (sun != moon)
	{
		if (sun > moon)
			moon += ym;
		else
			sun += ys;
	}

	cout << sun;

	return 0;
}