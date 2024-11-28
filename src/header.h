//��ͷ��ifndef
#ifndef HEADER_FILE
#define HEADER_FILE

//----------------���峣��-----------------------

//�ߵ�״̬ 
#define U 1 
#define D 2 
#define L 3 
#define R 4 

//-------------ȫ�ֱ��� -------------------
//�ṹ�����
//�����һ���ڵ� 
typedef struct snake{
	int x;
	int y;
	struct snake* next;
}snake;

/*------------------��ͨȫ�ֱ���------------------*/

//����
int score = 0;
//�ȼ�
int level;
//ÿ��һ��ʳ���õķ��� 
int add = 10;
//��Ϸ�����������1��ײǽ��2��ҧ���Լ���3�������˳�
int endGameStatus = 0;
//���ټ���
//ÿ�����е�ʱ����200ms
int sleeptime = 200;
//�ߵ�ǰ��״̬����������һ��ʼ����
//status = U, D, L, R.
int status = R;



//�ṹ��ָ�룺��ͷ��ʳ��
snake * head = NULL, * food;
//���������ʱ���õ����м�ָ��
snake * q;


//--------------��������------------------------------------------
void gotoxy(int x, int y);//���ù��λ�� 
int color(int c);//�����ı���ɫ 

void welcomeToGame();//��ʼ��Ϸ���� 				[#]
void creatMap();//������ͼ							[#]
void scoreAndTips();//��������ʾ���� 				[#]
void levelChange();//��λ 							[#]
void initSnake();//��ʼ������ 						[#]

void creatFood();//�������ʳ�� 					[#]

int biteSelf();//�ж��Ƿ�ҧ���Լ� 					[#]
void cantCrossWall();//������ײǽ����� 			[#]
void speedUp();//F1���� 							[#]
void speedDown();//F2���� 							[#]
void snakeMove();//���ƶ����� 						[#]
void keyboardControl();//���Ƽ��̰��� 				[#]
void lostDraw();//������Ϸʧ�ܽ��� 					[#]
void endGame();//��Ϸ���� 							[#]
void choose();//ѡ�������Ϸ�����˳���Ϸ 			[]
void explation();//��Ϸ˵�� 						[#]
//void isFoodOnSnake(snake * p);//�ж�ʳ���Ƿ���������  []

//��β��endif
#endif
