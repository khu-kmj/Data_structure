#include <stdio.h>
void hanoi(int num, char from, char by, char to) {
	if (num == 1){//원반이 1개면 원래가려던 A에서 C로 이동
		printf("원반 %d를 %c에서 %c로 이동!!! \n", num, from, to);
		return;
	}
	else {//원반이 1개가 아니라면
		hanoi(num - 1, from, to, by);//n-1까지의 원반을 A에서 B로 이동시킨 후
		printf("원반 %d를 %c에서 %c로 이동!!! \n", num, from, to);//n의 원반을 A에서 C로 이동시킨 다음
		hanoi(num - 1, by, from, to);//n-1까지의 원반을 B에서 C로 이동
	}
}
int main(void)
{
	char a = 'A';
	char b = 'B';
	char c = 'C';
	int hanoi_num = 0;
	printf("하노이의 타워를 A 에서 C로 옮깁니다.\n 타워의 갯수? ");
	scanf("%d", &hanoi_num);
	hanoi(hanoi_num, a, b, c);
	//b라는 중간거점을 거쳐서 a에서 c로 간다
	return 0;
}