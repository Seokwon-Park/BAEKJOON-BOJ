#include <bits/stdc++.h>

using namespace std;

int arr[1000001];
vector<int> unic;
int n;

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	unic.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		unic[i] = arr[i];
	}
	sort(unic.begin(), unic.end());
	unic.erase(unique(unic.begin(), unic.end()), unic.end());

	for (int i = 0; i < n; i++)
	{
		cout << std::lower_bound(unic.begin(),unic.end(), arr[i])-(unic.begin()) << ' ';
	}
	return 0;
}
