#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> k;
	vector<int> v(6);
	int dir;
	for (int i = 0; i < 6; i++)
	{
		cin >> dir;
		cin >> v[i];
	}
	int ix = max_element(v.begin(), v.end()) - v.begin();
	int val = v[ix];
	
	int ix2 = 0;
	int val2;
	int valshort;
	int val2short;
	if (v[(ix + 1) % 6] < v[(ix + 5) % 6])
	{
		val2 = v[(ix + 5) % 6];
		valshort = v[(ix + 1) % 6];
		val2short = v[(ix + 4) % 6];
	}
	else
	{
		val2 = v[(ix + 1) % 6];
		valshort = v[(ix + 5) % 6];
		val2short = v[(ix + 2) % 6];
	}
	cout << (val * val2	 -(val- val2short)*( val2-valshort))*k;


	return 0;
}