#include<stdio.h>
test() {
	char *arr[] = { "abc","string","hello" };
	char *p = arr[0];//arr[0] ��һ���ַ�ָ��,*p��ָ��ָ��ָ��ĵ�0���ı��е����ַ�
	
	printf("%s\n", arr[0]);
	printf("%c\n", *p);
	printf("%s\n", p);

	printf("-------------\n");
	char *q;
	q = arr[0];
	printf("%c\n", *q);
	printf("%s\n", q);
	
	printf("%d\n", (p == q));
}