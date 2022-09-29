#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <string>
#include <queue>
#include <map>
#include <climits>
#include <string.h>


using namespace std;

struct Point {
    int n, m;

    Point() {
        n = m = 0;
    }

    Point(int n, int m) {
        this->n = n;
        (*this).m = m;
    }

    void set(int n, int m) {
        this->n = n;
        this->m = m;
    }

    void set(Point point) {
        this->n = point.n;
        this->m = point.m;
    }
};

struct Spin {
    int r, c, s;

    Spin() {
        r = c = s = 0;
    }

    Spin(int r, int c, int s) {
        this->r = r - 1;
        this->c = c - 1;
        this->s = s;
    }
};

const int MAX_SIZE = 50;
const int MAX_COUNT = 6;

// 순서대로 오른쪽, 아래쪽, 왼쪽, 위쪽 이동
const int dn[4] = {0, 1, 0, -1};
const int dm[4] = {1, 0, -1, 0};

int n, m, k;
int MAP[MAX_SIZE][MAX_SIZE];
int answer = INT_MAX;

Spin spins[MAX_COUNT];

bool isCorner(Point start, Point end, Point next) {
    if (next.n < start.n || next.n > end.n)
        return true;
    if (next.m < start.m || next.m > end.m)
        return true;

    return false;
}

void spinning(int MAP[MAX_SIZE][MAX_SIZE], Spin spins) {
    Point start = Point(spins.r - spins.s, spins.c - spins.s);
    Point end = Point(spins.r + spins.s, spins.c + spins.s);
    Point point = Point(start.n, start.m);
    Point next;
    int tmp1, tmp2;

    int move = 0;
    tmp2 = MAP[start.n][start.m];
    while (1) {
        // 바깥부터 돌다가 start 값과 end값이 같아지는 중앙에서 멈춰야함 !
        if (start.n == end.n && start.m == end.m)
            return;

        next.set(point.n + dn[move], point.m + dm[move]);
        if (isCorner(start, end, next)) {
            move++;
            // 내부 이동
            if (move >= 4) {
                start.set(start.n + 1, start.m + 1);
                end.set(end.n - 1, end.m - 1);


                move = 0;
                point.set(start);

                tmp2 = MAP[start.n][start.m];
                continue;
            }
        }
        next.set(point.n + dn[move], point.m + dm[move]);

        // 교환
        tmp1 = MAP[next.n][next.m];
        MAP[next.n][next.m] = tmp2;
        tmp2 = tmp1;

        // 포인터 이동
        point.set(next);
    }
}

int getValue(const int MAP[MAX_SIZE][MAX_SIZE]) {
    int minValue = INT_MAX;
    int add;
    for (int i = 0; i < n; i++) {
        add = 0;
        for (int j = 0; j < m; j++) {
            add += MAP[i][j];
        }
        if (minValue > add) {
            minValue = add;
        }
    }
    return minValue;
}

void setMin(int val) {
    if (answer > val) {
        answer = val;
    }
}

void findMin(const int MAP[MAX_SIZE][MAX_SIZE], const vector<int> list) {
    if (list.size() <= 0) {
        setMin(getValue(MAP));
    }

    for (int i = 0; i < list.size(); i++) {
        int MAPCopy[MAX_SIZE][MAX_SIZE];
        copy(&MAP[0][0], &MAP[0][0] + MAX_SIZE * MAX_SIZE, &MAPCopy[0][0]);

        vector<int> listCopy;
        listCopy.resize(list.size());
        copy(list.begin(), list.end(), listCopy.begin());

        spinning(MAPCopy, spins[listCopy[i]]);
        listCopy.erase(listCopy.begin() + i);

        findMin(MAPCopy, listCopy);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> MAP[i][j];
        }
    }

    int r, c, s;
    for (int i = 0; i < k; i++) {
        cin >> r >> c >> s;
        spins[i] = Spin(r, c, s);
    }

    vector<int> list;
    for (int i = 0; i < k; i++) {
        list.push_back(i);
    }
    findMin(MAP, list);

    cout << answer;

    return 0;
}
