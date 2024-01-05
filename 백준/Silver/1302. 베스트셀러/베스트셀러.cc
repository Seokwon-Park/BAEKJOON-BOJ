#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	unordered_map <string, int> hsh;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		hsh[input]++;
	}

	cout << max_element(hsh.begin(), hsh.end(), [](auto& a, auto& b)
		{
			if (a.second == b.second)
			{
				return a.first > b.first;
			}
			return a.second < b.second;
		})->first;

	return 0;
}
