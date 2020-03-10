// NOTE: The ONLY files that should be #included for this assignment are iostream, vector, and string
// No other files should be #included

#include <iostream>
#include <vector>
#include <string>

// NOTE: The ONLY files that should be #included for this assignment are iostream, vector, and string
// No other files should be #included


using namespace std;

int bin_to_dec(string);
string dec_to_bin(int);
int hex_to_dec(string);
string dec_to_hex(int);



int main()
{
	// Sample Run 1
	cout<< "Sample Run 1" << endl;
	cout<<"10000011 binary = "<<bin_to_dec("10000011")<<" decimal\n"; // you should get 131
	cout<<"01010101 binary = "<<bin_to_dec("01010101")<<" decimal\n"; // you should get 85
	cout<<"1111111111111111 binary = "<<bin_to_dec("1111111111111111")<<" decimal\n"; // you should get 65,535
	cout<<"0111111111111111 binary = "<<bin_to_dec("0111111111111111")<<" decimal\n\n"; // you should get 32,767

	cout<<"255 decimal = "<<dec_to_bin(255)<<" binary\n"; //you should get 11111111
	cout<<"65532 decimal = "<<dec_to_bin(65532)<<" binary\n"; //you should get 1111111111111100
	cout<<"12 decimal = "<<dec_to_bin(12)<<" binary\n"; //you should get 1100
	cout<<"1000000 decimal = "<<dec_to_bin(1000000)<<" binary\n\n"; //you should get 11110100001001000000

	cout<<"ABC hexadecimal = "<<hex_to_dec("ABC")<<" decimal\n"; //you should get 2,748
	cout<<"F5 hexadecimal = "<<hex_to_dec("F5")<<" decimal\n"; //you should get 245
	cout<<"1234 hexadecimal = "<<hex_to_dec("1234")<<" decimal\n"; //you should get 4,660
	cout<<"FDECB hexadecimal = "<<hex_to_dec("FDECB")<<" decimal\n\n"; //you should get 1,040,075

	cout<<"512 decimal = "<<dec_to_hex(512)<<" hexadecimal\n"; //you should get 200
	cout<<"5000 decimal = "<<dec_to_hex(5000)<<" hexadecimal\n"; //you should get 1388
	cout<<"900000 decimal = "<<dec_to_hex(900000)<<" hexadecimal\n"; //you should get DBBA0
	cout<<"65525 decimal = "<<dec_to_hex(65525)<<" hexadecimal\n\n"; //you should get FFF5
	cout << endl;

	//Sample Run 2
	cout<< "Sample Run 2" << endl;
	cout<<"010011010100110 binary = "<<bin_to_dec("010011010100110")<<" decimal\n"; // you should get 9894
	cout<<"857 decimal = "<<dec_to_bin(857)<<" binary\n"; //you should get  01101011001
	cout<<"ABC hexadecimal = "<<hex_to_dec("ABC")<<" decimal\n"; //you should get 2,748
	cout<<"512 decimal = "<<dec_to_hex(512)<<" hexadecimal\n"; //you should get 200
	cout << endl;

	//Sample Run 3
	cout<< "Sample Run 3" << endl;
	cout<<"01110011000111110 binary = "<<bin_to_dec("01110011000111110")<<" decimal\n"; // you should get 58942
	cout<<"231 decimal = "<<dec_to_bin(231)<<" binary\n"; //you should get 011100111
	cout<<"ABC hexadecimal = "<<hex_to_dec("ABC")<<" decimal\n"; //you should get 2,748
	cout<<"512 decimal = "<<dec_to_hex(512)<<" hexadecimal\n"; //you should get 200
	cout << endl;

	//Sample Run 4
	cout<< "Sample Run 4" << endl;
	cout<<"01001010 binary = "<<bin_to_dec("01001010")<<" decimal\n"; // you should get 74
	cout<<"324 decimal = "<<dec_to_bin(324)<<" binary\n"; //you should get 0101000100
	cout<<"ABC hexadecimal = "<<hex_to_dec("ABC")<<" decimal\n"; //you should get 2,748
	cout<<"512 decimal = "<<dec_to_hex(512)<<" hexadecimal\n"; //you should get 200
	cout << endl;

	//Sample Run 5
	cout<< "Sample Run 5" << endl;
	cout<<"01010101101 binary = "<<bin_to_dec("01010101101")<<" decimal\n"; // you should get 685
	cout<<"932 decimal = "<<dec_to_bin(932)<<" binary\n"; //you should get  01110100100
	cout<<"ABC hexadecimal = "<<hex_to_dec("ABC")<<" decimal\n"; //you should get 2,748
	cout<<"512 decimal = "<<dec_to_hex(512)<<" hexadecimal\n"; //you should get 200
	cout << endl;

	system("PAUSE");
	return 0;

}

// Converts any UNsigned binary number to decimal

int bin_to_dec(string s)
{
	int decVal = 0, mult; //1. Since I couldn't include #cmath, I made a multiplier variable called "mult" to increase the bit value by power of 2 where necessary.

	for(int bit = 0; bit < s.size(); bit++){
		if(s.at(bit) == '1'){// 2. Increments DEC number if value is 1 based on the index in string
			mult = 1;
			for(int i = 0; i < s.size() - bit - 1; i++){ // 3. this loop is essentially: mult = pow(2, s.size() - bit)
				mult *= 2;
			}
			decVal += mult;
		}
	}

	return decVal;
}

//Converts any non-negative decimal number to binary

string dec_to_bin(int n)
{
	string binVal = "";
	int rem = 0;

	while (n > 0){ //4. Since n stores the quotient, the while loop runs until n is zero
		rem = n % 2;
		n = n / 2;
		//5. Using the ternary, the remainder is added to the string
		(rem) ? binVal.insert(0, "1") : binVal.insert(0, "0");
		//6. Note that using insert(), the bit is added to the front of the string!
	}

	return binVal;
}


//Converts any UNsigned hexadecimal number to decimal

int hex_to_dec(string s)
{
	int decVal = 0, mult;

	for(int bit = 0; bit < s.size(); bit++){
		//7. Switch case assigns proper value to multiplier
		switch(s.at(bit)){
			/*If bit is 0...9*/
			case 48: //8. If the bit is 0, the DEC number is not incremented.
				mult = 0;
				break;
			case 49:
			case 50:
			case 51:
			case 52:
			case 53:
			case 54:
			case 55:
			case 56:
			case 57:
				mult = s.at(bit) - 48;
				break;
			/*If bit is A...F*/
			case 65:
			case 66:
			case 67:
			case 68:
			case 69:
			case 70:
				mult = s.at(bit) - 55;
				break;
			default:
				cout << "error in hex_to_dec switch" << endl;
				break;
		}
		for(int i = 0; i < s.size() - bit - 1; i++){//9. this loop is essentially: mult = pow(16, s.size() - bit)
			mult *= 16;
		}
		decVal += mult;
	}
	return decVal;
}


//Converts any non-negative decimal number to hexadecimalConverts any non-negative decimal number to hexadecimal

string dec_to_hex(int n)
{
	string hexVal = "";
	int rem = 0;

	while (n > 0){
		rem = n % 16;
		n = n / 16;
		//10. Using the switch statement, the remainder is added to the string
		switch(rem){
			case 0:
				hexVal.insert(0,"0");
				break;
			case 1:
				hexVal.insert(0,"1");
				break;
			case 2:
				hexVal.insert(0,"2");
				break;
			case 3:
				hexVal.insert(0,"3");
				break;
			case 4:
				hexVal.insert(0,"4");
				break;
			case 5:
				hexVal.insert(0,"5");
				break;
			case 6:
				hexVal.insert(0,"6");
				break;
			case 7:
				hexVal.insert(0,"7");
				break;
			case 8:
				hexVal.insert(0,"8");
				break;
			case 9:
				hexVal.insert(0,"9");
				break;
			case 10:
				hexVal.insert(0,"A");
				break;
			case 11:
				hexVal.insert(0,"B");
				break;
			case 12:
				hexVal.insert(0,"C");
				break;
			case 13:
				hexVal.insert(0,"D");
				break;
			case 14:
				hexVal.insert(0,"E");
				break;
			case 15:
				hexVal.insert(0,"F");
				break;
			default:
				cout << "error in dec to hex switch" << endl;
				break;
		}
	}
	return hexVal;
}
