#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int mn = INT_MAX;

	vi v(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < 5; i++)
		for(int j = i+1; j < 5; j++)
			for (int k = j + 1; k < 5; k++)
			{
				if (i == j || i == k || j == k) continue;
				int res = lcm(v[k], lcm(v[i], v[j]));
				mn = min(res, mn);
			}
	cout << mn;

	return 0;
}