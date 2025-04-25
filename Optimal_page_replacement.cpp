#include<iostream>
using namespace std;

int findOptimal(int pages[], int n, int frames[], int index, int capacity) {
    int farthest = index;
    int pos = -1;
    for (int i = 0; i < capacity; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == n)
            return i;
    }
    if (pos == -1) return 0;
    else return pos;
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 4;

    int frames[4];
    int count = 0;
    int hit = 0, miss = 0;

    for (int i = 0; i < capacity; i++) {
        frames[i] = -1; 
    }

    cout << "Page Reference String: ";
    for (int i = 0; i < n; i++) {
        cout << pages[i] << " ";
    }
    cout << endl << endl;

    for (int i = 0; i < n; i++) {
        bool isHit = false;

       
        for (int j = 0; j < count; j++) {
            if (frames[j] == pages[i]) {
                isHit = true;
                break;
            }
        }

        if (isHit) {
            cout << pages[i] << " -> Hit" << endl;
            hit++;
        } else {
            cout << pages[i] << " -> Miss" << endl;
            miss++;
            if (count < capacity) {
                frames[count++] = pages[i];
            } else {
                int pos = findOptimal(pages, n, frames, i + 1, capacity);
                frames[pos] = pages[i];
            }
        }
    }

    cout << "\nTotal Hit = " << hit << endl;
    cout << "Total Miss= " << miss << endl;

    return 0;
}
