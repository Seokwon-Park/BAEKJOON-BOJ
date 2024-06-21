#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a;
	string b;
	getline(cin, a);
	getline(cin, b);
	string ans;
	for (int i = 0; i< a.size(); i++)
	{
		if (a[i] == ' ')
		{
			ans.push_back(' ');
			continue;
		}
		int ix = a[i] - 'a';
		int offset = b[i % b.size()] - 'a';
		ix = (ix - offset +25) % 26;
		ans.push_back('a' + ix);
	}
	cout << ans;

	return 0;
}
