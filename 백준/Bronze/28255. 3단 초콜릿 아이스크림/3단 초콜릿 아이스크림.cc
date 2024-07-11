#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

string rev(string s)
{
	return string(s.rbegin(), s.rend());
}

string tail(string s)
{
	return s.substr(1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		string s;
		cin >> s;
		string ss = s.substr(0, (int)ceil((double)s.size() /3.0));

		if (s == ss + rev(ss) + ss || 
			s == ss + tail(rev(ss)) + ss || 
			s == ss + rev(ss) + tail(ss) || 
			s == ss + tail(rev(ss)) + tail(ss))
			cout << 1;
		else
			cout << 0;
		cout << '\n';
	}

	return 0;
}
