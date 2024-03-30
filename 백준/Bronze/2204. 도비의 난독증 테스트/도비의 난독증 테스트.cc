#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1)
	{
		int n;
		cin >> n;
		if (n == 0)break;
		vector<string> v(n);
		map<string, string> m;
		for (auto& s : v)
		{
			string word;
			cin >> word;
			string tmp;
			for (char c : word)
			{
				tmp += tolower(c);
			}
			s = tmp;
			m[tmp] = word;
		}
		cout << m[*min_element(v.begin(), v.end())] << '\n';
	}

	return 0;
}