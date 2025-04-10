#include <iostream>
using namespace std;

void sort(int arr[], int n) {
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
             
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int requests[] = {0, 14, 41, 53, 65, 67, 98, 122, 124, 183, 199};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head = 53; 
    int size = 200;
    int total_movement = 0;

   
    sort(requests, n);

    
    int index = 0;
    while (index < n && requests[index] < head) {
        index++;
    }

    cout << "Order of servicing requests:\n";

    
    for (int i = index; i < n; i++) {
        cout << requests[i] << " ";
        total_movement += abs(head - requests[i]);
        head = requests[i];
    }

    
    if (index > 0) {
        total_movement += abs(head - (size - 1)); 
        head = 0; 
        total_movement += (size - 1); 
    }

   
    for (int i = 0; i < index; i++) {
        cout << requests[i] << " ";
        total_movement += abs(head - requests[i]);
        head = requests[i];
    }

    cout << "\nTotal head movement: " << total_movement << "\n";

    return 0;
}
