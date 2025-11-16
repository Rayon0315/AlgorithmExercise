#include <iostream>
#include <vector>
using namespace std;

int m, n;
vector<int> order;
vector<vector<int>> nedMachine;
vector<vector<int>> workTime;
vector<int> nedWork;
vector<int> lastEndTime;
vector<vector<pair<int, int>>> machineSlots;

pair<int, int> findInsertSlot(int machine, int duration, int earliestStart) {
    int currentTime = earliestStart;
    
    for (int i = 0; i <= machineSlots[machine].size(); i++) {
        int gapStart = currentTime;
        int gapEnd = (i < machineSlots[machine].size()) ? machineSlots[machine][i].first : 1000000000;
        
        if (gapEnd - gapStart >= duration) {
            return {gapStart, gapStart + duration};
        }
        
        if (i < machineSlots[machine].size()) {
            currentTime = max(currentTime, machineSlots[machine][i].second);
        }
    }
    
    int startTime = max(currentTime, earliestStart);
    return {startTime, startTime + duration};
}

int main() {
    cin >> m >> n;

    order = vector<int>(m * n + 1, 0);
    nedMachine = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
    workTime = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
    nedWork = vector<int>(n + 1, 0);
    lastEndTime = vector<int>(n + 1, 0);
    machineSlots = vector<vector<pair<int, int>>>(m + 1);

    for (int i = 1; i <= m * n; i++) cin >> order[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> nedMachine[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> workTime[i][j];

    for (int i = 1; i <= m * n; i++) {
        int workpiece = order[i];
        int process = nedWork[workpiece] + 1;
        int machine = nedMachine[workpiece][process];
        int duration = workTime[workpiece][process];
        
        int earliestStart = lastEndTime[workpiece];
        
        auto [startTime, endTime] = findInsertSlot(machine, duration, earliestStart);
        
        bool inserted = false;
        for (auto it = machineSlots[machine].begin(); it != machineSlots[machine].end(); ++it) {
            if (it->first > startTime) {
                machineSlots[machine].insert(it, {startTime, endTime});
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            machineSlots[machine].push_back({startTime, endTime});
        }
        
        lastEndTime[workpiece] = endTime;
        nedWork[workpiece]++;
        
        // cout << "------------debug-----------\n";
        // cout << "process: " << i << "/" << m*n << endl;
        // cout << "workpiece: " << workpiece << endl;
        // cout << "process step: " << process << endl;
        // cout << "machine: " << machine << endl;
        // cout << "time needed: " << duration << endl;
        // cout << "start time: " << startTime << endl;
        // cout << "finish time: " << endTime << endl;
        // cout << "----------------------------\n\n";
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, lastEndTime[i]);
    }
    cout << ans;

    return 0;
}