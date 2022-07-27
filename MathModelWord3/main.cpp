#include <bits/stdc++.h>
using namespace std;

#define mms(a, b) memset(a, b, sizeof(a))

const int ETRANCE = 8, RELAY = 4, TOTAL = ETRANCE + RELAY;
const int INF = 0x3f3f3f3f;

//坐标点
struct Node {
	int x, y;
}p[8 + 4 + 1];

//边
struct Edge {
	int u, v;
	double w;

	friend bool operator < (Edge& a, Edge& b) {
		return a.w < b.w;
	}
};

//并查集
int pre[TOTAL + 1];
//答案
int ans = 0;
//邻接矩阵图
int G[TOTAL][TOTAL];
//边集
vector<Edge> edge;
//最终边
vector<Edge> draw;

//计算两点间距离
double getDist(Node& a, Node& b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

//查
int find(int x) {
	return pre[x] == x ? x : pre[x] = find(pre[x]);
}

//并
bool merge(int a, int b) {
	int fa = find(a), fb = find(b);
	if (fa != fb) {
		pre[fa] = fb;
		return true;
	}
	else
		return false;
}

void Floyd() {
	for (int k = 1; k <= TOTAL; ++k) {
		for (int i = 1; i <= TOTAL; ++i) {
			for (int j = 1; j <= TOTAL; ++j) {
				if (i == j && j == k && i == k)
					continue;
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
			}
		}
	}
}

bool check() {
	Floyd();

	for (int i = 1; i <= TOTAL; ++i) {
		for (int j = i + 1; j <= TOTAL; ++j) {
			if (G[i][j] > 1.4 * getDist(p[i], p[j])) {
				return false;
			}
		}
	}
	return true;
}

bool Kruskal() {
	int cnt = 0;
	for (auto i : edge) {
		int u = i.u, v = i.v, w = i.w;
		if (merge(u, v)) {
			draw.push_back(i);
			ans += w;
			cnt++;
			G[u][v] = w;
			G[v][u] = w;
		}
	}

	if (cnt == TOTAL - 1 && check()) {
		return true;
	}
	else {
		return false;
	}
}

void init() {
	//数据输入
	for (int i = 1; i <= TOTAL; ++i) {
		int x, y; cin >> x >> y;
		p[i] = Node{ x, y };
	}

	//并查集初始化
	for (int i = 1; i <= TOTAL; ++i) {
		pre[i] = i;
	}

	//图初始化
	mms(G, INF);
	for (int i = 1; i <= TOTAL; ++i) {
		for (int j = i + 1; j <= TOTAL; ++j) {
			Edge tmp = Edge{ i, j, getDist(p[i], p[j]) };
			edge.push_back(tmp);
		}
	}
	sort(edge.begin(), edge.end());
}

void solve() {
	if (Kruskal()) {
		cout << ans << endl;
		for (auto i : draw) {
			cout << i.u << "---" << i.v << endl;
		}
	}
	else {
		cout << "ga" << endl;
	}
}

signed main() {
	freopen("in.txt", "r", stdin);
	
	init();
	solve();

	return 0;
}