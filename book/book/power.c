#include<stdio.h>
double power(int a, int x) {
	if (a <= 0 || a == 1) {
		printf("����a=%d: ����a��������(a>0��a!=1) !\n", a);
		return -1;
	}
	double result=1.0;
	if (x >= 0) {
		for (int i = 0; i < x; i++) {
			result = result * a;
		}
	}
	else {
		for (int i = 0; i < -x; i++) {
			result = result / a;
		}
	}
	printf("ע��: ����x����Ϊ������,���ڸ������ļ��㾫�Ȳ��ܱ�֤!\n");
	return result;
}