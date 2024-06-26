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

	vector<string> tokens;
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
				tokens.push_back(token);
				token = "";
			}
			if (s[i] == '<' || s[i] == '>' || s[i] == '(' || s[i] == ')')
			{
				string tmp;
				tmp += s[i];
				tokens.push_back(tmp);
			}
			if (s[i] == '|')
			{
				tokens.push_back("||");
				i++;
			}
			if (s[i] == '&' && s[i + 1] == '&')
			{
				tokens.push_back("&&");
				i++;
			}

		}
	}
	if (!token.empty())
	{
		tokens.push_back(token);
	}

	for (auto ss : tokens)
		cout << ss << ' ';

	return 0;
}