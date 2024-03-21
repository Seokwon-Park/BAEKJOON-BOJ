#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

vi fail(string s)
{
	int j = 0;
	vi f(s.size());
	for (int i = 1; i < s.size(); i++)
	{
		while (j > 0 && s[i] != s[j]) j = f[j - 1];
		if (s[i] == s[j]) f[i] = ++j;
	}
	return f;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	string p = "FBI";
	vi f = fail(p);
	bool isEx = false;
	vi answer;
	for (int ix = 0; ix < 5; ix++)
	{
		string s;
		cin >> s;
		int j = 0;
		for (int i = 0; i < s.size(); i++)
		{
			while (j > 0 && s[i] != p[j]) j = f[j - 1];
			if (s[i] == p[j]) j++;
			if (j == p.size())
			{
				answer.push_back(ix + 1);
				break;
			}
		}
	}
	if (answer.empty())
		cout << "HE GOT AWAY!";
	else
		for (auto i : answer)
			cout << i << ' ';

	return 0;
}