#include <stdio.h>
#include <stdlib.h>

struct student {
	int SID;
	char name[10];
	char gender;
	int Chinese;
	int Math;
	int English;
	int all;
	int avg;
	struct student *next;
} ;
#define LEN sizeof(struct student)

int all_grade3();

int main() {
	FILE *pf;
	int n;
	pf = fopen("studen_grad.txt", "r");
	fscanf(pf, "%d", &n);
	struct student *head, *p1, *p2;
	p1 = p2 = (struct student *)malloc(LEN);
	fscanf(pf, "%d %s %d %d %d %d", &(*p1).SID, &(*p1).name, &(*p1).gender, &(*p1).Chinese, &(*p1).Math, &(*p1).English,
	       &(*p1).all, &(*p1).avg);
	head = NULL;
	for (int i = 0; i < n; i++) {
		if (i = 1) {
			head = p1;
		} else {
			(*p2).next = p1;
		}
		p2 = p1;
		p1 = (struct student *)malloc(LEN);
		fscanf(pf, "%d %s %d %d %d %d", &(*p1).SID, &(*p1).name, &(*p1).gender, &(*p1).Chinese, &(*p1).Math, &(*p1).English,
		       &(*p1).all, &(*p1).avg);
	}
	(*p2).next = NULL;
	int caozuo;
	printf("ѧ���ɼ�����ϵͳ\n1.����  2.ɾ��\n3.��ʾ  4.����\n5.����  0.�˳�\n");
	scanf("%d", &caozuo);

	switch (caozuo) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 0:
			break;
	}
	return 0;
}


int all_grade3() {

}



