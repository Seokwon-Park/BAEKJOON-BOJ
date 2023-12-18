#include <bits/stdc++.h>

using namespace std;

int board[25][25];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    vector<int> people(n);
    iota(people.begin(), people.end(), 0);

    vector<int> pick(n, 1);
    fill(pick.begin(), pick.begin() + n / 2, 0);

    int min_val = INT_MAX;

    do {
        vector<int> start;
        vector<int> link;
        int startsum = 0;
        int linksum = 0;

        for (int i = 0; i < n; i++) {
            if (pick[i] == 1)
                start.push_back(people[i]);
            else
                link.push_back(people[i]);
        }

        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                if (i != j) {
                    startsum += board[start[i]][start[j]];
                    linksum += board[link[i]][link[j]];
                }
            }
        }

        int sub = abs(startsum - linksum);
        min_val = min(min_val, sub);
    } while (next_permutation(pick.begin(), pick.end()));

    cout << min_val;

    return 0;
}