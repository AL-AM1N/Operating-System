#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    
    int arrivalTime[n], burstTime[n], completionTime[n], processID[n];
    float waitingTime[n], turnAroundTime[n]; 
    
    cout << "Enter arrival times: ";
    for (int i = 0; i < n; i++) {
        cin >> arrivalTime[i];
    }
    
    cout << "Enter burst times: ";
    for (int i = 0; i < n; i++) {
        cin >> burstTime[i];
    }

    // Assign process IDs (1 to n) 
    for (int i = 0; i < n; i++) {
        processID[i] = i + 1;
    }
    
    // Sorting processes based on burst time 
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (burstTime[i] > burstTime[j]) {
                // Swap burst times
                int temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;

                // Swap arrival times
                temp = arrivalTime[i];
                arrivalTime[i] = arrivalTime[j];
                arrivalTime[j] = temp;

                // Swap process IDs
                temp = processID[i];
                processID[i] = processID[j];
                processID[j] = temp;
            }
        }
    }  

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        // Process can start when it arrives
        if (currentTime < arrivalTime[i]) {
            currentTime = arrivalTime[i];
        }

        // Completion time
        completionTime[i] = currentTime + burstTime[i];

        // Turnaround time = Completion time - Arrival time
        turnAroundTime[i] = completionTime[i] - arrivalTime[i];

        // Waiting time = Turnaround time - Burst time
        waitingTime[i] = turnAroundTime[i] - burstTime[i];

        currentTime = completionTime[i];
    }
    float totalWaitingTime = 0, totalTurnAroundTime = 0;
    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
        cout << processID[i] << "\t" << arrivalTime[i] << "\t\t" << burstTime[i] << "\t\t" 
             << completionTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnAroundTime[i] << endl;
    }
    cout << "\nAverage Waiting Time: " << totalWaitingTime / n << endl;
    cout << "Average Turnaround Time: " << totalTurnAroundTime / n << endl;

    return 0;
}
