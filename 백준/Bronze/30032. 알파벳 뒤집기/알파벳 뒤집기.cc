
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	map<char, char> pat1;
	map<char, char>pat2;
	pat1['d'] = 'q';
	pat1['b'] = 'p';
	pat1['q'] = 'd';
	pat1['p'] = 'b';

	pat2['d'] = 'b';
	pat2['b'] = 'd';
	pat2['q'] = 'p';
	pat2['p'] = 'q';


	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			if (d == 1)
			{
				cout << pat1[c];
			}
			else
			{
				cout << pat2[c];
			}
		}
		cout << '\n';
	}

	return 0;
}