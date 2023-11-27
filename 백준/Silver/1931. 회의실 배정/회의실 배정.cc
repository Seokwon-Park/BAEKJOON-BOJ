#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	using namespace std;

	int n;
	vector<pair<int, int>> a;
	cin >> n;

	
	int start, end, i;
	for (i = 0; i < n; i++)
	{
		cin >> start >> end;
		a.push_back(make_pair(start, end));
	}
	sort(a.begin(), a.end(),
		[](pair<int, int>& a, pair<int, int>& b) {if (a.second == b.second) return a.first < b.first;
		return a.second < b.second; }
	);

	int min = 0;
	int cnt = 0;
	int first;
	for (i = 0; i < n; i++)
	{
		first = a.at(i).first;
		if (first >= min)
		{
			min = a.at(i).second;
			cnt++;
		}
	}

	cout << cnt;
		
	return 0;
}
