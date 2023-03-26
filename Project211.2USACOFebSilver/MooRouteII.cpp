//
// Created by Kevin Yang on 2/25/23.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 200001;
int n, m;

typedef struct Flight {
    int end, departureTime, arrivalTime;

    Flight(int end, int departureTime, int arrivalTime) : end(end), departureTime(departureTime),
                                                          arrivalTime(arrivalTime) {}

    bool operator<(const Flight &other) const {
        return departureTime > other.departureTime;
    }
} Flight;

bool compArrivalTime(const Flight &a, const Flight &b) {
    return a.arrivalTime > b.arrivalTime;
}

vector<Flight> flights[N];
int transferTimes[N];
int arrivalTimes[N];
queue<int> q;
bool inQueue[N];
int flightIndex[N];

void init() {
    for (int i = 1; i <= n; i++) {
        arrivalTimes[i] = INT32_MAX;
    }
}

void spfa(int start) {
    arrivalTimes[start] = 0;
    q.push(start);
    inQueue[start] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        inQueue[cur] = false;
        int minDepartureTime = arrivalTimes[cur] + transferTimes[cur];
        if (cur == start) {
            minDepartureTime = 0;
        }
        for (; flightIndex[cur] < flights[cur].size(); flightIndex[cur]++) {
            Flight &nextFlight = flights[cur][flightIndex[cur]];
            if (nextFlight.departureTime < minDepartureTime) {
                break;
            }
            if (nextFlight.arrivalTime < arrivalTimes[nextFlight.end]) {
                arrivalTimes[nextFlight.end] = nextFlight.arrivalTime;
                if (!inQueue[nextFlight.end]) {
                    q.push(nextFlight.end);
                    inQueue[nextFlight.end] = true;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        int start, end, departureTime, arrivalTime;
        cin >> start >> departureTime >> end >> arrivalTime;
        flights[start].push_back(Flight(end, departureTime, arrivalTime));
    }
    for (int i = 1; i <= n; i++) {
        cin >> transferTimes[i];
        sort(flights[i].begin(), flights[i].end());
    }
    spfa(1);
    for (int i = 1; i <= n; i++) {
        if (arrivalTimes[i] == INT32_MAX) {
            cout << -1 << endl;
        } else {
            cout << arrivalTimes[i] << endl;
        }
    }
    return 0;
}