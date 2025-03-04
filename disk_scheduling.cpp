#include <iostream>
using namespace std;

int main() {

    int head = 50;


    int requests[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int n = sizeof(requests) / sizeof(requests[0]);


    int totalSeekDistance = 0;
    int currentHead = head;


    cout << "Initial Head Position: " << head << endl;
    cout << "Seek Sequence: " << head;


    for (int i = 0; i < n; i++) {

        int seekDistance = (requests[i] > currentHead) ? (requests[i] - currentHead) : (currentHead - requests[i]);


        totalSeekDistance += seekDistance;


        currentHead = requests[i];


        cout << " -> " << currentHead;
    }


    cout << "\nTotal Seek Distance: " << totalSeekDistance << endl;

    return 0;
}
