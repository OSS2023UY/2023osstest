#include "CRUD.h"
#include "setting.h"
#include "queue.h"

// ���� ���� �Լ�
void saveList(int mm) {
    char filename[100];

    sprintf(filename, "%d", mm);

    FILE *fp;
    fp = fopen(filename, "w"); // ����ڰ� �Է��� ���� �̸����� ���� ����

    if (fp == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    //�Ѹ��� ���
    int weekly_profit[5] = {0, 0, 0, 0, 0};  // �ֺ� ���� �迭 �ʱ�ȭ

    for (int j = 0; j < 31; j++) {
        // �ش� ���� ���� ���
        int week = j / 7;

        // ���� �մ��� �������� ������ ��� �ǳʶٱ�
        for (int n = 0; n < 16; n++) {
            for (int m = 0; m < 12; m++) {
                if (strcmp(dates[mm - 1][j].tables[n].customer[m].name, dates[mm - 1][j].tables[n].customer[m + 1].name) == 0) {
                    m++;  // ���� �մ����� �ǳʶٱ�
                } else {
                    weekly_profit[week] += dates[mm - 1][j].tables[n].customer[m].price;
                }
            }
        }
    }

    int totalMoney=0; //�Ѹ���
    for(int i=0; i<5; i++){
        totalMoney+=weekly_profit[i];
    }


    int totalCount=0; // �ȸ� ���� ����
    for (int j = 0; j < 31; j++) {
        for (int n = 0; n < 16; n++) {
                for (int m = 0; m < 12; m++) {
                    if (strcmp(dates[mm - 1][j].tables[n].customer[m].name, dates[mm - 1][j].tables[n].customer[m + 1].name) == 0) {
                        m++;  // ���� �մ����� �ǳʶٱ�
                    } else {
                        totalCount += dates[mm - 1][j].tables[n].customer[m].people;
                    }
                }
            }
    }
    
    //���� ���� �ȸ� ����
      int bestMenu[4]={0};
    for (int j = 0; j < 31; j++) {
      
        for (int n = 0; n < 16; n++) {
                for (int m = 0; m < 12; m++) {
                    if (strcmp(dates[mm - 1][j].tables[n].customer[m].name, dates[mm - 1][j].tables[n].customer[m + 1].name) == 0) {
                        m++;  // ���� �մ����� �ǳʶٱ�
                    } else {
                        if(strcmp(dates[mm-1][j].tables[n].customer[m].Menu, "ChickenSkewer")) bestMenu[0] +=dates[mm - 1][j].tables[n].customer[m].people;
                        else if(strcmp(dates[mm-1][j].tables[n].customer[m].Menu, "Ramen")) bestMenu[1] +=dates[mm - 1][j].tables[n].customer[m].people;
                        else if(strcmp(dates[mm-1][j].tables[n].customer[m].Menu, "Gimbob")) bestMenu[2] +=dates[mm - 1][j].tables[n].customer[m].people;
                        else if(strcmp(dates[mm-1][j].tables[n].customer[m].Menu, "Tteokbokki")) bestMenu[3] +=dates[mm - 1][j].tables[n].customer[m].people;
                    }
                }
            }
    }

    int max = bestMenu[0];
    for(int i=0; i<4; i++){
        if(max<bestMenu[i]) max =bestMenu[i];
    }

    char best[100];
    if(max ==best[0]) strcpy(best,"ChickenSkewer");
    else if(max ==best[1]) strcpy(best,"Ramen");
    else if(max ==best[2]) strcpy(best,"Gimbob");
    else if(max ==best[3]) strcpy(best,"Tteokbokki");


    fprintf(fp, "!%d��! \n�Ѹ����� %d�Դϴ�.\n�ȸ������� ������ %d�� �Դϴ�. \n���� ���� �ȸ� ������ %s�Դϴ�.", mm, totalMoney, totalCount, best);

    fclose(fp); // ���� �ݱ�
}

// ���� ��� �Լ�
void printList() {
    FILE *fp;
    char filename[100];
    int countt = 0;
    char line[100];

    printf("������ �̸��� �Է��ϼ���: ");
    scanf("%s", filename);
    fp = fopen(filename, "r"); // ���� ����

    if (fp == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    printf("���� ����:\n");

    // ������ ������ �� �پ� �о ���
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        countt++;
    }
}