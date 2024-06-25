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
	
	int tc;
	cin >> tc;

	map<char, string> m;
	m['a'] = "as";
	m['i'] = "ios";
	m['y'] = "ios";
	m['l'] = "les";
	m['n'] = "anes";
	m['o'] = "os";
	m['r'] = "res";
	m['t'] = "tas";
	m['u'] = "us";
	m['v'] = "ves";
	m['w'] = "was";


	while (tc--)
	{
		string s;
		cin >> s;

		string ans;
		if (s[s.size() - 2] == 'n' && s[s.size() - 1] == 'e')
		{
			ans = s.substr(0, s.size() - 2) + "anes";
		}
		else if (m.find(s[s.size() - 1]) != m.end())
		{
			ans = s.substr(0, s.size() - 1) + m[s[s.size() - 1]];
		}
		else
		{
			ans = s + "us";
		}
			
		
		cout << ans << '\n';
	}
	
	return 0;
}
