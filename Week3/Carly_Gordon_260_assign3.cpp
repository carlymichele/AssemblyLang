// NOTE: The ONLY files that should be #included for this assignment are iostream, vector, and string
// No other files should be #included

#include <iostream>
#include <vector>
#include <string>

// NOTE: The ONLY files that should be #included for this assignment are iostream, vector, and string
// No other files should be #included


using namespace std;

string addbin(string, string);
string addhex(string, string);


int main()
{

	cout<<"binary 1101 + 1000 = "<<addbin("1101", "1000")<<endl;   //you should get 10101
	cout<<"binary 11000 + 1011 = "<<addbin("11000", "1011")<<endl; //you should get 100011
	cout<<"binary 11111111 + 1 = "<<addbin("11111111", "1")<<endl; //you should get 100000000
	cout<<"binary 101010 + 10 = "<<addbin("101010", "10")<<endl<<endl; //you should get 101100

	cout<<"hexadecimal A4 + A5 = "<<addhex("A4", "A5")<<endl;  //you should get 149
	cout<<"hexadecimal 2B + C = "<<addhex("2B",  "C")<<endl;    //you should get 37
	cout<<"hexadecimal FABC + 789 = "<<addhex("FABC", "789")<<endl;  //you should get 10245
	cout<<"hexadecimal FFFFFF + FF = "<<addhex("FFFFFF", "FF")<<endl<<endl; //you should get 10000FE

	cout<<"Sample Run 1" << endl;
	cout<<"binary 110110 + 11 = "<<addbin("110110", "11")<<endl;   //you should get 111001
	cout<<"hexadecimal 1B0 + 34 = "<<addhex("1B0", "34")<<endl<<endl;  //you should get 1E4

	cout<<"Sample Run 2" << endl;
	cout<<"binary 101 + 10000001 = "<<addbin("101", "10000001")<<endl;   //you should get 10000110
	cout<<"hexadecimal A7774 + D = "<<addhex("A7774", "D")<<endl<<endl;  //you should get A7781

	cout<<"Sample Run 3" << endl;
	cout<<"binary 1010101011 + 1 = "<<addbin("1010101011", "1")<<endl;   //you should get 1010101100
	cout<<"hexadecimal F000000000F + ABCDEF = "<<addhex("F000000000F", "ABCDEF")<<endl<<endl;  //you should get F0000ABCDFE

	cout<<"Sample Run 4" << endl;
	cout<<"binary 111111111110 + 10 = "<<addbin("111111111110", "10")<<endl;   //you should get 1000000000000
	cout<<"hexadecimal 1CA0 + D4482 = "<<addhex("1CA0", "D4482")<<endl<<endl;  //you should get D6122

	cout<<"Sample Run 5" << endl;
	cout<<"binary 1 + 1 = "<<addbin("1", "1")<<endl;   //you should get 10
	cout<<"hexadecimal 4B + 5D = "<<addhex("4B", "5D")<<endl<<endl;  //you should get A8



	system("PAUSE");
	return 0;

}


string addbin(string bin1, string bin2)
{
	string binSum = "";
	int rem = 0, carry = 0, sum = 0;

	//1. This while loop ensures that both numbers are the same size
	while(bin1.size() != bin2.size()){
		// 2. It finds and concatenates the smallest number until it has the same size as the larger number
		if(bin1.size() < bin2.size()){
			//3. Using the difference in size, the for loop knows how many 0s to add
			for(int i=0; i < (bin2.size() - bin1.size()); i++){
				bin1.insert(0, "0");
			}
		}else{
			//bin1.size() > bin2.size()
			for(int i =0; i < (bin1.size() - bin2.size()); i++){
				bin2.insert(0, "0");
			}
		}
	}

	//4. Starting from the last bit, this for loop will add up each bit value
	for(int bit = bin1.size() - 1; bit >= 0; bit--){
		//5. Converts bit chars to ints with ascii code conversion
		//6. Note that the carry from the last bit addition is always included in the current sum
		sum = (bin1.at(bit) - 48) + (bin2.at(bit) - 48) + carry;
		rem = sum % 2;
		carry = sum / 2;

		//7. Remainder value is inserted into binSum (either 0 or 1)
		(rem) ? binSum.insert(0, "1") : binSum.insert(0, "0");
	}
	//8. In case of excess carry, this if statement adds another 1 if necessary
	if (carry == 1){
		binSum.insert(0, "1");
	}

	return binSum;
}

string addhex(string hex1, string hex2)
{
	string hexSum = "";
	int rem = 0, carry = 0, sum = 0;
	// While loop is exactly like the one in addbin, concatenating the smallest string
	while(hex1.size() != hex2.size()){
		if(hex1.size() < hex2.size()){
			for(int i=0; i < (hex2.size() - hex1.size()); i++){
				hex1.insert(0, "0");
			}
		}else{
			//if bin1.size() > bin2.size()
			for(int i =0; i < (hex1.size() - hex2.size()); i++){
				hex2.insert(0, "0");
			}
		}
	}

	//Starting from the last bit, this for loop will add each bit value
	for(int bit = hex1.size() - 1; bit >= 0; bit--){
		//Converts bit chars to ints with ascii code conversion
		sum = carry;
		//9. Ternary function checks if bit is a digit or letter, then increments the sum
		sum += ((hex1.at(bit) < 58) ? (hex1.at(bit) - 48) : (hex1.at(bit) - 55));
		sum += ((hex2.at(bit) < 58) ? (hex2.at(bit) - 48) : (hex2.at(bit) - 55));

		rem = sum % 16;
		carry = sum / 16;

		//10. Switch statement inserts proper remainder value into hexSum
		switch(rem){
			case 0:
				hexSum.insert(0,"0");
				break;
			case 1:
				hexSum.insert(0,"1");
				break;
			case 2:
				hexSum.insert(0,"2");
				break;
			case 3:
				hexSum.insert(0,"3");
				break;
			case 4:
				hexSum.insert(0,"4");
				break;
			case 5:
				hexSum.insert(0,"5");
				break;
			case 6:
				hexSum.insert(0,"6");
				break;
			case 7:
				hexSum.insert(0,"7");
				break;
			case 8:
				hexSum.insert(0,"8");
				break;
			case 9:
				hexSum.insert(0,"9");
				break;
			case 10:
				hexSum.insert(0,"A");
				break;
			case 11:
				hexSum.insert(0,"B");
				break;
			case 12:
				hexSum.insert(0,"C");
				break;
			case 13:
				hexSum.insert(0,"D");
				break;
			case 14:
				hexSum.insert(0,"E");
				break;
			case 15:
				hexSum.insert(0,"F");
				break;
			default:
				cout << "error in dec to hex switch" << endl;
				break;
		}
	}
	//In case of excess carry, this if statement adds another 1 if necessary
	if (carry == 1){
		hexSum.insert(0, "1");
	}

	return hexSum;
}
