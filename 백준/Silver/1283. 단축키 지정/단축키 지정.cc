#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

bool isused[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		bool findKey = false;
		int keyix = 0;
		string s;
		getline(cin, s);
		istringstream iss(s);
		string tmp;
		int ix= 0;
		while (getline(iss, tmp, ' '))
		{
			char c = tmp[0];
			int key;
			if (c <= 'z' && c >= 'a')
				key = c - 'a';
			else
				key = c - 'A';
			if (!isused[key])
			{
				isused[key] = true;
				findKey = true;
				for (int i = 0; i < s.size(); i++)
				{
					if (i == ix)
						cout << '[' << s[i] << ']';
					else
						cout << s[i];
				}
				break;
			}
			ix += tmp.length() + 1;
		}
		if (findKey)
		{
			cout << '\n';
			continue;
		}
		for (int i = 0; i< s.size(); i++)
		{
			char c = s[i];
			int key;
			if (c <= 'z' && c >= 'a')
				key = c - 'a';
			else if (c <= 'Z' && c >= 'A')
				key = c - 'A';
			else
				continue;
			if (!isused[key])
			{
				isused[key] = true;
				findKey = true;
				for (int j = 0; j < s.size(); j++)
				{
					if (i == j)
						cout << '[' << s[j] << ']';
					else
						cout << s[j];
				}
				break;
			}

		}
		if (findKey)
		{
			cout << '\n';
			continue;
		}
		cout << s << '\n';
	}
	
	
	return 0;
}