// C++ program to find amount 
// of water in a given glass using queue
#include <bits/stdc++.h>
using namespace std;

double waterOverflow(int k, int r, int c) {
    
    r--;
    c--;

    // Initialize queue with total water units
    queue<double> q;
    q.push(1.0*k);

    // Variable to track overflow from previous glasses
    double prev = 0;

    // Simulate water flow row by row
    for (int i = 0; i <= r; i++) {
        
        // Process current row's glasses
        int size = q.size();
        for (int j = 0; j < size; j++) {
            
            // Get current glass water amount
            double curr = q.front();

            // Check if target glass is reached
            if (i == r && j == c) return min(curr, 1.0);

            // Reduce water in current glass
            curr--;
            q.pop();

            // Calculate and distribute overflow
            double val = max(curr/2.0, 0.0) + prev;
            q.push(val);

            // Track overflow for next iteration
            prev = max(0.0, curr/2.0);
        }

        // Add previous row's overflow to next row
        q.push(prev);
        prev = 0;
    }

    return 0;
}

int main() {
  
  	int k = 3;
    int r = 2;
    int c = 1;

    cout << waterOverflow(k, r, c);
    return 0;
}
