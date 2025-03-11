#include <iostream>
using namespace std;

int main() {
    int head = 50;
    int requests[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int n = sizeof(requests) / sizeof(requests[0]);
    bool visited[n] = {false};

    int totalSeekDistance = 0;
    int currentHead = head;

    cout << "Head Position: " << head << endl;
    cout << "Seek Sequence: " << head;

    for (int i = 0; i < n; i++) {
        int minSeekDistance = INT_MAX;
        int nextRequestIndex = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int seekDistance = abs(requests[j] - currentHead);
                if (seekDistance < minSeekDistance) {
                    minSeekDistance = seekDistance;
                    nextRequestIndex = j;
                }
            }
        }

        if (nextRequestIndex != -1) {
            visited[nextRequestIndex] = true;
            totalSeekDistance += minSeekDistance;
            currentHead = requests[nextRequestIndex];
            cout << " -> " << currentHead;
        }
    }

    cout << "\nTotal Seek Operation: " << totalSeekDistance << endl;

    return 0;
}