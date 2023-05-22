#include "CRUD.h"
#include "file.h"
#include "graph.h"
#include "menu.h"
#include "rest.h"
#include "search.h"
#include "calendar.h"
#include "queue.h"

void showMenu();

int main() {

    
//isFull�� ���� �ʱ�ȭ
for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 31; j++) {
        for (int k = 0; k < 16; k++) {
            for(int y=0; y<12; y++){
            dates[i][j].tables[k].customer[y].name[0] = '\0';
            dates[i][j].tables[k].customer[y].people =0;
            dates[i][j].tables[k].customer[y].full = 0;
            }
            dates[i][j].tables[k].isFull = 0;
        }
        dates[i][j].isFull = 0;
    }
    
}
int selc; //����
int tableNumber;
char guestName[50];
int guestAge, menuChoice,  reservationDuration;
int month, year;
int menuCount, Phone;
int mm, dd;
int time;

ResetMenu();

do {
    showMenu();
    printf("�޴��� �Է��ϼ��� : ");
    scanf("%d", &selc);

    switch (selc) {
        case 1:
            printf("��¥�� �Է��ϼ���(�� ��) : ");
            scanf("%d %d", &mm, &dd);
            listSeat(mm, dd);
            break;
        case 2:
            printf("��¥�� �Է��ϼ���(�� ��) : ");
            scanf("%d %d", &mm, &dd);

            printf("���̺� ��ȣ�� �Է��ϼ��� (0-15): ");
            scanf("%d", &tableNumber);

            printf("�մ� �̸��� �Է��ϼ���(���� ����): ");
            scanf("%s", guestName);
           // getchar();

            printf("�մ� ��ȭ��ȣ�� �Է��ϼ���: ");
            scanf("%d", &Phone);

            printMenu();
            printf("�޴��� �����ϼ��� (1-3): ");
            scanf("%d", &menuChoice);

            printf("������ �����ϼ��� (1-3): ");
            scanf("%d", &menuCount);

            printf("��ú��� �����Ͻ� �ǰ���? ");
            scanf("%d", &time);

             printf("���� �Ⱓ�� �Է��ϼ��� (�ð� ����): ");
             scanf("%d", &reservationDuration);

            // ���� �߰�
            addSeat(mm, dd, tableNumber, guestName, Phone, reservationDuration, menuChoice, menuCount, time);
            break;
        case 3:
            printMenu() ;
            printf("��¥�� �Է��ϼ���(�� ��) : ");
            scanf("%d %d", &mm, &dd);

            printf("���̺� ��ȣ�� �Է��ϼ��� (0-15): ");
            scanf("%d", &tableNumber);

            printf("�մ� �̸��� �Է��ϼ���: ");
            scanf("%s", guestName);


            updateSeat(mm,dd, tableNumber, guestName);
            break;
        case 4:
            printf("��¥�� �Է��ϼ���(�� ��) : ");
            scanf("%d %d", &mm, &dd);

            printf("���̺� ��ȣ�� �Է��ϼ��� (0-15): ");
            scanf("%d", &tableNumber);

            printf("�մ� �̸��� �Է��ϼ���: ");
            scanf("%s", guestName);

            printf("�մ� ��ȭ��ȣ�� �Է��ϼ���(���� ����): ");
            scanf("%d", &Phone);

            deleteSeat(mm,dd, tableNumber, guestName, Phone);
            break;
        case 5:
            printf("��¥�� �Է��ϼ���(�� ��) : ");
            scanf("%d %d", &mm, &dd);

            printf("�մ� �̸��� �Է��ϼ���: ");
            scanf("%s", guestName);

            search(mm,dd, guestName);
            break;
        case 6:
            
            printf("�޷��� ǥ���� ���� �Է��ϼ��� (1-12): ");
            scanf("%d", &mm);
            printf("�޷��� ǥ���� �⵵�� �Է��ϼ���: ");
            scanf("%d", &year);

            displayCalendar(mm - 1, year);
            break;
        case 7:
            printf("Ȯ���ϰ� ���� ���� �Է��ϼ���: ");
            scanf("%d", &mm);
            showGraph(mm);
            break;
        case 8:
            printf("�޹����� �Է��ϼ���: ");
            scanf("%d %d", &mm, &dd);
            rest(mm,dd);
            break;
        case 9:
            printf("���Ͽ� ������ ������ ���� �Է��ϼ���: ");
            scanf("%d", &mm);
            saveList(mm);
            break;
        case 10:
            printList();
            break;
        case 11:
            showQueue(&queue);
            break;
    }

    printf("\n");
} while (selc != 0);

return 0;
}


void showMenu(){
    printf("����������������������������������������\n");
    printf("��       �޴�       ��\n");
    printf("����������������������������������������\n");
    printf("�� 1. ���� ��Ȳ     ��\n");
    printf("�� 2. ���� �߰�     ��\n");
    printf("�� 3. ���� ����     ��\n");
    printf("�� 4. ���� ����     ��\n");
    printf("�� 5. �� ���� ��ȸ��\n");
    printf("�� 6. Ķ���� ����   ��\n");
    printf("�� 7. �������� Ȯ�� ��\n");
    printf("�� 8. �޾���¥ ���� ��\n");
    printf("�� 9. ���� ����     ��\n");
    printf("�� 10. ���� ����    ��\n");
    printf("�� 11. ����� Ȯ�Φ�\n");
    printf("�� 0. ����          ��\n");
    printf("����������������������������������������\n");
}

