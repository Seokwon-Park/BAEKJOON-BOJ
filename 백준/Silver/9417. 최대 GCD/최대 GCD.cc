#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

vector<int> split(string& s)
{
	istringstream iss(s);
	vector<int> v;
	string tmp;
	while (getline(iss, tmp, ' '))
	{
		v.push_back(stoi(tmp));
	}
	return v;
}

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	cin.ignore();
	while (tc--)
	{
		int ans = 0;
		string s; 
		getline(cin, s);
		vector<int> v = split(s);

		for (int i = 0; i < v.size(); i++)
		{
			for (int j = i + 1; j < v.size(); j++)
			{
				ans = max(ans, gcd(v[i], v[j]));
			}
		}
		cout << ans;
		cout << '\n';
	}

	return 0;
}
