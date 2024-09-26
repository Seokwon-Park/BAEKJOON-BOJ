#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int b[26][26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < 26; i++)
	{
		fill(b[i], b[i] + 26, INF);
		b[i][i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		char x, z;
		string y;
		cin >> x >> y >> z;
		b[x - 'a'][z - 'a'] = 1;
	}

	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			for (int k = 0; k < 26; k++)
			{
				b[j][k] = min(b[j][k], b[j][i] + b[i][k]);
			}


	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		char x, z;
		string y;
		cin >> x >> y >> z;
		cout << (b[x-'a'][z-'a'] != INF ? 'T' : 'F') << '\n';
	}


	return 0;
}

