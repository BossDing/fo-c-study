#include<stdio.h>
void char_array() {
	char amessage[] = "nw is the time"; /* ���� */
	char *pmessage = "now is the time"; /* ָ�� */

	//*(pmessage + 1) = 'e';//����
	printf("%c\n", *(pmessage + 1));

	amessage[1] = 'e';
	printf("%c\n", amessage[1]);
}

void array_test() {
	int arr[] = { 1,2,3 };
	print_i(arr);
	print_i(&arr);
	print_i(*arr);
	int *p;
	p = &arr;
	print_i(p);
	print_i(*p);
	print_i(p+1);
	print_i(*(p+1));
	print_i(p[2]);

	int *q = arr;
	print_i(q);
	print_i(*q);

	int *w = &arr;
	print_i(w);
	print_i(*w);
}

f0() {
	int a[] = { 1,2,3 };
	if (a == &a) {
		printf("a==&a is true.\n");//���Խ��Ϊtrue ���� a==&a 
	}
	else {
		printf("a==&a is false.\n");
	}
	print_i(a[0]);
	f1(a);
	print_i(*a);

	printf("-----------------\n");
	print_i(a[2]);
	//f2(&a[2]);	//������봫&a[2]����Ϊa+2,�����a[2]�����
	f2(a + 2);
	print_i(a[2]);
	printf("-----------------\n");
	print_i(a+3);
}
f1(int *a) {
	*a = 6;
	a++;
	print_i(a);
	print_i(*a);
}
f2(int *x) {
	*x = 666;
}
