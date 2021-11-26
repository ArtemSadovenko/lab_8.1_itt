#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>

using namespace std;

void print_line(char* s) {
	cout << "line: ";
	for (int i = 0; s[i] != '\0'; i++) {
		cout << s[i];
	}
	cout << endl;
}

int count(char* s) {
	int i = strlen(s);
	int k = 0;
	int i_s;

	for (i; i >= 0; i--) {
		if (s[i] == '.' ) {
			k++;
			i_s = i;
		}
		if (k == 4) {
			break;
		}
	}
	if (k < 4) {
		return -1;
	}
	else return i_s;
}

void move_insert(char* s, int i) {
	int k = strlen(s);
	for (k; k > i; k--) {
		s[k + 1] = s[k];
	}
}

void chenge(char* s) {
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == '.') {
			move_insert(s, i);
			s[i] = '*';
			s[i + 1] = '*';
		}
	}
}



void main() {
	char s[101];

	
	cout << "Enter string: "; cin.getline(s, 100);
	print_line(s);
	
	int p = count(s);

	chenge(s);

	print_line(s);

	cout << "4th \".\" on position " << p << endl;
}