#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

string s = "1";
int n;

bool isValid(string& s, int& k)
{
	for (int j = 1; j <= (k + 1) / 2; j++)
	{
		string a = s.substr(s.size() - j);
		string b = s.substr(s.size() - j*2, j);
		if (a == b)
			return false;
	}
	return true;
}

void func(int k)
{
	if (k == n)
	{
		cout << s;
		exit(0);
	}
	for (int i = 1; i <= 3; i++)
	{
		s += (i + '0');
		if (!isValid(s, k))
		{
			s.pop_back();
			continue;
		}
		func(k + 1);
		s.pop_back();

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;

	func(1);

	return 0;
}