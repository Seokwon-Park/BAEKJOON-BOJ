#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	std::vector<int> v(5);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (auto c : s)
	{
		if (c == 'H')
			v[0]++;
		if (c == 'I')
			v[1]++;
		if (c == 'A')
			v[2]++;
		if (c == 'R')
			v[3]++;
		if (c == 'C')
			v[4]++;
	}

	cout << *min_element(v.begin(), v.end());


	return 0;
}