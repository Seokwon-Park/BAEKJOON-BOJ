#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

bool isPelin(int st ,int en, const string& s)
{
	while (st < en)
	{
		if (s[st] != s[en]) return false;
		st++;
		en--;
	}

	return true;
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
		int st = 0;
		int en = s.size() - 1;
		int diff = 0;
		bool isP = true;
		while (st < en)
		{
			if (s[st] != s[en])
			{
				diff++;
				if (isPelin(st + 1, en, s) || isPelin(st, en-1, s)) // 둘중 하나만 참이라면 펠린드롬 가능
				{
					
				}
				else
				{
					isP = false;
				}
				break;
			}
			else
			{
				st++;
				en--;
			}
		}
		if (isP)
		{
			if (diff)
				cout << 1;
			else
				cout << 0;
		}
		else
			cout << 2;
		cout << '\n';
	}

	return 0;
}
