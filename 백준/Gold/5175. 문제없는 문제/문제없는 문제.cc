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

int v[25];
int n, m;
string res;
vector<string> results;

void func(int x, int cur)
{
	if (x == n)
	{
		if (cur == (1 << m) - 1)
		{
			results.push_back(res);
		}
		return;
	}
	func(x + 1, cur);

	res.push_back('A' + x);
	func(x + 1, cur | v[x]);
	res.pop_back();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> k;
	for(int tc = 1; tc<=k; tc++)
	{
		cin >> m >> n;
		cin.ignore();
		fill(v, v + n, 0);
		results.clear();
		res.clear();
		for (int i = 0; i < n; i++)
		{
			string s;
			getline(cin, s);
			istringstream iss(s);
			string tmp;
			while (getline(iss, tmp, ' '))
			{
				int shift = stoi(tmp);
				v[i] += 1 << (shift-1);
			}
		}
		cout << "Data Set " << tc << ": ";
		func(0, 0);
		string s = *min_element(results.begin(), results.end(), [](const string& a, const string& b)
			{
				if (a.size() == b.size())
				{
					return a < b;
				}
				return a.size() < b.size();
			});
		for (auto c : s)cout << c << ' ';

		cout << "\n\n";
	}


	return 0;
}