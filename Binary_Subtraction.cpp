// Aakash Rana[KAN078BCT004]
// Binary Subtraction

#include<iostream>
#include<conio.h>
using namespace std;

// Function prototypes
int add(int*, int*, int*, int);
int sub(int*, int*, int*, int);
void get_twos_complement(int*, int*, int);

int main() {
    int n, i;
    cout << "Enter number of bits: ";
    cin >> n;

    // Dynamically allocate memory for binary numbers and their difference
    int* binary1 = new int[n];
    int* binary2 = new int[n];
    int* diff = new int[n];

    cout << "Enter the first binary number (separate by space): ";
    for (i = 0; i < n; i++) {
        cin >> binary1[i];
    }

    cout << "Enter the second binary number (separate by space): ";
    for (i = 0; i < n; i++) {
        cin >> binary2[i];
    }

    // Call sub function to compute the difference of binary1 and binary2
    int carry = sub(binary1, binary2, diff, n);
    cout<<"The borrow is: "<<carry<<endl;

    // If carry is 1, the result is non-negative, and we display the difference directly
    if (carry == 1) {
        cout << "The difference is: ";
        for (i = 0; i < n; i++) {
            cout << diff[i];
        }
    } else { // If carry is 0, the result is negative, and we need the two's complement of the difference
        int* tc_diff = new int[n];
        get_twos_complement(diff, tc_diff, n);
        cout << "The difference is: -";
        for (i = 0; i < n; i++) {
            cout << tc_diff[i];
        }
        delete[] tc_diff; // Free dynamically allocated memory
    }

    delete[] binary1; // Free dynamically allocated memory
    delete[] binary2;
    delete[] diff;

    getch();
    return 0;
}

// Function to add two binary numbers
int add(int* binary1, int* binary2, int* sum, int n) {
    int carry = 0, ones_count, i;
    for (i = n - 1; i >= 0; i--) {
        ones_count = binary1[i] + binary2[i] + carry;
        sum[i] = ones_count % 2;
        carry = ones_count / 2;
    }
    return carry;
}

// Function to get the two's complement of a binary number
void get_twos_complement(int* binary, int* tc_binary, int n) {
    int* ones_complement = new int[n];
    // Calculate the one's complement by flipping the bits
    for (int i = 0; i < n; i++) {
        ones_complement[i] = binary[i] ^ 1;
    }
    // Add 1 to the one's complement to get the two's complement
    int* one = new int[n]();
    one[n - 1] = 1; // Last bit is 1, rest are 0
    add(ones_complement, one, tc_binary, n);

    delete[] ones_complement; // Free dynamically allocated memory
    delete[] one;
}

// Function to subtract two binary numbers using two's complement method
int sub(int* binary1, int* binary2, int* diff, int n) {
    int carry;
    int* tc_binary2 = new int[n];
    // Get the two's complement of the second binary number
    get_twos_complement(binary2, tc_binary2, n);
    // Add the first binary number to the two's complement of the second binary number
    carry = add(binary1, tc_binary2, diff, n);
    delete[] tc_binary2; // Free dynamically allocated memory
    return carry; // Return the carry to determine if the result is negative or not
}

