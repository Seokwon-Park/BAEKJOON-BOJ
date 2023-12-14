#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> pl;
	vector<int> mi;
	bool zero = false;
	
	int answer = 0;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		if (input == 1)
			answer += 1;
		else if (input > 0)
			pl.push_back(input);
		else if (input < 0)
			mi.push_back(input);
		else
			zero = true;
	}

	sort(pl.begin(), pl.end(), [](int a, int b) {return a > b; });
	sort(mi.begin(), mi.end());
	
	if (pl.size() % 2 == 0)
	{
		for (int i = 0; i < pl.size(); i += 2)
		{
			answer += pl[i] * pl[i + 1];
		}
	}
	else
	{
		for (int i = 0; i < pl.size()-1; i += 2)
		{
			answer += pl[i] * pl[i + 1];
		}
		answer += pl[pl.size() - 1];
	}

	if (mi.size() % 2 == 0)
	{
		for (int i = 0; i < mi.size(); i += 2)
		{
			answer += mi[i] * mi[i + 1];
		}
	}
	else
	{
		for (int i = 0; i < mi.size()-1; i += 2)
		{
			answer += mi[i] * mi[i + 1];
		}
		if (!zero)
		{
			answer += mi[mi.size() -1];
		}
	}


	cout << answer;

	return 0;
}