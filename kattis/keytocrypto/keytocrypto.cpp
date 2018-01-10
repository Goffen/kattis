#include <iostream>
#include <algorithm>

using namespace std;



int main(void) {
	string msg, key, ciphertext = "";
	cin >> msg >> key;
	int msgLength = msg.size();
	int keyLength = key.size();

	for (int i = 0; i < msgLength; i++) {
		int charMsgShift;

		if(i < keyLength) {
			charMsgShift = key[i] - 65;
		}
		else {
			charMsgShift = ciphertext[i - keyLength] - 65;
		}
		int c = msg[i] - charMsgShift;
		if(c < 65) {
			//cout << (int)msg[i] << " " << charMsgShift << ": hmm < 65 : " << c << endl;
			c = 91 - (65 - c);
		}
		ciphertext += c;
	}
	cout << ciphertext << endl;
	return 0;
}