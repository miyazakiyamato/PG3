#include <stdio.h>

int Recursive(int n) {
	if (n <= 1) {
		return(100);
	}

	return (Recursive(n - 1) + Recursive(n - 1) * 2 - 50);
}

int main(){

	int a = 1072;
	int n = 5;
	int result;

	result = a * n;
	printf("��ʓI�Ȓ�����%d���ԕ� = %d\n", n, result);
	result = Recursive(n);
	printf("�ċA�I�Ȓ�����%d���ԕ� = %d\n", n, result);
	return 0;
}