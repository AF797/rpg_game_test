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
		printf("S:����  C:â��  H:�Ʒ���  B:����\n");
		
		char c;
		c = _getch();           // 3. ����Ű�� �Է��� �� 224 00 �� ���ۿ� �ִ�. 224���� ���ش�. 
        if (c == -32) {           // 4. -32�� �ԷµǸ�
            c = _getch();        // 5. ���� �� 00�� �Ǻ��Ͽ� �¿���� ���
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
					printf("1. ���ڻ�	1000��\n");
					printf("2. ���		1000��\n");
					printf("3. �����	1000��\n");
					printf("----------------------\n");
					printf("�ܾ� : %d  ������ : q\n", money);
					
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
							printf("��� ���� ���� ��������!!\n");
							printf("�� ����!!\n");
							printf("�ƹ�Ű press");
							c = _getch();
							system("cls");
							break;
						}
						else
						{
							system("cls");
							printf("�ܾ��� �����ϴٳ�!\n");
							printf("�ƹ�Ű press");
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
							printf("��� ���� ���� ��������!!\n");
							printf("�� ����!!\n");
							printf("�ƹ�Ű press");
							c = _getch();
							system("cls");
							break;
						}
						else
						{
							system("cls");
							printf("�ܾ��� �����ϴٳ�!\n");
							printf("�ƹ�Ű press");
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
							printf("��� ���� ���� ��������!!\n");
							printf("�� ����!!\n");
							printf("�ƹ�Ű press");
							c = _getch();
							system("cls");
							break;
						}
						else
						{
							system("cls");
							printf("�ܾ��� �����ϴٳ�!\n");
							printf("�ƹ�Ű press");
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
					printf("      â ��\n");
					printf("-----------------\n");
					printf("  ���ڻ�: %d\n", inven[0]);
					printf("  ��  ��: %d\n", inven[1]);
					printf("  �����: %d\n", inven[2]);
					printf("-----------------\n");
					printf("�ܾ� : %d  ������ : q\n", money);
					
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
					printf("      �Ʒ���\n");
					printf("-----------------\n");
					printf("  (�Ʒý�)  (+4)\n");
					printf("  �� HP    : %d\n", hp);
					printf("  �� ���ݷ�: %d\n", atk);
					printf("  �� ����: %d\n", dps);
					printf("-----------------\n");
					printf("���ڸ� ������ �Ʒ��Ѵٳ� (100��)\n");
					printf("�ܾ� : %d  ������ : q\n", money);
					
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
							printf("�ܾ��� �����ϴٳ�!\n");
							printf("�ƹ�Ű press");
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
							printf("�ܾ��� �����ϴٳ�!\n");
							printf("�ƹ�Ű press");
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
							printf("�ܾ��� �����ϴٳ�!\n");
							printf("�ƹ�Ű press");
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
