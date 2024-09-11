#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

string a[10] = { "","I","II","III","IV","V","VI","VII","VIII","IX" };

string b[10] = { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	unordered_map<string, int> m;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			m[b[i] + a[j]] = i * 10 + j;
		}
	}
	
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	
	string ans = "";
	int val = INF;
	do
	{
		if (m.find(s) != m.end())
		{
			if (m[s] < val)
			{
				ans = s;
				val = m[s];
			}
		}
	} while (next_permutation(s.begin(), s.end()));

	cout << ans;

	return 0;
}

