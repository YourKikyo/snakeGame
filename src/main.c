#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h> 

#include "header.h"

//1.设置光标位置：
void gotoxy(int x, int y){
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	
}
//2.更改文字颜色
int color(int c){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return 0;
}
//3.开始界面
void welcomeToGame(){
	system("cls");
	int n;
	gotoxy(40,10);
	color(11);
	printf("贪 吃 蛇 大 作 战");
	 
	color(12);
	gotoxy(25,22);
	printf("1.开始游戏"); 
	gotoxy(45,22);
	printf("2.游戏说明"); 
	gotoxy(65,22);
	printf("3.退出游戏"); 
	
	color(15);
	gotoxy(27,29);
	printf("由\"你的桔梗\"学习制作，并非个人独立开发。"); 
	gotoxy(49,25);
	color(3);
  	//scanf("%d", &n);
 	switch(_getch()){
  		case '1':
   			system("cls");//清屏
			creatMap();
			scoreAndTips();
			initSnake();
			creatFood();
			keyboardControl();
			break;
		case '2':
 	 		printf("游戏说明");
			explation();
			break;
		case '3':
  	 		exit(0);
			break;
		default:
  			gotoxy(40,27);
			color(12);
			printf("请输入合理的数字！");
			_getch();//输入任意键
			system("cls");
			welcomeToGame();
 	}
}
//4.绘制地图
void creatMap(){
	int row, col;
	for(row = 0; row < 58; row += 2){
		gotoxy(row, 0);
		color(5);
		printf("□");
		gotoxy(row, 26);
		printf("□");
	}
	for(row = 1; row < 26; row++){
		gotoxy(0, row);
		printf("□");
		gotoxy(56, row);
		printf("□");
	}
	for(row = 2; row < 56; row += 2){
		for(col = 1; col < 26; col++){
			gotoxy(row, col);
			color(0);
			printf("■");
		}
	}
} 
//5.分数和提示界面 
void scoreAndTips(){
	//分数 
	color(15);
	gotoxy(65,5);
	printf("Score: %d", score);
	//段位 
	gotoxy(65,8);
	printf("Rank: ");
	levelChange();
	//操作提示 
	color(15);
	gotoxy(65,13);
	printf("Tips:");
	gotoxy(65,15);
	printf("上下左右：控制蛇的移动");
	gotoxy(65,17);
	printf("空格：暂停游戏");
	color(12); 
	gotoxy(65,22);
	//游戏规则 
	printf("游戏规则：");
	gotoxy(65,24);
	printf("撞墙、咬到自己");
	gotoxy(65,25);
	printf("都算作游戏失败");
}
//6.游戏说明
void explation(){
	int n;
	system("cls");
	color(15);
	gotoxy(30, 5);
	printf("这么简单的经典游戏"); 
	gotoxy(30, 7);
	printf("真的需要别的说明吗？"); 
	gotoxy(30, 11);
	printf("但是嘛，既然你打开了这个说明页..."); 
	gotoxy(30, 13);
	printf("我就告诉你两个神秘按键吧"); 
	gotoxy(30, 16);
	printf("F1：踩油门"); 
	gotoxy(30, 18);
	printf("F2：踩刹车"); 
	//显示回退开始游戏界面
	color(12);
	gotoxy(30, 24);
	printf("输入0返回开始游戏界面："); 
	//scanf("%d", &n);
	while(_getch() != '0'){
		gotoxy(30, 23);
		printf("请输入数字0！"); 
		gotoxy(30, 24);
		printf("输入0返回开始游戏界面："); 
		//scanf("%d", &n);
		
	}
	welcomeToGame();
}
//7.段位
void levelChange(){
	if(score >= 0 && score < 100) level = 1; 
	if(score >= 100 && score < 250) level = 2; 
	if(score >= 250 && score < 500) level = 3; 
	if(score >= 500 && score < 1000) level = 4; 
	if(score >= 1000) level = 5; 
	
	switch(level){
		case 1:
			color(12);
			printf("铜");
			break;
		case 2:
			color(8);
			printf("银");
			break;
		case 3:
			color(14);
			printf("金");
			break;
		case 4:
			color(11);
			printf("钻");
			break;
		case 5:
			color(15);
			printf("Orz");
			break;
	}
} 
//8.游戏失败界面 
void lostDraw(){
	int n; 
	//本次游戏得分和段位 
	color(15);
	gotoxy(35,13);
	printf("Score: %d", score);
	color(15);
	gotoxy(36,15);
	printf("Rank: ");
	levelChange();
	
	//需要注意的是要先调用一遍 levelChange() 函数才能让level的值发生变动
	 
	if(level <= 2){
		color(4);
		gotoxy(38,9);
		printf("--- 蔡 ---");
	}
	else if(level == 3 || level == 4){
		color(10);
		gotoxy(33,9);
		printf("--- 再接再厉！---");
	}
	else{
		color(14);
		gotoxy(28,9);
		printf("--- 你已经制霸这个游戏了！---");
	}
	
	if(endGameStatus == 1){
		gotoxy(32, 11);
		color(4);
		printf("死因: 一头撞在了南墙!");
	}else if(endGameStatus == 2){
		gotoxy(32, 11);
		color(4);
		printf("死因: 你变成了苯环!");
	}else {
		gotoxy(32, 11);
		color(4);
		printf("死因: \"它自杀了...\"");
	}
	
	color(4);
	gotoxy(32, 24);
	printf("输入0返回开始游戏界面：");
 	//scanf("%d", &n);
 	
	while(_getch() != '0'){
		gotoxy(30, 23);
		printf("请输入数字0！"); 
		gotoxy(30, 24);
		printf("输入0返回开始游戏界面："); 
		//scanf("%d", &n);
	}
	score = 0;
	welcomeToGame();
}

//9.初始化蛇身
void initSnake(){

	q = head;
	while(q != NULL){
		q = head->next;
		free(head);
		head = q;
	}

	status = R;
	int i;
	
	
	/*---------------先创建一个蛇尾的初始位置--------------*/
	snake* tail;
	//malloc动态分配出一片内存空间用于存储tail
	//malloc函数返回一个void指针，需要把它强转成snake*类型的指针，从而赋给tail这片内存空间
	tail = (snake*)malloc(sizeof(snake));
	
	
	//蛇尾的初始位置
	int xx, yy;
	//需要注意xx必须为偶数才能和绘制的地图对齐！
	xx = 24;
	yy = 12;
	tail->x = xx;
	tail->y = yy;
	/*---------------------------------------------------------*/
	
	
	//初始化蛇身时尚未吃食物，所以next为NULL
	tail->next = NULL;
	
	
	
	
	/*-----------------------初始蛇身长度------------------------*/
	//初始化时就有一个蛇尾，所以循环可以少循环一次
	for(i = 1; i <= 2; i++){
		//每次都重新创建一个蛇头
		
		//用声明在头文件里的head指针，并给它分配一个内存空间
		head = (snake*)malloc(sizeof(snake));
		//蛇头的下一个位置是蛇尾
		head->next = tail;
		
		//每次循环，head的初始坐标相对于 初始化的蛇身位置 右移动个2i单位（为了和地图对齐！）
		head->x = xx + 2 * i;
		head->y = yy;
		
		//蛇头变蛇尾，重复循环2次
		tail = head;
	}
	/*-----------------------------------------------------------*/
	
	
	
	while(tail != NULL){
		gotoxy(tail->x,tail->y);
		color(10);
		printf("■");
		//从蛇头一直输出到蛇尾
		tail = tail->next;
	}
} 
//10.随机创建食物
void creatFood(){
	snake * food1;
	//srand((unsigned)time(NULL));
	food1 = (snake*)malloc(sizeof(snake));
	//同理，食物的坐标也必须是偶数，才能与地图对齐！
	//随便给第一个食物一个初始x坐标，y会根据x被随机出来
	food1->x = 35;
	//food1->y = 9;
	
	//确保x的坐标随机出来是偶数
	while(food1->x % 2 != 0){
		food1->x = rand() % 50 + 2;
	}
	food1->y = rand() % 22 + 1;
	
	//利用中间指针q从蛇头开始遍历整条蛇，
	//如果食物出现在蛇的身上，则释放掉食物的指针并重新创建食物
	q = head;
	while(q != NULL){
		if(q->x == food1->x && q->y == food1->y){
			
		/*	//放弃使用递归，改为循环，已解决！
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
	
	
	//同理，食物的坐标也必须是偶数，才能与地图对齐！
	//随便给第一个食物一个初始x坐标，y会根据x被随机出来
	food1->x = 35;
	//food1->y = 9;

	//确保x的坐标随机出来是偶数
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
			//Sleep(200);//bug尝试修改：刷新一下时间参数可以解决吗？——不行，sleep结束后一旦调用自身，仍然崩溃
			
			//错在creatFood()，一旦调用这玩意就会崩溃
			//creatFood();——放弃使用递归，改为再随机生成一个食物
			
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
	//现在就可以将food放在food1的位置了
	gotoxy(food1->x, food1->y);
	food = food1;
	//bug尝试修改：free掉food1能解决崩溃吗？---会不停的产生食物
	//free(food1);
	color(12);
	printf("●");
}
//10.5:尝试新定义一个函数来实现递归，排查bug原因
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
//11.判断是否咬到自己，0为正常1为咬到自己
int biteSelf(){
	//定义一个蛇身节点self作为蛇头之外的蛇身节点
	snake * self;
	self = head->next;
	//判断条件就是蛇头xy和self是否相等
	while(self != NULL){
		if((self->x == head->x) && (self->y == head->y)){
			//endGameStatus = 2;
			return 1;
		}
		self = self->next;
	}
	return 0;
}
//12.蛇撞墙的情况
void cantCrossWall(){
	if(head->x <= 0 || head->x >= 56 || head->y <= 0 || head->y >= 26){
		endGameStatus = 1;
		endGame();
	}
}
//13.加速减速
void speedUp(){
	if(sleeptime >= 50){
		//sleeptime是蛇移动的间隔，越小越快
		sleeptime -= 10;
		//速度越快，food每个得分越高
		add += 2;
	}
}
void speedDown(){
	if(sleeptime < 350 && add > 2){
		sleeptime += 10;
		//最低每个食物的得分不能为0或者负数
		add -= 2;
	}
}
//14.控制蛇前进方向
void snakeMove(){
	//创建一个蛇头的下一步
	snake * nextHead;
	//因为撞墙只会发生在前进时，故cantCrossWall这个函数要放在移动中
	//判断是否撞墙，若撞墙则不再开辟下一步的内存空间
	cantCrossWall();
	nextHead = (snake*)malloc(sizeof(snake));
	//吃食物：就是当nextHead和food的xy相等时把food变成head
	//向上走时吃到食物
	if(status == U){
		//首先实现向上走
		nextHead->x = head->x;
		nextHead->y = head->y - 1;
		nextHead->next = head;
		head = nextHead;
		//把head赋给q，来进行接下来的遍历
		q = head;
		
		//若nextHead和food的坐标相等
		if(nextHead->x == food->x && nextHead->y == food->y){
			while(q != NULL){
				//把原来是食物的位置换成蛇身，并重新打印整条蛇身
				gotoxy(q->x, q->y);
				color(10);
				printf("■");
				q = q->next;
			}
			//吃到食物后要加分并重新创建食物
			score += add;
			creatFood();
		}else{
			//若下一步没有食物
			while(q->next->next != NULL){
				gotoxy(q->x, q->y);
				color(10);
				printf("■");
				q = q->next;
			}
			//经过上一轮循环q指向了蛇尾（蛇的最后一节）
			//也就是蛇走过的位置，这个位置要被重新打印成背景
			gotoxy(q->next->x, q->next->y);
			color(0);
			printf("■");
			free(q->next);//释放掉q下一位的指针，防止蛇变长
			q->next = NULL;//指针的下一位就为空
		}
	}
	//向下走的部分只要复制粘贴上面的就行了
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
				printf("■");
				q = q->next;
			}
			score += add;
			creatFood();
		}else{
			while(q->next->next != NULL){
				gotoxy(q->x, q->y);
				color(10);
				printf("■");
				q = q->next;
			}
			gotoxy(q->next->x, q->next->y);
			color(0);
			printf("■");
			free(q->next);
			q->next = NULL;
		}
	}
	//左
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
				printf("■");
				q = q->next;
			}
			score += add;
			creatFood();
		}else{
			while(q->next->next != NULL){
				gotoxy(q->x, q->y);
				color(10);
				printf("■");
				q = q->next;
			}
			gotoxy(q->next->x, q->next->y);
			color(0);
			printf("■");
			free(q->next);
			q->next = NULL;
		}
	}
	//右
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
				printf("■");
				q = q->next;
			}
			score += add;
			creatFood();
		}else{
			while(q->next->next != NULL){
				gotoxy(q->x, q->y);
				color(10);
				printf("■");
				q = q->next;
			}
			gotoxy(q->next->x, q->next->y);
			color(0);
			printf("■");
			free(q->next);
			q->next = NULL;
		}
	}
	//如果移动过程中咬到自己
	if(biteSelf() == 1){
		endGameStatus = 2;
		endGame();
	}
	cantCrossWall();
}
//15.控制键盘按键
void keyboardControl(){
	//GetAsyncKeyState()函数：用来判断函数调用时虚拟指定键盘的状态
	//sleep()函数，用来实现进程暂停，需要一个时间参数
	while(1){
		//游戏过程（即移动过程中）要实时更新score的值和段位
		scoreAndTips();
		//VK_UP代表实际键盘中的上箭头
		if(GetAsyncKeyState(VK_UP) && status != D){
			//如果蛇不是向下前进，并且键盘按了向上键，则掉头到向上
			status = U;
		}else if(GetAsyncKeyState(VK_DOWN) && status != U){
			status = D;
		}else if(GetAsyncKeyState(VK_LEFT) && status != R){
			status = L;
		}else if(GetAsyncKeyState(VK_RIGHT) && status != L){
			status = R;
		}
		
		//若在移动过程中按下空格则暂停
		if(GetAsyncKeyState(VK_SPACE)){
			while(1){
				Sleep(300);
				//再按一次空格则继续游戏
				if(GetAsyncKeyState(VK_SPACE)){
					break;
				}
			}
		}
		
		//如果按了esc则直接退出游戏
		if(GetAsyncKeyState(VK_ESCAPE)){
			endGameStatus = 3;
			//跳出循环，结束游戏
			endGame();
			break;
		}
		
		//加速和减速
		if(GetAsyncKeyState(VK_F1)) speedUp();
		if(GetAsyncKeyState(VK_F2)) speedDown();
		
		//每次移动的间隔时间
		Sleep(sleeptime);
		//让蛇进行下一步移动
		snakeMove();
	}
	
}

//16.游戏结束
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
