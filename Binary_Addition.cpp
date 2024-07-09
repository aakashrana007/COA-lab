//Aakash Rana[KAN078BCT004]
//Binary Addition

#include<iostream>
#include<conio.h>
using namespace std;
int add(int*, int*, int*, int);
int main(){
	int n,i;
	cout<<"Enter number of bits: ";
	cin>>n;
	// Dynamically allocate memory for binary numbers and their sum
	int *binary1 = new int[n];
	int *binary2 = new int[n];
	int *sum = new int[n];
	
	cout<<"enter the first binary number(seperate by space): ";
	for(i=0;i<n;i++){
		cin>>binary1[i];
	}
	
	cout<<"enter the second binary number(seperate by space): ";
	for(i=0;i<n;i++){
		cin>>binary2[i];
	}
	
	//the carry variable is used to store the return value from the add function,
	//which is the final carry-out of the binary addition.
	
	//if you donot need carry to display, you can simply call the add function without assigning to any variable
	//since the sum is a pointer and the sum gets updated itself in the memory
	int carry=add(binary1,binary2,sum,n); // Call add function to compute the sum of binary1 and binary2
	cout<<"The carry is: "<<carry<<endl;
	cout<<"The sum is: ";
	for(i=0;i<n;i++){
		cout<<sum[i];
	}
	getch();
	return 0;
}

int add(int* binary1, int* binary2, int* sum, int n) {
    int carry = 0, ones_count, i;
    
    // Iterate through the bits from least significant to most significant
    for (i = n - 1; i >= 0; i--) {
        // Calculate the number of 1s in the current position
        ones_count = binary1[i] + binary2[i] + carry;
        
        // Calculate the sum bit for the current position (0 or 1)
        sum[i] = ones_count % 2;
        
        // Calculate the carry for the next position
        carry = ones_count / 2;
    }
    sum[0]=carry;
    return carry;  // Return the final carry
}
