#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<string> v(4);
	
	for (int i = 0; i < 4; i++)
	{
		cin >> v[i];
	}

	set<string> s;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			s.insert(v[i] + ' ' + v[j]);
		}
	}

	for(auto i: s)
		cout << i << '\n';

	


	return 0;
}
