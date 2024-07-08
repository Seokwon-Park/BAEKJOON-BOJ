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

	for (int i = 1; i <= n; i++)
	{
		string s;
		getline(cin, s);

		vector<int> v(26, 0);
		for (auto c : s)
		{
			if (isalpha(c))
			{
				c = tolower(c);
				v[c - 'a']++;
			}
		}
		
		int res = *min_element(v.begin(), v.end());
		cout << "Case " << i << ": ";
		if (res == 0)
			cout << "Not a pangram";
		else if (res == 1)
			cout << "Pangram!";
		else if (res == 2)
			cout << "Double pangram!!";
		else
			cout << "Triple pangram!!!";
		cout << '\n';
	}



	return 0;
}