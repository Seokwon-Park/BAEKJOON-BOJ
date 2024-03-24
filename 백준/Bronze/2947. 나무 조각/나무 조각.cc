#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void print(const vector<int>& v)
{
	for (int i : v)
		cout << i << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> v(5);
	for (int& i : v)
		cin >> i;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5-i-1; j++)
		{
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j + 1]);
				print(v);
			}
		}
	}
	return 0;
}