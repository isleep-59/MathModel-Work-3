#include <bits/stdc++.h>
using namespace std;

#define mms(a, b) memset(a, b, sizeof(a))

const int ETRANCE = 8, RELAY = 4, TOTAL = ETRANCE + RELAY;
const int INF = 0x3f3f3f3f;

//�����
struct Node {
	int x, y;
}p[8 + 4 + 1];

//��
struct Edge {
	int u, v;
	double w;

	friend bool operator < (Edge& a, Edge& b) {
		return a.w < b.w;
	}
};

//���鼯
int pre[TOTAL + 1];
//��
int ans = 0;
//�ڽӾ���ͼ
int G[TOTAL][TOTAL];
//�߼�
vector<Edge> edge;
//���ձ�
vector<Edge> draw;

//������������
double getDist(Node& a, Node& b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

//��
int find(int x) {
	return pre[x] == x ? x : pre[x] = find(pre[x]);
}

//��
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
	//��������
	for (int i = 1; i <= TOTAL; ++i) {
		int x, y; cin >> x >> y;
		p[i] = Node{ x, y };
	}

	//���鼯��ʼ��
	for (int i = 1; i <= TOTAL; ++i) {
		pre[i] = i;
	}

	//ͼ��ʼ��
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