#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

int board[1005][6]; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	
	if (s.size() == 1)
	{
		cout << "NO";
		return 0;
	}

	int f = s[0] - '0';
	int r = 1;
	int zero = count(s.begin(), s.end(), '0');
	if (zero == 1)
	{
		cout << "NO";
		return 0;
	}
	else if (zero>1)
	{
		cout << "YES";
		return 0;
	}
	for (int i = 1; i < s.size(); i++)
	{
		r *= (s[i] - '0');
	}

	if (f == r)
	{
		cout << "YES";
		return 0;
	}

	int sep = 1;
	while (sep < s.size() - 1)
	{
		
		
		f *= (s[sep] - '0');
		r /= (s[sep] - '0');
		if (f == r)
		{
			cout << "YES";
			return 0;
		}
		sep++;
	}
	cout << "NO";

	return 0;
}
