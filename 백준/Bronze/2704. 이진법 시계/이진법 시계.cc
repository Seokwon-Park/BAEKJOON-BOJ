#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

string tobinary(int n)
{
	string res;
	while (n)
	{
		res += (n % 2) + '0';
		n /= 2;

	}

	res += string(6 - res.size(), '0');
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		int h = stoi(str.substr(0, 2));
		int m = stoi(str.substr(3, 2));
		int s = stoi(str.substr(6, 2));

		vector<string> v;
		v.push_back(tobinary(h));
		v.push_back(tobinary(m));
		v.push_back(tobinary(s));
		//string hh = tobinary(h);
		//string mm = tobinary(m);
		//string ss = tobinary(s);

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << v[j][i];
			}
		}
		cout << ' ';
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				cout << v[i][j];
			}
		}
		cout << '\n';

		
	}

	return 0;
}