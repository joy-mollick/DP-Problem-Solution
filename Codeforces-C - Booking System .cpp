#include<bits/stdc++.h>

using namespace std;

// It is actually dp problem but you can do it by greedy algorithm

const int N = 1000 + 10;

int n, k;
int c[N], p[N], r[N];
int vis[N];
pair<int, int> b[N];
pair< pair<int, int>, int> a[N];

void solve()
{
	cin >> n;
	for(int i = 0; i < n; ++ i) {
		cin >> c[i] >> p[i];
		a[i] = make_pair(make_pair(p[i], - c[i]), i);
	}
	sort(a, a + n);
	cin >> k;
	for(int i = 0; i < k; ++ i) {
		cin >> r[i];
		b[i] = make_pair(r[i], i);
	}
	sort(b, b + k);

	int ret = 0;
	vector< pair<int, int> > vec;

	for(int i = n - 1; i >= 0; -- i) {
		int tmp = -a[i].first.second;

		for(int j = 0; j < k; ++ j) {
			if (b[j].first >= tmp && ! vis[j]) {
				vis[j] = true;
				ret += a[i].first.first;
				vec.push_back(make_pair(a[i].second + 1, b[j].second + 1));
				break;
			}
		}
	}
	cout << vec.size() << ' ' << ret << endl;
	for(int i = 0; i < vec.size(); ++ i) {
		cout << vec[i].first << ' ' << vec[i].second << endl;
	}
}

int main()
{
	solve();
	return 0;
}
