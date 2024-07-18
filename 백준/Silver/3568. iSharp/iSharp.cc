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

	string s;
	getline(cin, s);

	istringstream iss(s);
	vector<string> v;
	string tmp;
	while (getline(iss, tmp, ' '))
	{
		v.push_back(tmp);
	}

	for (int i = 1; i < v.size(); i++)
	{
		string var = v[i];
		string var_name = "";
		string var_add = "";
		for (int j = 0; j< var.size(); j++)
		{
			if (isalpha(var[j]))
				var_name += var[j];
			else
			{
				var_add = var.substr(j);
				break;
			}
		}
		var_add.pop_back(); // , ; 제거
		string res = "";
		for (int i = var_add.size()-1; i >= 0; i--)
		{
			if (var_add[i] == ']')
			{
				res += "[]";
				i--;
			}
			else
				res += var_add[i];
		}
		cout << v[0] << res << ' ' << var_name << ";\n";
	}

	return 0;
}
