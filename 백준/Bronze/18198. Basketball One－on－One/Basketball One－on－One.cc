#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int a = 0;
	int b = 0;
	for (int i = 0; i < s.size(); i += 2)
	{
		char team = s[i];
		int score = s[i+1]-'0';
		if (team == 'A')
			a += score;
		else
			b += score;
		if (a >= 10 && b >= 10)
		{
			if (a - b >= 2)
			{
				cout << 'A';
				return 0;
			}
			else if (b -a >= 2)
			{
				cout << 'B';
				return 0;
			}
		}
		else
		{
			if (a >= 11)
			{
				cout << 'A';
				return 0;
			}
			else if (b >= 11)
			{
				cout << 'B';
				return 0;
			}
		}
	}

	return 0;
}
