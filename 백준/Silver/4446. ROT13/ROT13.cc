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

	vector<int> vow = { 'a', 'i', 'y', 'e', 'o', 'u' };
	vector<int> vowB = { 'A', 'I', 'Y', 'E', 'O', 'U' };
	vector<int> con = { 'b','k','x','z','n','h','d','c','w','g','p','v','j','q','t','s','r','l','m','f' };
	vector<int> conB = { 'B','K','X','Z','N','H','D','C','W','G','P','V','J','Q','T','S','R','L','M','F' };

	vector<int> chmap(256);
	vector<int> isVow(256, false);

	for (int i = 0; i < vow.size(); i++)
	{
		chmap[vow[i]] = i;
		chmap[vowB[i]] = i;
		isVow[vow[i]] = true;
		isVow[vowB[i]] = true;

	}

	for (int i = 0; i < con.size(); i++)
	{
		chmap[con[i]] = i;
		chmap[conB[i]] = i;
	}

	string s;
	while (getline(cin, s))
	{
		for (int i = 0; i < s.size(); i++)
		{
			char c = s[i];
			if (c <= 'z' && c >= 'a')
			{
				if (isVow[c])
				{
					int ix = chmap[c];
					s[i] = vow[(ix + 3) % vow.size()];
				}
				else
				{
					int ix = chmap[c];
					s[i] = con[(ix + 10) % con.size()];
				}
			}
			else if( c<='Z' && c>='A')
			{
				if (isVow[c])
				{
					int ix = chmap[c];
					s[i] = vowB[(ix + 3) % vowB.size()];
				}
				else
				{
					int ix = chmap[c];
					s[i] = conB[(ix + 10) % conB.size()];
				}
			}
		}

		cout << s << '\n';
	}

	return 0;
}