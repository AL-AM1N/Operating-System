#include <iostream>
using namespace std;

int main() {
    int n = 3; 

    
    string process[] = {"P0", "P1", "P2"};
    int arrival[] = {2, 0, 4};
    int burst[] = {5, 3, 4};
    
    int completion[n], turnaround[n], waiting[n];
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrival[j] > arrival[j + 1]) {
                swap(arrival[j], arrival[j + 1]);
                swap(burst[j], burst[j + 1]);
                swap(process[j], process[j + 1]);
            }
        }
    }

    int start_time = 0;
    for (int i = 0; i < n; i++) {
        if (start_time < arrival[i])
            start_time = arrival[i]; 
        
        completion[i] = start_time + burst[i];
        turnaround[i] = completion[i] - arrival[i]; 
        waiting[i] = turnaround[i] - burst[i]; 

        start_time = completion[i]; 
    } 

    cout << "Process | Arrival | Burst | Completion | Turnaround | Waiting\n";
    for (int i = 0; i < n; i++) {
        cout << process[i] << "\t    "
             << arrival[i] << "\t    "
             << burst[i] << "\t    "
             << completion[i] << "\t\t  "
             << turnaround[i] << "\t\t "
             << waiting[i] << endl;
    }
    return 0;
}
