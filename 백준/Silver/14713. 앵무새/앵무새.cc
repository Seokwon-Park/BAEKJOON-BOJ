#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int b[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	set<string> s;
	int n;
	cin >> n;
	cin.ignore();
	queue<string> q[100];
	for (int i = 0; i < n; i++)
	{	
		string str;
		getline(cin, str);
		istringstream iss(str);
		string tmp;
		while (getline(iss, tmp, ' '))
		{
			q[i].push(tmp);
		}
	}

	string str2;
	getline(cin, str2);
	istringstream iss(str2);
	string tmp;
	vector<string> v;
	while (getline(iss, tmp, ' '))
	{
		v.push_back(tmp);
	}
		
	for (int i = 0; i < v.size(); i++)
	{
		string word = v[i];
		bool isFind = false;
		for (int j = 0; j < n; j++)
		{
			if (q[j].empty()) continue;
			if (q[j].front() == word)
			{
				q[j].pop();
				isFind = true;
				break;
			}
		}
		if (!isFind)
		{
			cout << "Impossible";
			return 0;
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		if (!q[i].empty())
		{
			cout << "Impossible";
			return 0;
		}
	}

	cout << "Possible";
	return 0;
}