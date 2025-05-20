#include <bits/stdc++.h>
#include <regex>

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

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		string pattern;
		cin >> s >> pattern;
		
		set<char> res;
		for (int j = 0; j < 26; j++)
		{
			string tmp = s;
			int ix = tmp.find('_');
			tmp[ix] = 'A'+j;
			if (regex_match(pattern, regex(tmp)))
			{
				res.insert(tmp[ix]);
			}
		}
		if (res.size() == 1)
		{
			cout << *res.begin();
		}
		else if(res.size() >1)
		{
			cout << '_';
		}
		else
		{
			cout << '!';
		}
		cout << '\n';
	}

	return 0;
}