#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int times[55];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	cin.ignore();
	for (int i = 1; i <= tc; i++)
	{
		string s;
		getline(cin, s);
		istringstream iss(s);
		string t;
		vector<string> ans;
		while (getline(iss, t, ' '))
		{
			ans.push_back(t);
		}
		cout << "Case #" << i << ": ";
		for (auto itr = ans.rbegin(); itr != ans.rend(); itr++)
			cout << *itr << ' ';
		cout << '\n';
	}

	return 0;
}
