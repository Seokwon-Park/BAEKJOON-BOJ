#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

string upper = "A   3  HI   M O   2TUVWXY5";
string lower = " d b    i  lmnoqp7  uvwx  ";
string num = "01SE Z r8 ";

char getQuilin(char c)
{
	if (c <= 'Z' && c >= 'A')
	{
		int ix = c - 'A';
		return upper[ix];
	}
	else if (c <= 'z' && c >= 'a')
	{
		int ix = c - 'a';
		return lower[ix];
	}
	else if(c <= '9' && c>='0')
	{
		int ix = c - '0';
		return num[ix];
	}
	return c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (isalpha(s[i]))
		{
			s[i] = tolower(s[i]);
		}
		char c = getQuilin(s[i]);
		if (c == ' ')
		{
			if (s[i] <= 'Z' && s[i] >= 'A')
			{
				int ix = s[i] - 'A';
				s[i] = 'a' + ix;
			}
			else if (s[i] <= 'z' && s[i] >= 'a')
			{
				int ix = s[i] - 'a';
				s[i] = 'A' + ix;
			}
		}
		if (getQuilin(s[i]) == ' ')
		{
			cout << -1;
			return 0;
		}
	}

	for (int i = 0; i <= s.size()/2; i++)
	{
		if (s[i] != getQuilin(s[s.size() - 1 - i]))
		{
			cout << -1;
			return 0;
		}
	}

	cout << s;

	return 0;
}