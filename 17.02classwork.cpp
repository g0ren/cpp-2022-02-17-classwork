#include <iostream>
#include <cstring>
using namespace std;

int mystrlen(char *line) {
	int r { };
	while (*line != '\0') {
		r++;
		line++;
	}
	return r;
}

int countdigits(char *line) {
	int r { };
	while (*line != '\0') {
		if (*line >= '0' && *line <= '9')
			r++;
		line++;
	}
	return r;
}

char* renameNumbers(char *line) {
	static const char *names[] { "zero", "one", "two", "three", "four", "five",
			"six", "seven", "eight", "nine" };
	char *res = new char[mystrlen(line) + countdigits(line) * 5] { };
	char *r = res;
	while (*line != '\0') {
		if (*line >= '0' && *line <= '9') {
			int n = (int) *line - 48;
			for (int i = 0; names[n][i] != '\0'; i++) {
				*r = names[n][i];
				r++;
			}
		} else {
			*r = *line;
			r++;
		}
		line++;
	}
	return res;
}

/*
 * Определить, можно ли путем перестановок символов в строке S1 получить  строку S2.
 * Считать, что обе строки одной длины.
 */
long long encode(char *line) {
	static const int primes[256] { 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
			37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103,
			107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
			179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241,
			251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317,
			331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401,
			409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479,
			487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571,
			577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647,
			653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739,
			743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827,
			829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919,
			929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013,
			1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087,
			1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163,
			1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237,
			1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307,
			1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427,
			1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487,
			1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549, 1553, 1559, 1567,
			1571, 1579, 1583, 1597, 1601, 1607, 1609, 1613 };
	long long r { 1 };
	for (; *line != 0; line++) {
		r *= primes[(int) *line];
	}
	return r;
}

bool isAnagram(char *s1, char *s2) {
	return encode(s1) == encode(s2);
}

void swap(char &a, char &b) {
	char t { };
	t = a;
	a = b;
	b = t;
}

void sort(char *ar) {
	bool sorted { };
	while (!sorted) {
		sorted = 1;
		for (int i = 1; i < ar[0]; i++) {
			if (ar[i] > ar[i + 1]) {
				sorted = 0;
				swap(ar[i], ar[i + 1]);
			}
		}
	}
}

bool isEqual(char *ar1, char *ar2) {
	while (*ar1 != '\0') {
		if (*ar1 != *ar2)
			return false;
		ar1++;
		ar2++;
	}
	return true;
}

bool isAnagram2(char *ar1, char *ar2) {
	sort(ar1);
	sort(ar2);
	return isEqual(ar1, ar2);
}

/*
 * Генерируем список и печатаем только те, что длиннее 7
 */
char** generateList(int size) {
	char **list = new char*[size];
	for (int i = 0; i < size; i++) {
		list[i] = new char[256];
		cout << "Enter name: ";
		cin.getline(list[i], 256);
	}
	return list;
}

void printList(char **list) {
	for (int i = 0; i < 5; i++) {
		cout << list[i] << endl;
	}
}

void printListOver7(char **list) {
	for (int i = 0; i < 5; i++) {
		if (strlen(list[i]) > 7)
			cout << list[i] << endl;
	}
}

/*
 * Вывести фамилию и инициалы
 */
char* surnameNP(char *line) {
	char *res = new char[strlen(line)];
	char *r = res;
	while (*line != ' ') {
		*r = *line;
		r++;
		line++;
	}
	*r = ' ';
	r++;
	line++;
	*r = *line;
	r++;
	line++;
	while (*line != ' ') {
		line++;
	}
	*r = ' ';
	r++;
	line++;
	*r = *line;
	return res;
}

/*
 * Вывести все чётные слова, начиная с 1
 */
char* evenWords(char *line) {
	char *res = new char[strlen(line)]{};
	char *r = res;
	bool even { };
	while (*line != '\0') {
		if (even) {
			*r = *line;
			r++;
		}
		if (*line == ' ')
			even = (even ? false : true);
		line++;
	}
	return res;
}

int main() {
	char *line = new char[256];
	cout << "Enter string" << endl;
	cin.getline(line, 256);
	char *r = new char[256] { };
	r = evenWords(line);
	cout << r << endl;
	//char **list = new char*[5];
	//list = generateList(5);
	//printList(list);
	//printListOver7(list);
	return 0;
}
