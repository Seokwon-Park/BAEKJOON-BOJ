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

	string s;
	getline(cin, s);

	string token = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (isalpha(s[i]) || s[i] == '$' || s[i] == '?' || s[i] == '+' || s[i] == '_' || isdigit(s[i]))
		{
			token += s[i];
		}
		else
		{
			if (!token.empty())
			{
				cout << token << ' ';
				token = "";
			}
			if (s[i] == '<' || s[i] == '>' || s[i] == '(' || s[i] == ')')
			{
				cout << s[i] << ' ';
			}
			if (s[i] == '|')
			{
				cout << "|| ";
				i++;
			}
			if (s[i] == '&' && s[i + 1] == '&')
			{
				cout << "&& ";
				i++;
			}

		}
	}
	if (!token.empty())
	{
		cout << token;
	}

	return 0;
}