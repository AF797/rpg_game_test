#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct character

{
	char *ch_name;
	
	int ch_hp;
	int ch_atk;
	int ch_dps;
	
	int pa;
	
} character;

int main(int argc, char *argv[])
{
	char map[5][21];
	int i = 0, j = 0;
	int x = 10, y = 2;
	char gar;
	
	char *name = malloc(sizeof(char) * 10);
	int money = 1000;
	int hp = 50;
	int hhp = hp;
	int atk = 20;
	int hatk = atk;
	int dps = 5;
	int hdps = hdps;
	
	char *ch_name = malloc(sizeof(char) * 10);
	int ch_hp;
	int ch_atk;
	int ch_dps;
	
	int gar_turn = 0;
	int turn = 4;
	int magyo_turn = 0;
	
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
	
	printf("어서오시오 대협\n");
	printf("------------------\n");
	printf("아무키 press");
	_getch();
	system("cls");
	printf("처음 뵙는 분같은데 대협의 이름을 여쭈어 봐도 되겠소?\n");
	printf("------------------------------------------------------\n");
	printf("아무키 press");
	_getch();
	system("cls");
	while(1)
	{
		printf("이름: ");
		scanf("%s", name);
		system("cls");
		printf("%s 대협이구려\n", name);
		printf("------------------\n");
		printf("예 (y)  아니요(n)");
		char ss = _getch();
		if (ss == 'y' || ss == 'Y')
		{
			system("cls");
			break;
		}
		else
		{
			system("cls");
			printf("그러면 대협의 이름은 무엇이오?\n");
		}
	}
	printf("%s 대협께서는 화산파로 보이시는데 아마 이곳에 수련하러 오신듯하오\n", name);
	printf("------------------------------------------------------------------------\n");
	printf("아무키 press");
	_getch();
	system("cls");
	printf("즐거운 시간 보내시오!!\n");
	printf("----------------------\n");
	printf("아무키 press");
	_getch();
	system("cls");
	
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
		printf("O: 내 캐릭터\n");
		
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
			if((x == 14 && y == 4) || (x == 16 && y == 4) || (x == 15 && y == 3))
			{
				hhp = hp;
				hatk = atk;
				hdps = dps;
				system("cls");
				while(1)
				{
					printf("      비무장\n");
					printf("--------------------\n");
					printf("비무를 하시겠습니까?\n");
					printf("\n");
					printf("예 (y)  아니요 (n)\n");
					printf("--------------------\n");
					
					c = _getch();
					if (c == 'y' || c == 'Y')
					{
						system("cls");
						srand(time(NULL));
						ch_name = "아무개";
						if(atk <= 41)
						{
							ch_hp = 50 + (rand()%5+1 * rand()%5+1);
							ch_atk = 20 + (rand()%4+1 * rand()%4+1);
							ch_dps = 5 + (rand()%3+1 * rand()%5+1);
						}
						else
						{
							ch_hp = 50 + (rand()%7+1 * rand()%7+1);
							ch_atk = 20 + (rand()%7+1 * rand()%7+1);
							ch_dps = 5 + (rand()%6+1 * rand()%6+1);
						}
						
						//TODO enemy.pa = rand()%3+1;
						
						while(1)
						{
							printf("---------------------------\n");
							printf("            	     %s\n", ch_name);
							printf("		     HP: %d\n", ch_hp);
							puts("");	puts("");
							printf("%s\n", name);
							printf("HP: %d\n", hhp);
							printf("---------------------------\n");
							printf("(1) 공격 (2)기 모으기\n");
							printf("(3) 스킬 (%d턴 남음)\n", turn);
							c = _getch();
							system("cls");
							if(c == '1')
							{
								ch_hp -= hatk - ch_dps;
								if (turn > 0)
									turn -= 1;
								printf("%d만큼 피해를 입혔다!\n", hatk - ch_dps);
								printf("----------------------\n");
								printf("아무키 press");
								_getch();
								system("cls");
							}
							else if(c == '2')
							{
								hhp += rand()%4+3;
								hatk += rand()%3;
								hdps += rand()%3;
								printf("기를 모와 더 강해 졌다.\n");
								if (turn > 0)
									turn -= 1;
								printf("----------------------\n");
								printf("아무키 press");
								_getch();
								system("cls");
							}
							else if(c == '3' && turn == 0)
							{
								printf("                                                  \n");
							    printf("                                                  \n");
							    printf("                                                  \n");
							    printf("                                                  \n");
							    printf("                                                  \n");
							    printf("                                                  \n");
							    printf("                       .--.                       \n");
							    printf("                     ,-~~~~-.                     \n");
							    printf("                    ,~~~~~~~-                     \n");
							    printf("                   .~~~~~~~-,                     \n");
							    printf("                   -~~~~~~-                       \n");
							    printf("               .   ~~~~~~-  .-~-.                 \n");
							    printf("              -~.  ~~~~~~. ,~~~~~-.               \n");
							    printf("             ~~~.  -~~~-, .~~~~~~~~.              \n");
							    printf("            ,~~~-  .~~,   -~~~~~~~~-              \n");
							    printf("            -~~~~,  .~.  ., ,~~~~~~~.             \n");
							    printf("            -~~~~~-  .,      ,~~~~~~.             \n");
							    printf("            -~~~~~~          .~~~~~~.             \n");
							    printf("            .~~~~~~             .~~~.             \n");
							    printf("             -~~~~~-        ,--  .~-              \n");
							    printf("              -~~~~~~,       -~~. ,.              \n");
							    printf("               ~~~~~.        ,~~~,                \n");
							    printf("                .,.     ..   -~~~-                \n");
							    printf("              ,-,  ,-,  -. .-~~~~~                \n");
							    printf("              ,~~~~~~~~~~. .~~~~~~                \n");
							    printf("              ,~~~~~~~~~~.  ~~~~~-                \n");
							    printf("               ~~~~~~~~~~. .~~~~~,                \n");
							    printf("               ,~~~~~~~~-  -~~~~~.                \n");
							    printf("                ,~~~~~~-  .~~~~~,                 \n");
							    printf("                  ,,,,.   -~~~-,                  \n");
							    printf("                            .                     \n");
							    printf("                                                  \n");
							    printf("                                                  \n");
							    printf("                                                  \n");
							    printf("                                                  \n");
							    printf("                                                  \n");
							    printf("                                                  \n");
								printf("    이  십  사  수  매  화  검  법  !  !\n");
								
								ch_hp -= hatk * 2;
								turn = 4;
								printf("--------------------------------------------\n");
								printf("아무키 press");
								_getch();
								system("cls");
								printf("%d만큼 피해를 입혔다!\n", hatk * 2);
								printf("-------------------\n");
								printf("아무키 press");
								_getch();
								system("cls");
							}
							else if(c == '3' && turn != 0)
							{
								printf("%d턴이 지나야 사용할 수 있다!\n", turn);
								printf("----------------------\n");
								printf("아무키 press");
								_getch();
								system("cls");
								continue;
							}
							else
								continue;
							
							if(ch_hp <= 0)
							{
								printf("%s을(를) 쓰러뜨렸다!!\n", ch_name);
								printf("----------------------\n");
								printf("아무키 press");
								_getch();
								system("cls");
								printf("100원을 얻었다!!\n");
								printf("----------------\n");
								printf("아무키 press");
								_getch();
								system("cls");
								money += 100;
								break;
							}
							
							int ene = rand()%5+1;
							if (ene == 1 || ene == 3)
							{
								hhp -= ch_atk - hdps;
								printf("%d만큼 피해를 입었다!\n", ch_atk - hdps);
								printf("----------------------\n");
								printf("아무키 press");
								_getch();
								system("cls");
							}
							else if (ene == 2 || ene == 4)
							{
								ch_hp += rand()%4+3;
								ch_atk += rand()%3;
								ch_dps += rand()%3;
								printf("%s이(가) 기를 모와 더 강해 졌다!\n", ch_name);
								printf("---------------------------\n");
								printf("아무키 press");
								_getch();
								system("cls");
							}
							else if (ene == 5)
							{
								hhp -= ch_atk * 2;
								printf("천 하 삼 십 육 검 법 !\n");
								printf("----------------------\n");
								printf("아무키 press");
								_getch();
								system("cls");
							}
							if(hhp <= 0)
							{
								printf("%s에게 쓰러졌다!!\n", ch_name);
								printf("----------------------\n");
								printf("아무키 press");
								_getch();
								system("cls");
								break;
							}
						}	
					}
					
					else if (c == 'q' || c == 'n' || c == 'N')
					{
						system("cls");
						break;
					}
				}
			}
		}
    }
	return 0;
}
