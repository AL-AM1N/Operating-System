#include<iostream>
using namespace std;

int main() {

    int pages[] = {0, 1, 5,3,5, 0, 2, 4, 7, 9, 0, 0, 3};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frame_size = 3;

    int frames[frame_size];
    int age[frame_size]; 
    int hits = 0, misses = 0;

    for (int i = 0; i < frame_size; i++) {
        frames[i] = -1;
        age[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        bool hit = false;

    
        for (int j = 0; j < frame_size; j++) {
            if (frames[j] != -1) {
                age[j]++;
            }
        }

        
        for (int j = 0; j < frame_size; j++) {
            if (frames[j] == pages[i]) {
                hit = true;
                hits++;
                age[j] = 0; 
                break;
            }
        }

       
        if (!hit) {
            misses++;

            int lru_index = 0;
            int max_age = -1;

           
            for (int j = 0; j < frame_size; j++) {
                if (frames[j] == -1) {
                    lru_index = j;
                    break;
                }
                if (age[j] > max_age) {
                    max_age = age[j];
                    lru_index = j;
                }
            }

            frames[lru_index] = pages[i];
            age[lru_index] = 0;
        }

        
        cout << "Frames after reference " << pages[i] << ": ";
        for (int j = 0; j < frame_size; j++) {
            cout << frames[j] << " ";
        }
        cout << endl;
    }

    cout << "Hits: " << hits << endl;
    cout << "Misses: " << misses << endl;

    return 0;
}
