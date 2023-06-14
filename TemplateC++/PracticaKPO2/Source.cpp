#include <iostream>

//int searchForMax(int n, int* mas) {
//	int max = 0;
//	for (int i = 0; i < n; i++) {
//		if (mas[i] > max) {
//			max = mas[i];
//		}
//	}
//	return max;
//}
//
//int* sortMas(int n, int* mas, int max) {
//	int* sortedMas = new int[n];
//	sortedMas[n - 1] = max;
//	int index = n - 2;
//	while (index >= 0) {
//		int prevElem = 0;
//		for (int i = 0; i < n; i++) {
//			if (mas[i] < max && mas[i] > prevElem) {
//				prevElem = mas[i];
//			}
//		}
//		max = prevElem;
//		int copies = 0;
//		for (int i = 0; i < n; i++) {
//			if (mas[i] == max) {
//				copies++;
//			}
//		}
//		while (copies > 0) {
//			sortedMas[index] = max;
//			copies--;
//			if (copies > 0) {
//				index--;
//			}
//		}
//		index--;
//	}
//	return sortedMas;
//}
//
//int main() {
//	int n = 0;
//	std::cin >> n;
//	int* mas = new int[n];
//	for (int i = 0; i < n; i++) {
//		std::cin >> mas[i];
//	}
//	int max = searchForMax(n, mas);
//	int* newMas = sortMas(n, mas, max);
//	for (int i = 0; i < n; i++) {
//		std::cout << mas[i] << " ";
//	}
//	std::cout << "\n";
//	for (int i = 0; i < n; i++) {
//		std::cout << newMas[i] << " ";
//	}
//	delete[] mas;
//	delete[] newMas;
//	return 0;
//}
 

//
//int searchForMax(int n, int* mas) {
//	int max = 0;
//	for (int i = 0; i < n; i++) {
//		if (mas[i] > max) {
//			max = mas[i];
//		}
//	}
//	return max;
//}
//
//short searchForMax(int n, short* mas) {
//	short max = 0;
//	for (int i = 0; i < n; i++) {
//		if (mas[i] > max) {
//			max = mas[i];
//		}
//	}
//	return max;
//}
//
//double searchForMax(int n, double* mas) {
//	double max = 0;
//	for (int i = 0; i < n; i++) {
//		if (mas[i] > max) {
//			max = mas[i];
//		}
//	}
//	return max;
//}
//
//short* sortMas(int n, short* mas, short max) {
//	short* sortedMas = new short[n];
//	sortedMas[n - 1] = max;
//	int index = n - 2;
//	while (index >= 0) {
//		short prevElem = 0;
//		for (int i = 0; i < n; i++) {
//			if (mas[i] < max && mas[i] > prevElem) {
//				prevElem = mas[i];
//			}
//		}
//		max = prevElem;
//		int copies = 0;
//		for (int i = 0; i < n; i++) {
//			if (mas[i] == max) {
//				copies++;
//			}
//		}
//		while (copies > 0) {
//			sortedMas[index] = max;
//			copies--;
//			if (copies > 0) {
//				index--;
//			}
//		}
//		index--;
//	}
//	return sortedMas;
//}
//
//int* sortMas(int n, int* mas, int max) {
//	int* sortedMas = new int[n];
//	sortedMas[n - 1] = max;
//	int index = n - 2;
//	while (index >= 0) {
//		int prevElem = 0;
//		for (int i = 0; i < n; i++) {
//			if (mas[i] < max && mas[i] > prevElem) {
//				prevElem = mas[i];
//			}
//		}
//		max = prevElem;
//		int copies = 0;
//		for (int i = 0; i < n; i++) {
//			if (mas[i] == max) {
//				copies++;
//			}
//		}
//		while (copies > 0) {
//			sortedMas[index] = max;
//			copies--;
//			if (copies > 0) {
//				index--;
//			}
//		}
//		index--;
//	}
//	return sortedMas;
//}
//
//double* sortMas(int n, double* mas, double max) {
//	double* sortedMas = new double[n];
//	sortedMas[n - 1] = max;
//	int index = n - 2;
//	while (index >= 0) {
//		double prevElem = 0;
//		for (int i = 0; i < n; i++) {
//			if (mas[i] < max && mas[i] > prevElem) {
//				prevElem = mas[i];
//			}
//		}
//		max = prevElem;
//		int copies = 0;
//		for (int i = 0; i < n; i++) {
//			if (mas[i] == max) {
//				copies++;
//			}
//		}
//		while (copies > 0) {
//			sortedMas[index] = max;
//			copies--;
//			if (copies > 0) {
//				index--;
//			}
//		}
//		index--;
//	}
//	return sortedMas;
//}
//
//int main() {
//	int n = 0;
//	std::cin >> n;
//	char str[10] = { 0 };
//	std::cin >> str;
//	if (strcmp(str, "int") == 0) {
//		int* mas = new int[n];
//		for (int i = 0; i < n; i++) {
//			std::cin >> mas[i];
//		}
//		int max = searchForMax(n, mas);
//		int* newMas = sortMas(n, mas, max);
//		for (int i = 0; i < n; i++) {
//			std::cout << mas[i] << " ";
//		}
//		std::cout << "\n";
//		for (int i = 0; i < n; i++) {
//			std::cout << newMas[i] << " ";
//		}
//		delete[] mas;
//		delete[] newMas;
//	} else if (strcmp(str, "short") == 0) {
//		short* mas = new short[n];
//		for (int i = 0; i < n; i++) {
//			std::cin >> mas[i];
//		}
//		short max = searchForMax(n, mas);
//		short* newMas = sortMas(n, mas, max);
//		for (int i = 0; i < n; i++) {
//			std::cout << mas[i] << " ";
//		}
//		std::cout << "\n";
//		for (int i = 0; i < n; i++) {
//			std::cout << newMas[i] << " ";
//		}
//		delete[] mas;
//		delete[] newMas;
//	} else if (strcmp(str, "double") == 0) {
//		double* mas = new double[n];
//		for (int i = 0; i < n; i++) {
//			std::cin >> mas[i];
//		}
//		double max = searchForMax(n, mas);
//		double* newMas = sortMas(n, mas, max);
//		for (int i = 0; i < n; i++) {
//			std::cout << mas[i] << " ";
//		}
//		std::cout << "\n";
//		for (int i = 0; i < n; i++) {
//			std::cout << newMas[i] << " ";
//		}
//		delete[] mas;
//		delete[] newMas;
//	} else {
//		std::cout << "Wrong input!";
//	}
//
//	return 0;
//}

template <typename T>
T searchForMax(int n, T* mas) {
	T max = 0;
	for (int i = 0; i < n; i++) {
		if (mas[i] > max) {
			max = mas[i];
		}
	}
	return max;
}

template <typename D>
D* sortMas(int n, D* mas, D max) {
	D* sortedMas = new D[n];
	sortedMas[n - 1] = max;
	int index = n - 2;
	while (index >= 0) {
		D prevElem = 0;
		for (int i = 0; i < n; i++) {
			if (mas[i] < max && mas[i] > prevElem) {
				prevElem = mas[i];
			}
		}
		max = prevElem;
		int copies = 0;
		for (int i = 0; i < n; i++) {
			if (mas[i] == max) {
				copies++;
			}
		}
		while (copies > 0) {
			sortedMas[index] = max;
			copies--;
			if (copies > 0) {
				index--;
			}
		}
		index--;
	}
	return sortedMas;
}

char searchForMax(int n, char* mas) {
	char max = 0;
	for (int i = 0; i < n; i++) {
		if (mas[i] > max && (mas[i] >='a' && mas[i] <= 'z') || (mas[i] >= 'A' && mas[i] <= 'Z')) {
			max = mas[i];
		}
	}
	return max;
}

int searchForNumers(int n, char* mas) {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		if (mas[i] >= 'a' && mas[i] <= 'z' || mas[i] >= 'A' && mas[i] <= 'Z') {
			counter++;
		}
	}
	return counter;
}

char* sortMas(int n, char* mas, char max) {
	std::cout << max << "\n";
	char* sortedMas = new char[n];
	int index = n - 1;
	int tempCounter = searchForNumers(n, mas);
	while (tempCounter > 0) {
		tempCounter--;
		mas[index] = ' ';
		index--;
	}
	sortedMas[index] = max;
	while (index >= 0) {
		char prevElem = 0;
		for (int i = 0; i < n; i++) {
			if (mas[i] < max && mas[i] > prevElem) {
				prevElem = mas[i];
			}
		}
		max = prevElem;
		int copies = 0;
		for (int i = 0; i < n; i++) {
			if (mas[i] == max) {
				copies++;
			}
		}
		while (copies > 0) {
			sortedMas[index] = max;
			copies--;
			if (copies > 0) {
				index--;
			}
		}
		index--;
	}
	return sortedMas;
}

int main() {
	int n = 0;
	std::cin >> n;
	char str[10] = { 0 };
	std::cin >> str;
	if (strcmp(str, "int") == 0) {
		int* mas = new int[n];
		for (int i = 0; i < n; i++) {
			std::cin >> mas[i];
		}
		int max = searchForMax(n, mas);
		int* newMas = sortMas(n, mas, max);
		for (int i = 0; i < n; i++) {
			std::cout << mas[i] << " ";
		}
		std::cout << "\n";
		for (int i = 0; i < n; i++) {
			std::cout << newMas[i] << " ";
		}
		delete[] mas;
		delete[] newMas;
	} else if (strcmp(str, "short") == 0) {
		short* mas = new short[n];
		for (int i = 0; i < n; i++) {
			std::cin >> mas[i];
		}
		short max = searchForMax(n, mas);
		short* newMas = sortMas(n, mas, max);
		for (int i = 0; i < n; i++) {
			std::cout << mas[i] << " ";
		}
		std::cout << "\n";
		for (int i = 0; i < n; i++) {
			std::cout << newMas[i] << " ";
		}
		delete[] mas;
		delete[] newMas;
	} else if (strcmp(str, "double") == 0) {
		double* mas = new double[n];
		for (int i = 0; i < n; i++) {
			std::cin >> mas[i];
		}
		double max = searchForMax(n, mas);
		double* newMas = sortMas(n, mas, max);
		for (int i = 0; i < n; i++) {
			std::cout << mas[i] << " ";
		}
		std::cout << "\n";
		for (int i = 0; i < n; i++) {
			std::cout << newMas[i] << " ";
		}
		delete[] mas;
		delete[] newMas;
	} 
	else if (strcmp(str, "char") == 0) {
		char* mas = new char[n];
		for (int i = 0; i < n; i++) {
			std::cin >> mas[i];
		}
		char max = searchForMax(n, mas);
		char* newMas = sortMas(n, mas, max);
		for (int i = 0; i < n; i++) {
			std::cout << mas[i] << " ";
		}
		cout << "\n";
		for (int i = 0; i < n; i++) {
			std::cout << newMas[i] << " ";
		}
		delete[] mas;
		delete[] newMas;
	} else {
		std::cout << "Wrong input!";
	}

	return 0;
}



