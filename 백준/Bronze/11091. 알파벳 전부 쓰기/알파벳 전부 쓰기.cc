#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	cin.ignore();
	while (n--)
	{
		vector<bool> v(26);

		string s;
		getline(cin, s);
		for (auto c : s)
		{
			if (c >= 'a' && c <= 'z')
				v[c - 'a'] = true;
			else if (c >= 'A' && c <= 'Z')
				v[c - 'A'] = true;
		}

		int res = count(v.begin(), v.end(), true);
		if (res == 26)
		{
			cout << "pangram";
		}
		else
		{
			cout << "missing ";
			for (int i= 0; i< 26; i++)
			{
				if (!v[i])
					cout << (char)(i + 'a');
			}
		}
		cout << '\n';
	}

	return 0;
}