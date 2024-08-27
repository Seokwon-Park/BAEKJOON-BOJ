#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

bool isVowel[256];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	isVowel['A'] = true;
	isVowel['E'] = true;
	isVowel['I'] = true;
	isVowel['O'] = true;
	isVowel['U'] = true;
	isVowel['a'] = true;
	isVowel['e'] = true;
	isVowel['i'] = true;
	isVowel['o'] = true;
	isVowel['u'] = true;

	int tc;
	cin >> tc;
	cin.ignore();
	while (tc--)
	{
		string s;
		getline(cin, s);
		int v = 0;
		int c = 0;
		for (auto ch : s)
		{
			if (isalpha(ch))
			{
				if (isVowel[ch])
					v++;
				else
					c++;
			}
		}

		cout << c << ' ' << v << '\n';
	}


	return 0;
}