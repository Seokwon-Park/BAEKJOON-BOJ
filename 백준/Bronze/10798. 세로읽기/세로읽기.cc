#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	size_t len_sum = 0;
	
	vector<string> vs(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> vs[i];
		len_sum += vs[i].length();
	}

	string new_str;
	int len = 0;
	int cursor = 0;
	while (len != len_sum)
	{
		for (int i = 0; i < 5; i++)
		{
			if (cursor < vs[i].length())
			{
				new_str.push_back(vs[i][cursor]);
				len++;
			}
		}
		cursor++;
	}
	cout << new_str;

	return 0;
}