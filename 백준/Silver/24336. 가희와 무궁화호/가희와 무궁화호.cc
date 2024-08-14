#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

unordered_map<string, double> dist = {
	{ "Seoul", 0.0 },
	{ "Yeongdeungpo", 9.1 },
	{ "Anyang", 23.9 },
	{ "Suwon", 41.5 },
	{ "Osan", 56.5 },
	{ "Seojeongri", 66.5 },
	{ "Pyeongtaek", 75.0 },
	{ "Seonghwan", 84.4 },
	{ "Cheonan", 96.6 },
	{ "Sojeongni", 107.4 },
	{ "Jeonui", 114.9 },
	{ "Jochiwon", 129.3 },
	{ "Bugang", 139.8 },
	{ "Sintanjin", 151.9 },
	{ "Daejeon", 166.3 },
	{ "Okcheon", 182.5 },
	{ "Iwon", 190.8 },
	{ "Jitan", 196.4 },
	{ "Simcheon", 200.8 },
	{ "Gakgye", 204.6 },
	{ "Yeongdong", 211.6 },
	{ "Hwanggan", 226.2 },
	{ "Chupungnyeong", 234.7 },
	{ "Gimcheon", 253.8 },
	{ "Gumi", 276.7 },
	{ "Sagok", 281.3 },
	{ "Yangmok", 289.5 },
	{ "Waegwan", 296.0 },
	{ "Sindong", 305.9 },
	{ "Daegu", 323.1 },
	{ "Dongdaegu", 326.3 },
	{ "Gyeongsan", 338.6 },
	{ "Namseonghyeon", 353.1 },
	{ "Cheongdo", 361.8 },
	{ "Sangdong", 372.2 },
	{ "Miryang", 381.6 },
	{ "Samnangjin", 394.1 },
	{ "Wondong", 403.2 },
	{ "Mulgeum", 412.4 },
	{ "Hwamyeong", 421.8 },
	{ "Gupo", 425.2 },
	{ "Sasang", 430.3 },
	{ "Busan", 441.7 }
};

unordered_map<string, int> start;
unordered_map<string, int> arrive;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		string s, st, en;
		cin >> s >> st >> en;
		if (i > 0)
		{
			int h = stoi(st.substr(0, 2));
			int m = stoi(st.substr(3));
			arrive[s] = m + h * 60;
		}
		if (i < n - 1)
		{
			int h = stoi(en.substr(0, 2));
			int m = stoi(en.substr(3));
			start[s] = m + h * 60;
		}
	}

	for (int i = 0; i < q; i++)
	{
		string st, en;
		cin >> st >> en;

		double d = abs(dist[en] - dist[st]);
		int tmp = 0;
		if (start[st] >= arrive[en])
		{
			tmp = arrive[en] + 24*60 - start[st];
		}
		else
		{
			tmp = arrive[en] - start[st];
		}

		double t = (double)tmp / 60.0;
		cout << fixed << setprecision(6);
		cout << d / t << '\n';

	}
	

	return 0;
}