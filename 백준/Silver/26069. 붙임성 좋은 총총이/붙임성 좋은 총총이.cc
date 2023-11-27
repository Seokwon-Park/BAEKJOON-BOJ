#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	map<string, bool> dancing;

	dancing["ChongChong"] = true;

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		string a, b;
		cin >> a >> b;
		if (dancing[a])
			dancing[b] = true;
		else if (dancing[b])
			dancing[a] = true;
		else
		{
			dancing[a] = false;
			dancing[b] = false;
		}
	}

	int answer = 0;
	for (auto itr = dancing.begin(); itr != dancing.end(); itr++)
	{
		if(itr->second)
			answer++;
	}
	cout << answer;

	return 0;
}
