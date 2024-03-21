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

	string nm;
	cin >> nm;
	
	vi v(4);

	for (auto c : nm)
	{
		if (c == 'L')
			v[0]++;
		if (c == 'O')
			v[1]++;
		if (c == 'V')
			v[2]++;
		if (c == 'E')
			v[3]++;
	}
	int n;
	cin >> n;

	int mx = INT_MIN;
	string answer;

	for (int i = 0; i < n; i++)
	{
		vi vcopy = v;
		string s;
		cin >> s;
		for (auto c : s)
		{
			if (c == 'L')
				vcopy[0]++;
			if (c == 'O')
				vcopy[1]++;
			if (c == 'V')
				vcopy[2]++;
			if (c == 'E')
				vcopy[3]++;
		}

		int res = 1;
		for (int i = 0; i < 4; i++)
		{
			for (int j = i + 1; j < 4; j++)
			{
				res *= (vcopy[i] + vcopy[j]);
				res %= 100;
			}
		}
		if (res > mx)
		{
			answer = s;
			mx = res;
		}
		else if (res == mx)
		{
			if (answer > s)
			{
				answer = s;
			}
		}
	}
	cout << answer;
	
	return 0;
}