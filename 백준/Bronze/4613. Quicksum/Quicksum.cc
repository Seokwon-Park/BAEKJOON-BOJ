#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	while (getline(cin, s), s != "#")
	{
		int res = 0;
		for (int i = 1; i <= s.size(); i++)
		{
			char c = s[i-1];
			if (c == ' ')continue;
			else
				res += (c - 'A'+1) * i;
		}
		cout << res << '\n';
	}




	return 0;
}

