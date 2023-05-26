#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	char map[5][21];
	int i = 0, j = 0;
	int x = 10, y = 2;
	char gar;
	
	int money = 1000;
	int hp = 50;
	int atk = 10;
	int dps = 15;
	
	int gar_turn = 0; 
	
	int inven[3] = {0,0,0};
	
	for(i = 0; i < 5; ++i)
	{
		for(j = 0; j < 21; ++j)
		{
			map[i][j] = ' ';
		}
	}
	
	map[0][5] = 'S';
	map[0][15] = 'C';
	map[4][5] = 'H';
	map[4][15] = 'B';
	map[2][10] = 'O';
	
	while (1) {
        printf("-----------------------\n");
		for(i = 0; i < 5; ++i)
		{
			printf("|"); 
			for(j = 0; j < 21; ++j)
			{
				printf("%c", map[i][j]);
			}
			printf("|\n");
		}
		printf("-----------------------\n");
		printf("S:상점  C:창고  H:훈련장  B:비무장\n");
		
		char c;
		c = _getch();           // 3. 방향키가 입력됬을 때 224 00 이 버퍼에 있다. 224부터 빼준다. 
        if (c == -32) {           // 4. -32로 입력되면
            c = _getch();        // 5. 뒤의 값 00을 판별하여 좌우상하 출력
            switch (c) {           
                case LEFT:
                    if(x == 0 || ((y == 0 || y == 4) && (x == 6 || x == 16)))
						break;
						
					map[y][x] = ' ';
					x -= 1;
					map[y][x] = 'O';
                    break;
                case RIGHT:
                    if(x == 20 || ((y == 0 || y == 4) && (x == 4 || x == 14)))
						break;
						
					map[y][x] = ' ';
					x += 1;
					map[y][x] = 'O';
                    break;
                case UP:
                    if(y == 0 || (y == 1 && (x == 5 || x == 15)))
						break;

					map[y][x] = ' ';
					y -= 1;
					map[y][x] = 'O';
                    break;
                case DOWN:
                	if(y == 4 || (y == 3 && (x == 5 || x == 15)))
						break;
                	
					map[y][x] = ' ';
					y += 1;
					map[y][x] = 'O';
                    break;
            }
            system("cls");
        }
        
        if (c == 'a')
		{
			if((x == 4 && y == 0) || (x == 6 && y == 0) || (x == 5 && y == 1))
			{
				gar_turn = 0;
				system("cls");
				while(1)
				{
					printf("----------------------\n");
					printf("1. 동자삼	1000원\n");
					printf("2. 명검		1000원\n");
					printf("3. 명방패	1000원\n");
					printf("----------------------\n");
					printf("잔액 : %d  나가기 : q\n", money);
					
					c = _getch();
					if (c == '1' && money >= 1000)
					{
						hp += 50;
						atk += 20;
						dps += 20;
						money -= 1000;
						inven[0] += 1;
					}
					else if(c == '1' && money < 1000)
					{
						++gar_turn;
						if (gar_turn == 4)
						{
							system("cls");
							printf("어디 돈도 없는 거지놈이!!\n");
							printf("썩 꺼져!!\n");
							printf("아무키 press");
							c = _getch();
							system("cls");
							break;
						}
						else
						{
							system("cls");
							printf("잔액이 부족하다네!\n");
							printf("아무키 press");
							c = _getch();
						}		 
					}
					if (c == '2' && money >= 1000)
					{
						atk += 70;
						money -= 1000;
						inven[1] += 1;
					}
					else if(c == '2' && money < 1000)
					{
						++gar_turn;
						if (gar_turn == 4)
						{
							system("cls");
							printf("어디 돈도 없는 거지놈이!!\n");
							printf("썩 꺼져!!\n");
							printf("아무키 press");
							c = _getch();
							system("cls");
							break;
						}
						else
						{
							system("cls");
							printf("잔액이 부족하다네!\n");
							printf("아무키 press");
							c = _getch();
						}		 
					}
					if (c == '3' && money >= 1000)
					{
						dps += 70;
						money -= 1000;
						inven[2] += 1;
					}
					else if(c == '3' && money < 1000)
					{
						++gar_turn;
						if (gar_turn == 4)
						{
							system("cls");
							printf("어디 돈도 없는 거지놈이!!\n");
							printf("썩 꺼져!!\n");
							printf("아무키 press");
							c = _getch();
							system("cls");
							break;
						}
						else
						{
							system("cls");
							printf("잔액이 부족하다네!\n");
							printf("아무키 press");
							c = _getch();
						}		 
					}
							
					if (c == 'q')
					{
						system("cls");
						break;
					}
					
					system("cls");
				}		
			}
			if((x == 14 && y == 0) || (x == 16 && y == 0) || (x == 15 && y == 1))
			{
				system("cls");
				while(1)
				{
					printf("      창 고\n");
					printf("-----------------\n");
					printf("  동자삼: %d\n", inven[0]);
					printf("  명  검: %d\n", inven[1]);
					printf("  명방패: %d\n", inven[2]);
					printf("-----------------\n");
					printf("잔액 : %d  나가기 : q\n", money);
					
					c = _getch();
					if (c == 'q')
						{
							system("cls");
							break;
						}
					system("cls");
				}
				
			}
			if((x == 4 && y == 4) || (x == 6 && y == 4) || (x == 5 && y == 3))
			{
				system("cls");
				while(1)
				{
					printf("      훈련장\n");
					printf("-----------------\n");
					printf("  (훈련시)  (+4)\n");
					printf("  내 HP    : %d\n", hp);
					printf("  내 공격력: %d\n", atk);
					printf("  내 방어력: %d\n", dps);
					printf("-----------------\n");
					printf("숫자를 누르면 훈련한다네 (100원)\n");
					printf("잔액 : %d  나가기 : q\n", money);
					
					c = _getch();
					if (c == '1' && money >= 100)
						{
							hp += 4;
							money -= 100;
							system("cls");
						}
					else if (c == '1' && money < 100)
						{
							system("cls");
							printf("잔액이 부족하다네!\n");
							printf("아무키 press");
							c = _getch();
						}
					if (c == '2' && money >= 100)
						{
							atk += 4;
							money -= 100;
							system("cls");
						}
					else if (c == '2' && money < 100)
						{
							system("cls");
							printf("잔액이 부족하다네!\n");
							printf("아무키 press");
							c = _getch();
						}
					if (c == '3' && money >= 100)
						{
							dps += 4;
							money -= 100;
							system("cls");
						}
					else if (c == '3' && money < 100)
						{
							system("cls");
							printf("잔액이 부족하다네!\n");
							printf("아무키 press");
							c = _getch();
						}
					else if (c == 'q')
						{
							system("cls");
							break;
						}
					system("cls");
				}
				
			}
		}
    }
	return 0;
}
