#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
string m[256];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		string s;
		char ch;
		cin >> s >> ch;
		m[ch] = s;
	}

	string str;
	cin >> str;
	string res = "";
	for (auto c : str)
	{
		res += m[c];
	}

	int s, e;
	cin >> s >> e;
	s--;
	e--;

	cout << res.substr(s, e - s+1);




	return 0;
}

