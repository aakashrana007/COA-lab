// AAKASH RANA [KAN078BCT004]
// Binary Division using Restoring Division Algorithm

#include <iostream>
#include <conio.h>

using namespace std;

// Function prototypes
int add(int*, int*, int*, int);
void get_twos_complement(int*, int*, int);
void shift_left(int*, int*, int);

int main() {
    int i, n;
    cout << "Enter the number of bits: ";
    cin >> n;

    // Dynamically allocate memory for dividend, divisor, accumulator, and two's complement of the divisor
    int *Q = new int[n];     // Dividend; the number being divided
    int *M = new int[n + 1]; // Divisor; the number dividing
    int *A = new int[n + 1]; // Accumulator
    int *M2C = new int[n + 1]; // Two's complement of the divisor

    // Input the dividend
    cout << "Enter the dividend (separate by space): ";
    for (int i = 0; i < n; i++) {
        cin >> Q[i];
    }

    // Initialize the MSB of divisor and accumulator to 0
    M[0] = A[0] = 0;

    // Input the divisor
    cout << "Enter the divisor (separate by space): ";
    for (i = 0; i < n; i++) {
        cin >> M[i + 1];
    }

    // Compute the two's complement of the divisor
    get_twos_complement(M, M2C, n + 1);

    // Perform the restoring division algorithm
    for (int count = n; count > 0; count--) {
        // Shift the accumulator and dividend left by one bit
        shift_left(A, Q, n);

        // Subtract divisor (M) from accumulator (A) using two's complement (A = A - M)
        add(A, M2C, A, n + 1);

        // If the result is negative, restore the value of A and set Q[n-1] to 0
        if (A[0] == 1) {
            Q[n - 1] = 0;
            add(A, M, A, n + 1); // Restore A (A = A + M)
        } 
        // If the result is positive, set Q[n-1] to 1
        else {
            Q[n - 1] = 1;
        }
    }

    // Output the quotient
    cout << "The quotient is: ";
    for (i = 0; i < n; i++) {
        cout << Q[i];
    }

    // Output the remainder
    cout << "\nThe remainder is: ";
    for (i = 0; i <= n; i++) {
        cout << A[i];
    }

    delete[] Q; // Free dynamically allocated memory
    delete[] M;
    delete[] A;
    delete[] M2C;

    getch();
    return 0;
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

// Function to add two binary numbers
int add(int *binary1, int *binary2, int *sum, int n) {
    int carry = 0, ones_count;
    for (int i = n - 1; i >= 0; i--) {
        ones_count = binary1[i] + binary2[i] + carry;
        sum[i] = ones_count % 2;    // Store the sum bit
        carry = ones_count / 2;     // Determine the carry for the next bit
    }
    return carry;   // Return the carry
}

// Function to perform a left shift on the accumulator and dividend
void shift_left(int* accumulator, int* dividend, int n) {
    // Shift the accumulator left by one bit
    for (int i = 0; i < n; i++) {
        accumulator[i] = accumulator[i + 1];
    }
    accumulator[n] = dividend[0]; // Move the MSB of the dividend to the LSB of the accumulator

    // Shift the dividend left by one bit
    for (int i = 0; i < n - 1; i++) {
        dividend[i] = dividend[i + 1];
    }
    dividend[n - 1] = 0; // Set the LSB of the dividend to 0
}

