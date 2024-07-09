// AAKASH RANA [KAN078BCT004]
// Binary Multiplication

#include<iostream>
#include<conio.h>

using namespace std;

// Function prototypes
int add(int *, int *, int *, int);
void shift_left(int *, int);
void multiply(int *, int *, int *, int);

int main() {
    int n, i;
    cout << "Enter the number of bits: ";
    cin >> n;

    // Dynamically allocate memory for multiplicant, multiplier, and product
    int *multiplicant = new int[n];
    int *multiplier = new int[n];
    int *product = new int[2 * n];   // Since two n-bit numbers multiplied, product is 2n bits

    cout << "Enter the multiplicant: ";
    for (i = 0; i < n; i++) {
        cin >> multiplicant[i];
    }

    cout << "Enter the multiplier: ";
    for (i = 0; i < n; i++) {
        cin >> multiplier[i];
    }

    // Initialize product array with zeros
    for (i = 0; i < 2 * n; i++) {
        product[i] = 0;
    }

    // Call multiply function to compute the product of multiplicant and multiplier
    multiply(multiplicant, multiplier, product, n);

    // Output the product array
    cout << "Product of the numbers is: ";
    for (i = 0; i < 2 * n; i++) {
        cout << product[i];
    }

    delete[] multiplicant;  // Free dynamically allocated memory
    delete[] multiplier;
    delete[] product;

    getch();
    return 0;
}

// Function to perform binary multiplication
void multiply(int *multiplicant, int *multiplier, int *product, int n) {
    int *shifted_multiplicant = new int[2 * n];   // Array to store shifted multiplicant

    // Initialize shifted_multiplicant array with zeros
    for (int i = 0; i < 2 * n; i++) {
        shifted_multiplicant[i] = (i < n) ? 0 : multiplicant[i - n];
    }

    // Perform multiplication using binary multiplication algorithm
    for (int i = n - 1; i >= 0; i--) {
        if (multiplier[i]) {
            add(product, shifted_multiplicant, product, 2 * n); // Add shifted multiplicant to product
        }
        shift_left(shifted_multiplicant, 2 * n); // Shift the multiplicant left by 1 bit
    }

    delete[] shifted_multiplicant;  // Free dynamically allocated memory
}

// Function to perform left shift operation on a binary array
void shift_left(int *binary_array, int n) {
    for (int i = 0; i <= n - 2; i++) {
        binary_array[i] = binary_array[i + 1];   // Shift each element left by one position
    }
    binary_array[n - 1] = 0;    // Set the last element to 0 (left shift operation)
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

