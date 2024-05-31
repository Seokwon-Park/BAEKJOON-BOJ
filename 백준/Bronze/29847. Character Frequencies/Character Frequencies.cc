#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> v(256, 0);
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);
		for (auto c : s)
		{
			if (c == ' ') continue;
			v[c]++;
		}
	}

	for (int  i = 0; i< 256;i ++)
	{
		if (v[i] == 0)continue;
		cout << (char)i << ' ' << v[i] << '\n';
	}

	return 0;
}