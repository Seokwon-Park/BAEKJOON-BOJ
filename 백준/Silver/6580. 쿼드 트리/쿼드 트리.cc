#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int b[520][520];

string QuadTree(int x, int y, int n)
{
	if (n == 1)
	{
		return (b[y][x] == 1? "B" : "W");
	}
	int half = n / 2;
	string res1 = QuadTree(x, y, half);
	string res2 = QuadTree(x+half, y, half);
	string res3 = QuadTree(x, y+half, half);
	string res4 = QuadTree(x+half, y+half, half);
	if (res1 == res2 && res2 == res3 && res3 == res4 && res1.size() == 1)
	{
		return res1;
	}
	else
	{
		return 'Q' + res1 + res2 + res3 + res4;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	getline(cin, s);
	istringstream iss(s);
	string str;
	std::vector<string> v;
	while (getline(iss, str, ' '))
	{
		v.push_back(str);
	}
	int n = stoi(v[2]);
	getline(cin, s);
	getline(cin, s);
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < n / 8; j++)
		{
			int x = 0;
			string hs = s.substr(j * 5, 4);
			stringstream ss;
			ss << std::hex << hs;
			ss >> x;
			for (int k = 0; k < 8; k++)
			{
				b[i][j * 8 + k] = x % 2;
				x /= 2;
			}
		}
	}

	cout << n << '\n';
	cout << QuadTree(0, 0, n);

	return 0;
}