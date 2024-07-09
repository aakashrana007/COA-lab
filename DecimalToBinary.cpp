//WAP to convert Decimal number to Binary number.
#include<iostream>
#include<conio.h>

using namespace std;

int decimal_to_binary(int);

int main(){
	int binary,decimal;
	cout<<"Enter the decimal number: ";
	cin>>decimal;
	binary=decimal_to_binary(decimal);
	cout<<"The binary converted number is: "<<binary;
	getch();
	return 0;
}

int decimal_to_binary(int decimal){
	int binary=0,lsb,multiplier=1;
	while(decimal!=0){
		lsb=decimal%2;
		binary=binary+lsb*multiplier;
		multiplier=multiplier*10;
		decimal=decimal/2;
	}
	return binary;
}

//NOTE: In order to convert long numbers change the data type of binary to long long int
