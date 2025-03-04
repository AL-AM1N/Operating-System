#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int process[] = {1, 2, 3, 4};
    int priority[] = {10, 20, 30, 40};
    int AT[] = {0, 1, 2, 4};
    int BT[] = {5, 4, 2, 1};
    int CT[n], TAT[n], WT[n];
    int remainingBT[n];


    for (int i = 0; i < n; i++) {
        remainingBT[i] = BT[i];
    }

    int currentTime = 0;
    int completed = 0;

    while (completed != n) {
        int highestPriority = -1;
        int highestPriorityIndex = -1;


        for (int i = 0; i < n; i++) {
            if (AT[i] <= currentTime && remainingBT[i] > 0) {
                if (highestPriority == -1 || priority[i] > highestPriority) {
                    highestPriority = priority[i];
                    highestPriorityIndex = i;
                }
            }
        }

        if (highestPriorityIndex == -1) {
            currentTime++;
        } else {
            remainingBT[highestPriorityIndex]--;
            currentTime++;

            if (remainingBT[highestPriorityIndex] == 0) {
                completed++;
                CT[highestPriorityIndex] = currentTime;
                TAT[highestPriorityIndex] = CT[highestPriorityIndex] - AT[highestPriorityIndex];
                WT[highestPriorityIndex] = TAT[highestPriorityIndex] - BT[highestPriorityIndex];
            }
        }
    }


    cout << "Process\tCT\tTAT\tWT" << endl;
    for (int i = 0; i < n; i++) {
        cout << process[i] << "\t" << CT[i] << "\t" << TAT[i] << "\t" << WT[i] << endl;
    }

    return 0;
}
