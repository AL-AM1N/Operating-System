#include<iostream>
using namespace std;

int main() {
    
    int pages[] = {1,3,0,3,5,6,3};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frame_size = 3;
    
    int frames[frame_size];  
    bool hit;
    int hits = 0, misses = 0;
    
    
    for (int i = 0; i < frame_size; i++) {
        frames[i] = -1;
    }
    
    int index = 0;  
    
   
    for (int i = 0; i < n; i++) {
        hit = false;
        
        
        for (int j = 0; j < frame_size; j++) {
            if (frames[j] == pages[i]) {
                hit = true;
                hits++;
                break;
            }
        }
        
        
        if (!hit) {
            misses++;
            frames[index] = pages[i];
            index = (index + 1) % frame_size;  
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
