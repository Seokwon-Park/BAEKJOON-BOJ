#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

bool cup[3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
			
	cup[0] = true;

	for (auto c : s)
	{
		if (c == 'A')
			swap(cup[0], cup[1]);
		else if( c == 'B')
			swap(cup[1], cup[2]);
		else
			swap(cup[0], cup[2]);
	}

	for (int i = 0; i < 3; i++)
	{
		if (cup[i])
			cout << i + 1;
	}

	return 0;
}
