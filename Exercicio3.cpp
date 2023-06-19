#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

const double INF = 1e9;

struct Point {
    double x;
    double y;
};

double distance(const Point& p1, const Point& p2) {
    double dist = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    return dist;
}

double ClosestPair(vector<Point>& points, long long int p1, long long int p2) {
    if (p1 == p2) {
        return INF;
    } else if (p2 - p1 == 1) {
        return distance(points[p1], points[p2]);
    } else {
        long long int mid = (p1 + p2) / 2;
        double left = ClosestPair(points, p1, mid);
        double right = ClosestPair(points, mid + 1, p2);
        double dist = min(left, right);

        vector<Point> strip;
        double median = points[mid].x;

        for (long long int i = p1; i <= p2; i++) {
            if (abs(points[i].x - median) < dist) {
                strip.push_back(points[i]);
            }
        }

        sort(strip.begin(), strip.end(), [](const Point& p1, const Point& p2) {
            return p1.y < p2.y;
        });

        for (long long int i = 0; i < strip.size(); i++) {
            for (long long int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < dist; j++) {
                dist = min(dist, distance(strip[i], strip[j]));
            }
        }

        return dist;
    }
}

bool compare(const Point& p1, const Point& p2) {
    if (p1.x != p2.x) {
        return p1.x < p2.x;
    } else {
        return p1.y < p2.y;
    }
}

int main() {
    long long int N;
    while (cin >> N && N != 0) {
        vector<Point> points(N);
        for (long long int i = 0; i < N; i++) {
            cin >> points[i].x >> points[i].y;
        }

        sort(points.begin(), points.end(), compare);
        double dist = ClosestPair(points, 0, N - 1);

        if (dist >= 10000) {
            cout << "INFINITY" << endl;
        } else {
            cout << fixed << setprecision(4) << dist << endl;
        }
    }

    return 0;
}
