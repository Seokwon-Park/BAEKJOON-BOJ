#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
string m[256];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;

	if (n <= 25)
	{
		cout << s;
	}
	else
	{
		int enpos = s.size() - 11;
		string check = s.substr(11, enpos - 11);
		int cnt = count(check.begin(), check.end(), '.');
		if (cnt == 1) // .이 하나 있을때
		{
			if (check[check.size() - 1] != '.')
			{
				cout << s.substr(0, 9) << "......" << s.substr(s.size() - 10);
			}
			else
			{
				cout << s.substr(0, 11) << "..." << s.substr(enpos);
			}
		}
		else if (cnt > 1)
		{
			cout << s.substr(0, 9) << "......" << s.substr(s.size() - 10);
		}
		else
		{
			cout << s.substr(0, 11) << "..." << s.substr(enpos);
		}

	}



	return 0;
}

