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
	while (getline(cin, s))
	{
		bool isBug = 1;
		string test = s;
		while (isBug)
		{
			isBug = 0;
			string res = "";
			for (int i = 0; i < test.size(); i++)
			{
				if (i + 2 < test.size() && test[i] == 'B' && test[i + 1] == 'U' && test[i + 2] == 'G')
				{
					isBug = 1;
					i += 2;
				}
				else
				{
					res += test[i];
				}
			}
			test = res;
		}
		cout << test;
		cout << '\n';
	}

	return 0;
}
