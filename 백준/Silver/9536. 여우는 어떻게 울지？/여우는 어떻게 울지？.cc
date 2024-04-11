#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

vector<string> split(string str)
{
	istringstream iss(str);
	string tmp;
	vector<string> ret;
	while (getline(iss, tmp, ' '))
	{
		ret.push_back(tmp);
	}
	return ret;
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
		vector<string> rec;
		string s;
		getline(cin, s);
		rec = split(s);
		unordered_map<string, bool> um;
		while (1)
		{
			getline(cin, s);
			if (s == "what does the fox say?") break;
			vector<string> word = split(s);
			um[word[2]] = true;
		}
		for (int i = 0; i < rec.size(); i++)
		{
			if (!um[rec[i]])
			{
				cout << rec[i] << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}