#include<iostream>
using namespace std;
int main(){

int set1[] = {1, 2, 3, 4};
int set2[] = {3, 4, 5, 6};

int size1 = sizeof(set1) / sizeof(set1[0]);
int size2 = sizeof(set2) / sizeof(set2[0]);

int result[size1];
int k = 0;

// Iterate through set1
for (int i = 0; i < size1; i++) {
    // Check if current element is in set2
    for (int j = 0; j < size2; j++) {
        if (set1[i] == set2[j]) {
            result[k] = set1[i];
            k++;
            break;
        }
    }
}

// Print the result array
for (int i = 0; i < k; i++) {
    std::cout << result[i] << " ";
}
}

