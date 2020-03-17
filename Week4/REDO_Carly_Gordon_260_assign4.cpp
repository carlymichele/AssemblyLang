// NOTE: The ONLY files that should be #included for this assignment are iostream, vector, and string
// No other files should be #included

#include <iostream>
#include <vector>
#include <string>

// NOTE: The ONLY files that should be #included for this assignment are iostream, vector, and string
// No other files should be #included
#include <cmath>


using namespace std;


string addbin(string, string);
string addhex(string, string);

string multbin(string, string);
string multhex(string, string);

int main()
{

	cout<<"binary 10001 * 11 = "<<multbin("10001", "11")<<endl; //you should get 110011
	cout<<"binary 100 * 110001 = "<<multbin("100", "11001")<<endl; //you should get 1100100
	cout<<"binary 110 * 1010 = "<<multbin("110", "1010")<<endl; //you should get 111100
	cout<<"binary 11111111 * 10 = "<<multbin("11111111", "10")<<endl; //you should get 111111110
	cout<<"binary 10101010 * 1 = "<<multbin("10101010", "1")<<endl;  //you should get 10101010
	cout<<"binary 0 * 11110000 = "<<multbin("0", "11110000")<<endl<<endl; //you should get 0

	cout<<"hexadecimal F * A = "<<multhex("F", "A")<<endl; //you should get 96
	cout<<"hexadecimal 1A * 5 = "<<multhex("1A", "5")<<endl; //you should get 82
	cout<<"hexadecimal FF * 2 = "<<multhex("FF", "2")<<endl; //you should get 1FE
	cout<<"hexadecimal 104 * 3 = "<<multhex("104", "3")<<endl; //you should get 30C
	cout<<"hexadecimal FABC * 1 = "<<multhex("FABC", "1")<<endl; //you should get FABC
	cout<<"hexadecimal 0 * EFDCAB = "<<multhex("0", "EFDCAB")<<endl<<endl; //you should get 0

	cout<<"Sample Run 1" << endl;
	cout<<"binary 110110 * 11 = "<<multbin("110110", "11")<<endl;   //you should get 10100010
	cout<<"hexadecimal 1B0 * 34 = "<<multhex("1B0", "34")<<endl<<endl;  //you should get 57C0

	cout<<"Sample Run 2" << endl;
	cout<<"binary 101 * 10000001 = "<<multbin("101", "10000001")<<endl;   //you should get 1010000101
	cout<<"hexadecimal A7774 * D = "<<multhex("A7774", "D")<<endl<<endl;  //you should get 8810E4

	cout<<"Sample Run 3" << endl;
	cout<<"binary 1010101011 * 1 = "<<multbin("1010101011", "1")<<endl;   //you should get 1010101011
	cout<<"hexadecimal F000000F * ABCDE = "<<multhex("F000000F", "ABCDE")<<endl<<endl;  //you should get A111020A11102

	cout<<"Sample Run 4" << endl;
	cout<<"binary 111111111110 * 10 = "<<multbin("111111111110", "10")<<endl;   //you should get 1111111111100
	cout<<"hexadecimal 1CA0 * D4482 = "<<multhex("1CA0", "D4482")<<endl<<endl;  //you should get 17BC909400

	cout<<"Sample Run 5" << endl;
	cout<<"binary 1 * 1 = "<<multbin("1", "1")<<endl;   //you should get 1
	cout<<"hexadecimal 4B * 5D = "<<multhex("4B", "5D")<<endl<<endl;  //you should get 1B3F

	system("PAUSE");
	return 0;
}

string multbin(string bin1, string bin2)
{
	string binProd = ""; //1. This variable stores the binary product to be calculated.

	if(bin1 == "0" || bin2 == "0"){ //2. Base Case: if either number is 0, the product is 0.
		binProd.append("0");
	}else if(bin1 == "1"){//3. If either number is 1, the product is equal to the other number.
		binProd.append(bin2);
	}else if(bin2 == "1"){
		binProd.append(bin1));
	}else if(bin1.size() > bin2.size()){ //4. If bin1 is larger, use bin2 as multiplier
		for(int bit = 0; bit < bin2.size(); bit++){
			for(int i = 0; i < (bin2.at(bit) == '1' ? exp2(bin2.size() - bit - 1) : 0); i++){
				binProd = addbin(bin1, binProd);
			}
		}
	}else{  /*5. If bin2 is larger than bin1, use bin1 as multiplier*/
		for(int bit = 0; bit < bin1.size(); bit++){
			for(int i = 0; i < (bin1.at(bit) == '1' ? exp2(bin1.size() - bit - 1) : 0); i++){
				binProd = addbin(bin2, binProd);
			}
		}
	}
	return binProd;
}

string multhex(string hex1, string hex2)
{
	string hexProd = ""; //6. This variable stores the hexadecimal product to be calculated.

	if(hex1 == "0" || hex2 == "0"){
		hexProd.append("0");
	}else if(hex1 == "1" || hex2 == "1"){
		(hex1 == "1" ? hexProd.append(hex2) : hexProd.append(hex1));
	}else if(hex1.size() > hex2.size()){ //7. If hex1 is larger, use hex2 as multiplier
		for(int bit = 0; bit < hex2.size(); bit++){
			//9. Inside the for loop is a ternary operator that checks if each bit is a digit or a letter depending on the ASCII code value
			// Value returned from ternary
			for(int i = 0; i < (hex2.at(bit) <= 57 ? hex2.at(bit) - 48/*if digit*/ : hex2.at(bit) - 55/*if letter*/); i++){
				for(int i = 0; i < (pow(16, hex2.size() - bit - 1)); i++){
					hexProd = addhex(hex1, hexProd);
				}
			}
		}
	}else{ /*10. If hex2 is larger than hex1, use hex1 as multiplier*/
		for(int bit = 0; bit < hex1.size(); bit++){
			for(int i = 0; i < (hex1.at(bit) <= 57 ? hex1.at(bit) - 48 : hex1.at(bit) - 55); i++){
				for(int i = 0; i < (pow(16, hex1.size() - bit - 1)); i++){
					hexProd = addhex(hex2, hexProd);
				}
			}
		}
	}
	return hexProd;
}


string addbin(string bin1, string bin2)
{
	string binSum = "";
	int rem = 0, carry = 0;

	//1. This while loop ensures that both numbers are the same size
	// 2. It finds and concatenates the smallest number until it has the same size as the larger number
	if(bin1.size() < bin2.size()){
		//3. Using the difference in size, the for loop knows how many 0s to add
		bin1.insert(0, bin2.size() - bin1.size(), '0');
	}else{
		//bin1.size() > bin2.size()
		bin2.insert(0, bin1.size() - bin2.size(), '0');
	}


	//4. Starting from the last bit, this for loop will add up each bit value
	for(int bit = bin1.size() - 1; bit >= 0; bit--){
		//5. Converts bit chars to ints with ascii code conversion
		//6. Note that the carry from the last bit addition is always included in the current sum
		/*Changes made*:
			int sum was removed, rem and carry were modified to contain value of sum
		*/
		carry = (bin1.at(bit) - 48) + (bin2.at(bit) - 48) + carry;
		rem = carry % 2;
		carry = carry / 2;

		//7. Remainder value is inserted into binSum (either 0 or 1)
		binSum.insert(0, 1, static_cast<char>(rem + 48));
	}
	//8. In case of excess carry, this if statement adds another 1 if necessary
	if(carry == 1){
		binSum.insert(0, "1");
	}

	return binSum;
}

string addhex(string hex1, string hex2)
{
	string hexSum = "";
	int rem = 0, carry = 0;
	// While loop is exactly like the one in addbin, concatenating the smallest string
	if(hex1.size() < hex2.size()){
		hex1.insert(0, hex2.size() - hex1.size(), '0');
	}else{
		//if hex1.size() > hex2.size()
		hex2.insert(0, hex1.size() - hex2.size(), '0');
	}

	//Starting from the last bit, this for loop will add each bit value
	for(int bit = hex1.size() - 1; bit >= 0; bit--){
		//Converts bit chars to ints with ascii code conversion
		// sum = carry;
		//9. Ternary function checks for each hex number if bit is a digit or letter, then increments the sum
		carry += ((hex1.at(bit) < 58) ? (hex1.at(bit) - 48) : (hex1.at(bit) - 55)) + ((hex2.at(bit) < 58) ? (hex2.at(bit) - 48) : (hex2.at(bit) - 55));

		rem = carry % 16;
		carry = carry / 16;
		/*Changes made:
			switch statement replaced with ternary operator
		*/
		//10. Ternary statement inserts proper remainder value into hexSum
		// If remainder is less than 10 (or its value is not a letter in hexadecimal), then it inserts with digit ascii value, else, a letter ascii code value
		hexSum.insert(0, 1, static_cast<char>(rem < 10 ? rem + 48 : rem + 55));
	}
	//In case of excess carry, this if statement adds another 1 if necessary
	if(carry == 1){
		hexSum.insert(0, "1");
	}


	return hexSum;

}
