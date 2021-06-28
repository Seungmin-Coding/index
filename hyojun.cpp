#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct rectangle {
    int x, y; // 사각형 중심 좌표
    int width, height; // 사각형 높이, 너비
}rectangle;

void createRect(rectangle r[]);
double IoU(rectangle* r1, rectangle* r2);
void printStruct(rectangle r[]);

int main()
{
    srand(time(NULL)); // 랜덤함수
    rectangle r[10]; // rectangle 구조체 10개 선언
    double res[10][10]; // IOU결과 값 저장할 이중 배열
    createRect(r); // rectangle 구조체 안에 값들 저장
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            res[i][j] = IoU(r + i, r + j); // IoU값을 계산해서 res배열에 하나씩 집어넣음
    }

    for (int i = 0; i < 10; i++) // res배열에 있는 값을 모두 출력
    {
        for (int j = 0; j < 10; j++)
            printf("%.lf ", res[i][j]);
        printf("\n");
    }
}

void createRect(rectangle r[]) // 구조체 안에 값을 지정하는 함수
{
    for (int i = 0; i < 10; i++)
    {
        (r + i)->x = rand() % 100;
        (r + i)->y = rand() % 100;
        (r + i)->height = rand() % 31 + 20;
        (r + i)->width = rand() % 31 + 20;
    }
}

double IoU(rectangle* r1, rectangle* r2) // IoU값 계산하는 함수
{
    double IOU;
    int rect_union; // 두 사각형의 넓이 합
    int rect_inter; // 두 사각형 겹치는 넓이
    rect_union = r1->height * r1->width + r2->height * r2->width; // 두 사각형의 넓이 합
    if (abs(r1->y - r2->y) < r1->height / 2 + r2->height / 2 && abs(r1->x - r2->x) < r1->width / 2 + r2->width / 2) // 두 사각형 안겹칠때
        rect_inter = 0;
    else { // 두 사각형이 겹칠때 값을 구한다음 rect_inter에 넣으면 될듯

    }
    IOU = rect_inter / rect_union;
    return IOU;
}

void printStruct(rectangle r[]) // 구조체에 저장된 값 모두 출력
{
    for (int i = 0; i < 10; i++)
        printf("x: %d y: %d height: %d width: %d\n", (r + i)->x, (r + i)->y, (r + i)->height, (r + i)->width);
}