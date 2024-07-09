//WAP to convert Binary number to Decimal number.
#include<iostream>
#include<conio.h>

using namespace std;

int binary_to_decimal(int);

int main(){
	int binary,decimal;
	cout<<"Enter the Binary number: ";
	cin>>binary;
	decimal=binary_to_decimal(binary);
	cout<<"The decimal converted number is: "<<decimal;
	getch();
	return 0;
}

int binary_to_decimal(int binary){
	int decimal=0,lsb,multiplier=1;
	while(binary!=0){
		lsb=binary%10;
		decimal=decimal+lsb*multiplier;
		multiplier=multiplier*2;
		binary=binary/10;
	}
	return decimal;
}

//NOTE: In order to convert long numbers change the data type of binary to long long int
