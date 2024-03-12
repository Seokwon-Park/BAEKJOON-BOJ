#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string sem[7] = { "Algorithm", "DataAnalysis", "ArtificialIntelligence", "CyberSecurity", "Network", "Startup", "TestStrategy" };
	string clss[7] = { "204", "207", "302", "B101", "303", "501", "105" };
	unordered_map<string, string> um;
	for (int i = 0; i < 7; i++)
	{
		um[sem[i]] = clss[i];
	}

	int tc;
	cin >> tc;
	while (tc--)
	{
		string input;
		cin >> input;
		cout << um[input] << '\n';
	}

	return 0;
}