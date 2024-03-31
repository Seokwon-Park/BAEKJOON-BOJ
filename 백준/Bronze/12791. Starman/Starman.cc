#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	map<int, vector<string>> m;
	m[1967].push_back("DavidBowie");
	m[1969].push_back("SpaceOddity");
	m[1970].push_back("TheManWhoSoldTheWorld");
	m[1971].push_back("HunkyDory");
	m[1972].push_back("TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars");
	m[1973].push_back("AladdinSane");
	m[1973].push_back("PinUps");
	m[1974].push_back("DiamondDogs");
	m[1975].push_back("YoungAmericans");
	m[1976].push_back("StationToStation");
	m[1977].push_back("Low");
	m[1977].push_back("Heroes");
	m[1979].push_back("Lodger");
	m[1980].push_back("ScaryMonstersAndSuperCreeps");
	m[1983].push_back("LetsDance");
	m[1984].push_back("Tonight");
	m[1987].push_back("NeverLetMeDown");
	m[1993].push_back("BlackTieWhiteNoise");
	m[1995].push_back("1.Outside");
	m[1997].push_back("Earthling");
	m[1999].push_back("Hours");
	m[2002].push_back("Heathen");
	m[2003].push_back("Reality");
	m[2013].push_back("TheNextDay");
	m[2016].push_back("BlackStar");

	int tc;
	cin >> tc;
	while (tc--)
	{
		int s, e;
		cin >> s >> e;
		vector<pair<int,string>> ans;
		int cnt = 0;
		for (int i = s; i <= e; i++)
		{
			if (!m[i].empty())
			{
				for (auto str : m[i])
				{
					ans.push_back({ i, str });
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
		for (auto [year, title] : ans)
			cout << year << ' ' << title << '\n';

	}

	return 0;
}
