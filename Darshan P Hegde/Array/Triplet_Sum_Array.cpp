#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findTriplets(vector<int>& arr, int target) {
    int n = arr.size();
  
    sort(arr.begin(), arr.end());  

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && arr[i] == arr[i - 1])  
            continue;

        int left = i + 1, right = n - 1;

        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum == target) {
                cout << "Triplet: " << arr[i] << ", " << arr[left] << ", " << arr[right] << endl;
                while (left < right && arr[left] == arr[left + 1]) left++;  
                
                while (left < right && arr[right] == arr[right - 1]) right--;  
                right--;
            } 
            else if (sum < target) {
                left++; 
            } 
            else {
                right--;  
            }
        }
    }
}

int main() {
    vector<int> arr = {12, 3, 6, 9, 1, 7, 5, 11};
    int target = 24;
    
    findTriplets(arr, target);
    
    return 0;
}
