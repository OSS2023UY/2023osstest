// #include <stdio.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <setting.h>


// // 파일 저장 함수
// void saveList(day *day) {
//     char filename[100];
//     printf("저장할 파일의 이름을 입력하세요: ");
//     scanf("%s", filename);

//     FILE *fp;
//     fp = fopen(filename, "w"); // 사용자가 입력한 파일 이름으로 파일 열기

//     if (fp == NULL) {
//         printf("파일을 열 수 없습니다.\n");
//         return;
//     }


//     // 파일에 예약 정보 쓰기
//     for(int i=0; i<16; i++){
//         for(int j=0; j<12; i++){
//         printf("%s %d %d %d %d\n", day[mm-1][dd-1]->table[i]->customer[j]->name, day[mm-1][dd-1]->table[i]->customer[j]->people, day[mm-1][dd-1]->table[i]->customer[j]->phoneNum, day[mm-1][dd-1]->table[i]->customer[j]->price,day[mm-1][dd-1]->table[i]->customer[j]->isPaid);
//         }
//     }

//     fclose(fp); // 파일 닫기
// }

// // 파일 출력 함수
// void printList() {
//     FILE *fp;
//   //  struct Reservation list[MAX_LIST_SIZE];
//     int countt = 0;

//     fp = fopen("reservation_list.txt", "r"); // 파일 열기

//     if (fp == NULL) {
//         printf("파일을 열 수 없습니다.\n");
//         return;
//     }

//     // 파일에서 예약 정보 읽어오기
//     while (fscanf(fp, "%s %d %s %d %d %s %[^\n]"), list[countt]->name, &list[countt].num_people, list[countt].phone, &list[count].price, &list[count].check, list[count].time, list[count].notes) != EOF) {
//         count++;
//     }

//     fclose(fp); // 파일 닫기

//     // 예약 정보 출력
//     printf("=============================================================\n");
//     printf("번호\t이름\t인원수\t전화번호\t가격\t결제 완료\t시간대\t추가 사항\n");
//     printf("=============================================================\n");
//     for (int i = 0; i < count; i++) {
//         printf("%d\t%s\t%d\t%s\t%d\t%s\t%s\t%s\n", i + 1, list[i]->name, list[i].num_people, list[i].phone, list[i].price, list[i].check == 1 ? "O" : "X", list[i].time, list[i].notes);
//     }
//     printf("=============================================================\n");
// }