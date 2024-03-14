#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v(3);
	cin >> v[0] >> v[1] >> v[2];
	if (v[0]+v[1]+v[2] >= 100) cout << "OK";
	else
	{
		int ix = min_element(v.begin(), v.end()) - v.begin();
		if (ix == 0)
			cout << "Soongsil";
		else if (ix == 1)
			cout << "Korea";
		else
			cout << "Hanyang";
	}

	return 0;
}