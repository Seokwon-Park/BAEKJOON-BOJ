#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		vector<int> alpha(26, 0);
		int ix = 0;
		bool isFake = false;
		while(ix < s.size())
		{
			alpha[s[ix] - 'A']++;
			if (alpha[s[ix] - 'A'] % 3 == 0)
			{
				if (ix + 1 >= s.size() || s[ix + 1] != s[ix])
				{
					isFake = true;
					break;
				}
				else
					ix++;
			}
			ix++;
		}
		if (isFake)
			cout << "FAKE";
		else
			cout << "OK";
		cout << '\n';
		
		
	}

	return 0;
}