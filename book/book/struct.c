#include<stdio.h>
struct point {
	int x;
	int y;
};
struct {
	int x, y, z;
} *third;
struct point make_point(int x, int y) {
	struct point temp;
	temp.x = x;
	temp.y = y;
	return temp;
}
void make_third_point(int x, int y,int z) {
	/*
		ʹ��
			struct {
			int x, y, z;
			} *third;
		���ַ�ʽ�����ṹ�壬ʹ��third->x����(*third).x��ʽ��ֵ
	*/
	//(*third).x = x;
	//(*third).y = y;
	//(*third).z = z;
	third->x = x;
	third->y = y;
	third->z = z;
}
void print_point(struct point p) {
	printf("point(%d,%d)\n", p.x, p.y);
}
void print_point_with_addr(struct point *p) {
	printf("point(%d,%d)\n", (*p).x, (*p).y);
}
test_point() {
	struct point po = make_point(10, 20);
	print_point(po);
	struct point *p = &po;
	print_point_with_addr(p);
	print_point_with_addr(&po);

	make_third_point(1, 2, 3);
	printf("*third(%d,%d,%d)\n", third->x, third->y, third->z);
}