//开头是ifndef
#ifndef HEADER_FILE
#define HEADER_FILE

//----------------定义常量-----------------------

//蛇的状态 
#define U 1 
#define D 2 
#define L 3 
#define R 4 

//-------------全局变量 -------------------
//结构体变量
//蛇身的一个节点 
typedef struct snake{
	int x;
	int y;
	struct snake* next;
}snake;

/*------------------普通全局变量------------------*/

//分数
int score = 0;
//等级
int level;
//每吃一个食物获得的分数 
int add = 10;
//游戏结束的情况，1是撞墙，2是咬到自己，3是主动退出
int endGameStatus = 0;
//加速减速
//每次运行的时间间隔200ms
int sleeptime = 200;
//蛇的前进状态，不妨让他一开始向右
//status = U, D, L, R.
int status = R;



//结构体指针：蛇头和食物
snake * head = NULL, * food;
//遍历蛇身的时候用到的中间指针
snake * q;


//--------------函数声明------------------------------------------
void gotoxy(int x, int y);//设置光标位置 
int color(int c);//更改文本颜色 

void welcomeToGame();//开始游戏界面 				[#]
void creatMap();//创建地图							[#]
void scoreAndTips();//分数和提示界面 				[#]
void levelChange();//段位 							[#]
void initSnake();//初始化蛇身 						[#]

void creatFood();//随机生成食物 					[#]

int biteSelf();//判断是否咬到自己 					[#]
void cantCrossWall();//设置蛇撞墙的情况 			[#]
void speedUp();//F1加速 							[#]
void speedDown();//F2减速 							[#]
void snakeMove();//蛇移动方向 						[#]
void keyboardControl();//控制键盘按键 				[#]
void lostDraw();//绘制游戏失败界面 					[#]
void endGame();//游戏结束 							[#]
void choose();//选择继续游戏或者退出游戏 			[]
void explation();//游戏说明 						[#]
//void isFoodOnSnake(snake * p);//判断食物是否在蛇身上  []

//结尾是endif
#endif
