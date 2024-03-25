#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	istringstream iss(s);
	string tmp;
	vector<int> v;
	while (getline(iss, tmp, ','))
	{
		v.push_back(stoi(tmp));
	}

	while (k--)
	{
		vector<int> nv(v.size() - 1);
		for (int i = 0; i < v.size() - 1; i++)
		{
			nv[i] = v[i + 1] - v[i];
		}
		v = nv;
	}
	
	
	cout << v[0];
	for (int i = 1; i < v.size(); i++)
	{
		cout << ',' << v[i];
	}
		

	return 0;
}