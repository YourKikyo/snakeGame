#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h> 

#include "header.h"

//1.���ù��λ�ã�
void gotoxy(int x, int y){
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	
}
//2.����������ɫ
int color(int c){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return 0;
}
//3.��ʼ����
void welcomeToGame(){
	system("cls");
	int n;
	gotoxy(40,10);
	color(11);
	printf("̰ �� �� �� �� ս");
	 
	color(12);
	gotoxy(25,22);
	printf("1.��ʼ��Ϸ"); 
	gotoxy(45,22);
	printf("2.��Ϸ˵��"); 
	gotoxy(65,22);
	printf("3.�˳���Ϸ"); 
	
	color(15);
	gotoxy(27,29);
	printf("��\"��Ľ۹�\"ѧϰ���������Ǹ��˶���������"); 
	gotoxy(49,25);
	color(3);
  	//scanf("%d", &n);
 	switch(_getch()){
  		case '1':
   			system("cls");//����
			creatMap();
			scoreAndTips();
			initSnake();
			creatFood();
			keyboardControl();
			break;
		case '2':
 	 		printf("��Ϸ˵��");
			explation();
			break;
		case '3':
  	 		exit(0);
			break;
		default:
  			gotoxy(40,27);
			color(12);
			printf("�������������֣�");
			_getch();//���������
			system("cls");
			welcomeToGame();
 	}
}
//4.���Ƶ�ͼ
void creatMap(){
	int row, col;
	for(row = 0; row < 58; row += 2){
		gotoxy(row, 0);
		color(5);
		printf("��");
		gotoxy(row, 26);
		printf("��");
	}
	for(row = 1; row < 26; row++){
		gotoxy(0, row);
		printf("��");
		gotoxy(56, row);
		printf("��");
	}
	for(row = 2; row < 56; row += 2){
		for(col = 1; col < 26; col++){
			gotoxy(row, col);
			color(0);
			printf("��");
		}
	}
} 
//5.��������ʾ���� 
void scoreAndTips(){
	//���� 
	color(15);
	gotoxy(65,5);
	printf("Score: %d", score);
	//��λ 
	gotoxy(65,8);
	printf("Rank: ");
	levelChange();
	//������ʾ 
	color(15);
	gotoxy(65,13);
	printf("Tips:");
	gotoxy(65,15);
	printf("�������ң������ߵ��ƶ�");
	gotoxy(65,17);
	printf("�ո���ͣ��Ϸ");
	color(12); 
	gotoxy(65,22);
	//��Ϸ���� 
	printf("��Ϸ����");
	gotoxy(65,24);
	printf("ײǽ��ҧ���Լ�");
	gotoxy(65,25);
	printf("��������Ϸʧ��");
}
//6.��Ϸ˵��
void explation(){
	int n;
	system("cls");
	color(15);
	gotoxy(30, 5);
	printf("��ô�򵥵ľ�����Ϸ"); 
	gotoxy(30, 7);
	printf("�����Ҫ���˵����"); 
	gotoxy(30, 11);
	printf("�������Ȼ��������˵��ҳ..."); 
	gotoxy(30, 13);
	printf("�Ҿ͸������������ذ�����"); 
	gotoxy(30, 16);
	printf("F1��������"); 
	gotoxy(30, 18);
	printf("F2����ɲ��"); 
	//��ʾ���˿�ʼ��Ϸ����
	color(12);
	gotoxy(30, 24);
	printf("����0���ؿ�ʼ��Ϸ���棺"); 
	//scanf("%d", &n);
	while(_getch() != '0'){
		gotoxy(30, 23);
		printf("����������0��"); 
		gotoxy(30, 24);
		printf("����0���ؿ�ʼ��Ϸ���棺"); 
		//scanf("%d", &n);
		
	}
	welcomeToGame();
}
//7.��λ
void levelChange(){
	if(score >= 0 && score < 100) level = 1; 
	if(score >= 100 && score < 250) level = 2; 
	if(score >= 250 && score < 500) level = 3; 
	if(score >= 500 && score < 1000) level = 4; 
	if(score >= 1000) level = 5; 
	
	switch(level){
		case 1:
			color(12);
			printf("ͭ");
			break;
		case 2:
			color(8);
			printf("��");
			break;
		case 3:
			color(14);
			printf("��");
			break;
		case 4:
			color(11);
			printf("��");
			break;
		case 5:
			color(15);
			printf("Orz");
			break;
	}
} 
//8.��Ϸʧ�ܽ��� 
void lostDraw(){
	int n; 
	//������Ϸ�÷ֺͶ�λ 
	color(15);
	gotoxy(35,13);
	printf("Score: %d", score);
	color(15);
	gotoxy(36,15);
	printf("Rank: ");
	levelChange();
	
	//��Ҫע�����Ҫ�ȵ���һ�� levelChange() ����������level��ֵ�����䶯
	 
	if(level <= 2){
		color(4);
		gotoxy(38,9);
		printf("--- �� ---");
	}
	else if(level == 3 || level == 4){
		color(10);
		gotoxy(33,9);
		printf("--- �ٽ�������---");
	}
	else{
		color(14);
		gotoxy(28,9);
		printf("--- ���Ѿ��ư������Ϸ�ˣ�---");
	}
	
	if(endGameStatus == 1){
		gotoxy(32, 11);
		color(4);
		printf("����: һͷײ������ǽ!");
	}else if(endGameStatus == 2){
		gotoxy(32, 11);
		color(4);
		printf("����: �����˱���!");
	}else {
		gotoxy(32, 11);
		color(4);
		printf("����: \"����ɱ��...\"");
	}
	
	color(4);
	gotoxy(32, 24);
	printf("����0���ؿ�ʼ��Ϸ���棺");
 	//scanf("%d", &n);
 	
	while(_getch() != '0'){
		gotoxy(30, 23);
		printf("����������0��"); 
		gotoxy(30, 24);
		printf("����0���ؿ�ʼ��Ϸ���棺"); 
		//scanf("%d", &n);
	}
	score = 0;
	welcomeToGame();
}

//9.��ʼ������
void initSnake(){

	q = head;
	while(q != NULL){
		q = head->next;
		free(head);
		head = q;
	}

	status = R;
	int i;
	
	
	/*---------------�ȴ���һ����β�ĳ�ʼλ��--------------*/
	snake* tail;
	//malloc��̬�����һƬ�ڴ�ռ����ڴ洢tail
	//malloc��������һ��voidָ�룬��Ҫ����ǿת��snake*���͵�ָ�룬�Ӷ�����tail��Ƭ�ڴ�ռ�
	tail = (snake*)malloc(sizeof(snake));
	
	
	//��β�ĳ�ʼλ��
	int xx, yy;
	//��Ҫע��xx����Ϊż�����ܺͻ��Ƶĵ�ͼ���룡
	xx = 24;
	yy = 12;
	tail->x = xx;
	tail->y = yy;
	/*---------------------------------------------------------*/
	
	
	//��ʼ������ʱ��δ��ʳ�����nextΪNULL
	tail->next = NULL;
	
	
	
	
	/*-----------------------��ʼ������------------------------*/
	//��ʼ��ʱ����һ����β������ѭ��������ѭ��һ��
	for(i = 1; i <= 2; i++){
		//ÿ�ζ����´���һ����ͷ
		
		//��������ͷ�ļ����headָ�룬����������һ���ڴ�ռ�
		head = (snake*)malloc(sizeof(snake));
		//��ͷ����һ��λ������β
		head->next = tail;
		
		//ÿ��ѭ����head�ĳ�ʼ��������� ��ʼ��������λ�� ���ƶ���2i��λ��Ϊ�˺͵�ͼ���룡��
		head->x = xx + 2 * i;
		head->y = yy;
		
		//��ͷ����β���ظ�ѭ��2��
		tail = head;
	}
	/*-----------------------------------------------------------*/
	
	
	
	while(tail != NULL){
		gotoxy(tail->x,tail->y);
		color(10);
		printf("��");
		//����ͷһֱ�������β
		tail = tail->next;
	}
} 
//10.�������ʳ��
void creatFood(){
	snake * food1;
	//srand((unsigned)time(NULL));
	food1 = (snake*)malloc(sizeof(snake));
	//ͬ��ʳ�������Ҳ������ż�����������ͼ���룡
	//������һ��ʳ��һ����ʼx���꣬y�����x���������
	food1->x = 35;
	//food1->y = 9;
	
	//ȷ��x���������������ż��
	while(food1->x % 2 != 0){
		food1->x = rand() % 50 + 2;
	}
	food1->y = rand() % 22 + 1;
	
	//�����м�ָ��q����ͷ��ʼ���������ߣ�
	//���ʳ��������ߵ����ϣ����ͷŵ�ʳ���ָ�벢���´���ʳ��
	q = head;
	while(q != NULL){
		if(q->x == food1->x && q->y == food1->y){
			
		/*	//����ʹ�õݹ飬��Ϊѭ�����ѽ����
			while((food1->x %2)!=0)
			{
				food1->x=rand() %50 + 2;
			}
			food1->y=rand() %22 + 1;
			q=head;
			continue;
			
		*/
/*
snake * food1;
	//srand((unsigned)time(NULL));
	
	
	food1 = (snake*)malloc(sizeof(snake));
	
	
	//ͬ��ʳ�������Ҳ������ż�����������ͼ���룡
	//������һ��ʳ��һ����ʼx���꣬y�����x���������
	food1->x = 35;
	//food1->y = 9;

	//ȷ��x���������������ż��
	while(food1->x % 2 != 0){
		food1->x = rand() % 50 + 2;
	}
	food1->y = rand() % 22 + 1;
	
	
	
q = head;
while(q != NULL){
	if(q->x == food1->x && q->y == food1->y){
		free(food1);
		
		
		creatFood();
		return;
	}
	q = q->next;
}



*/
			
			

			//Sleep(200);
			//isFoodOnSnake(food1);
			//free(food1);
			//Sleep(200);//bug�����޸ģ�ˢ��һ��ʱ��������Խ���𣿡������У�sleep������һ������������Ȼ����
			
			//����creatFood()��һ������������ͻ����
			//creatFood();��������ʹ�õݹ飬��Ϊ���������һ��ʳ��
			
			/*snake * food1;
			food1 = (snake*)malloc(sizeof(snake));
			food1->x = 35;
			while(food1->x % 2 != 0){
				food1->x = rand() % 50 + 2;
			}
			food1->y = rand() % 22 + 1;*/
			
			if(q->x == food1->x && q->y == food1->y){
			free(food1);
			creatFood();
				return;
			}
			
			
			
		}
		q = q->next;
	}
	//���ھͿ��Խ�food����food1��λ����
	gotoxy(food1->x, food1->y);
	food = food1;
	//bug�����޸ģ�free��food1�ܽ��������---�᲻ͣ�Ĳ���ʳ��
	//free(food1);
	color(12);
	printf("��");
}
//10.5:�����¶���һ��������ʵ�ֵݹ飬�Ų�bugԭ��
/*void isFoodOnSnake(snake * p){
	p = (snake*)malloc(sizeof(snake));
	q = head;
	while(q->next != NULL){
		if(q->x == p->x && q->y == p->y){
			free(p);
			creatFood();
		}
	}
}*/
//11.�ж��Ƿ�ҧ���Լ���0Ϊ����1Ϊҧ���Լ�
int biteSelf(){
	//����һ������ڵ�self��Ϊ��ͷ֮�������ڵ�
	snake * self;
	self = head->next;
	//�ж�����������ͷxy��self�Ƿ����
	while(self != NULL){
		if((self->x == head->x) && (self->y == head->y)){
			//endGameStatus = 2;
			return 1;
		}
		self = self->next;
	}
	return 0;
}
//12.��ײǽ�����
void cantCrossWall(){
	if(head->x <= 0 || head->x >= 56 || head->y <= 0 || head->y >= 26){
		endGameStatus = 1;
		endGame();
	}
}
//13.���ټ���
void speedUp(){
	if(sleeptime >= 50){
		//sleeptime�����ƶ��ļ����ԽСԽ��
		sleeptime -= 10;
		//�ٶ�Խ�죬foodÿ���÷�Խ��
		add += 2;
	}
}
void speedDown(){
	if(sleeptime < 350 && add > 2){
		sleeptime += 10;
		//���ÿ��ʳ��ĵ÷ֲ���Ϊ0���߸���
		add -= 2;
	}
}
//14.������ǰ������
void snakeMove(){
	//����һ����ͷ����һ��
	snake * nextHead;
	//��Ϊײǽֻ�ᷢ����ǰ��ʱ����cantCrossWall�������Ҫ�����ƶ���
	//�ж��Ƿ�ײǽ����ײǽ���ٿ�����һ�����ڴ�ռ�
	cantCrossWall();
	nextHead = (snake*)malloc(sizeof(snake));
	//��ʳ����ǵ�nextHead��food��xy���ʱ��food���head
	//������ʱ�Ե�ʳ��
	if(status == U){
		//����ʵ��������
		nextHead->x = head->x;
		nextHead->y = head->y - 1;
		nextHead->next = head;
		head = nextHead;
		//��head����q�������н������ı���
		q = head;
		
		//��nextHead��food���������
		if(nextHead->x == food->x && nextHead->y == food->y){
			while(q != NULL){
				//��ԭ����ʳ���λ�û������������´�ӡ��������
				gotoxy(q->x, q->y);
				color(10);
				printf("��");
				q = q->next;
			}
			//�Ե�ʳ���Ҫ�ӷֲ����´���ʳ��
			score += add;
			creatFood();
		}else{
			//����һ��û��ʳ��
			while(q->next->next != NULL){
				gotoxy(q->x, q->y);
				color(10);
				printf("��");
				q = q->next;
			}
			//������һ��ѭ��qָ������β���ߵ����һ�ڣ�
			//Ҳ�������߹���λ�ã����λ��Ҫ�����´�ӡ�ɱ���
			gotoxy(q->next->x, q->next->y);
			color(0);
			printf("��");
			free(q->next);//�ͷŵ�q��һλ��ָ�룬��ֹ�߱䳤
			q->next = NULL;//ָ�����һλ��Ϊ��
		}
	}
	//�����ߵĲ���ֻҪ����ճ������ľ�����
	if(status == D){
		nextHead->x = head->x;
		nextHead->y = head->y + 1;
		nextHead->next = head;
		head = nextHead;
		q = head;
		if(nextHead->x == food->x && nextHead->y == food->y){
			while(q != NULL){
				gotoxy(q->x, q->y);
				color(10);
				printf("��");
				q = q->next;
			}
			score += add;
			creatFood();
		}else{
			while(q->next->next != NULL){
				gotoxy(q->x, q->y);
				color(10);
				printf("��");
				q = q->next;
			}
			gotoxy(q->next->x, q->next->y);
			color(0);
			printf("��");
			free(q->next);
			q->next = NULL;
		}
	}
	//��
	if(status == L){
		nextHead->x = head->x - 2;
		nextHead->y = head->y;
		nextHead->next = head;
		head = nextHead;
		q = head;
		if(nextHead->x == food->x && nextHead->y == food->y){
			while(q != NULL){
				gotoxy(q->x, q->y);
				color(10);
				printf("��");
				q = q->next;
			}
			score += add;
			creatFood();
		}else{
			while(q->next->next != NULL){
				gotoxy(q->x, q->y);
				color(10);
				printf("��");
				q = q->next;
			}
			gotoxy(q->next->x, q->next->y);
			color(0);
			printf("��");
			free(q->next);
			q->next = NULL;
		}
	}
	//��
	if(status == R){
		nextHead->x = head->x + 2;
		nextHead->y = head->y;
		nextHead->next = head;
		head = nextHead;
		q = head;
		if(nextHead->x == food->x && nextHead->y == food->y){
			while(q != NULL){
				gotoxy(q->x, q->y);
				color(10);
				printf("��");
				q = q->next;
			}
			score += add;
			creatFood();
		}else{
			while(q->next->next != NULL){
				gotoxy(q->x, q->y);
				color(10);
				printf("��");
				q = q->next;
			}
			gotoxy(q->next->x, q->next->y);
			color(0);
			printf("��");
			free(q->next);
			q->next = NULL;
		}
	}
	//����ƶ�������ҧ���Լ�
	if(biteSelf() == 1){
		endGameStatus = 2;
		endGame();
	}
	cantCrossWall();
}
//15.���Ƽ��̰���
void keyboardControl(){
	//GetAsyncKeyState()�����������жϺ�������ʱ����ָ�����̵�״̬
	//sleep()����������ʵ�ֽ�����ͣ����Ҫһ��ʱ�����
	while(1){
		//��Ϸ���̣����ƶ������У�Ҫʵʱ����score��ֵ�Ͷ�λ
		scoreAndTips();
		//VK_UP����ʵ�ʼ����е��ϼ�ͷ
		if(GetAsyncKeyState(VK_UP) && status != D){
			//����߲�������ǰ�������Ҽ��̰������ϼ������ͷ������
			status = U;
		}else if(GetAsyncKeyState(VK_DOWN) && status != U){
			status = D;
		}else if(GetAsyncKeyState(VK_LEFT) && status != R){
			status = L;
		}else if(GetAsyncKeyState(VK_RIGHT) && status != L){
			status = R;
		}
		
		//�����ƶ������а��¿ո�����ͣ
		if(GetAsyncKeyState(VK_SPACE)){
			while(1){
				Sleep(300);
				//�ٰ�һ�οո��������Ϸ
				if(GetAsyncKeyState(VK_SPACE)){
					break;
				}
			}
		}
		
		//�������esc��ֱ���˳���Ϸ
		if(GetAsyncKeyState(VK_ESCAPE)){
			endGameStatus = 3;
			//����ѭ����������Ϸ
			endGame();
			break;
		}
		
		//���ٺͼ���
		if(GetAsyncKeyState(VK_F1)) speedUp();
		if(GetAsyncKeyState(VK_F2)) speedDown();
		
		//ÿ���ƶ��ļ��ʱ��
		Sleep(sleeptime);
		//���߽�����һ���ƶ�
		snakeMove();
	}
	
}

//16.��Ϸ����
void endGame(){
	system("cls");
	switch(endGameStatus){
		case 1:
			lostDraw();
			break;
		case 2:
			lostDraw();
			break;
		case 3:
			lostDraw();
			break;
	}
}



int main(){
	
	srand((unsigned)time(NULL));
	//initSnake();
	//score = 1000;
	//lostDraw();
	system("mode con cols=110 lines=40");
	welcomeToGame();
	
	keyboardControl();
	endGame();
	return 0;
}









 
/*
int main() {
	time_t timep;
	struct tm *p;
	time(&timep);
	p = gmtime(&timep);
	printf("Date:%d/%02d/%02d\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
	printf("Time:%02d/%02d/%02d\n", 8 + p->tm_hour, p->tm_min, p->tm_sec);
	return 0;
}
*/
