#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct rectangle {
    int x, y; // �簢�� �߽� ��ǥ
    int width, height; // �簢�� ����, �ʺ�
}rectangle;

void createRect(rectangle r[]);
double IoU(rectangle* r1, rectangle* r2);
void printStruct(rectangle r[]);

int main()
{
    srand(time(NULL)); // �����Լ�
    rectangle r[10]; // rectangle ����ü 10�� ����
    double res[10][10]; // IOU��� �� ������ ���� �迭
    createRect(r); // rectangle ����ü �ȿ� ���� ����
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            res[i][j] = IoU(r + i, r + j); // IoU���� ����ؼ� res�迭�� �ϳ��� �������
    }

    for (int i = 0; i < 10; i++) // res�迭�� �ִ� ���� ��� ���
    {
        for (int j = 0; j < 10; j++)
            printf("%.lf ", res[i][j]);
        printf("\n");
    }
}

void createRect(rectangle r[]) // ����ü �ȿ� ���� �����ϴ� �Լ�
{
    for (int i = 0; i < 10; i++)
    {
        (r + i)->x = rand() % 100;
        (r + i)->y = rand() % 100;
        (r + i)->height = rand() % 31 + 20;
        (r + i)->width = rand() % 31 + 20;
    }
}

double IoU(rectangle* r1, rectangle* r2) // IoU�� ����ϴ� �Լ�
{
    double IOU;
    int rect_union; // �� �簢���� ���� ��
    int rect_inter; // �� �簢�� ��ġ�� ����
    rect_union = r1->height * r1->width + r2->height * r2->width; // �� �簢���� ���� ��
    if (abs(r1->y - r2->y) < r1->height / 2 + r2->height / 2 && abs(r1->x - r2->x) < r1->width / 2 + r2->width / 2) // �� �簢�� �Ȱ�ĥ��
        rect_inter = 0;
    else { // �� �簢���� ��ĥ�� ���� ���Ѵ��� rect_inter�� ������ �ɵ�

    }
    IOU = rect_inter / rect_union;
    return IOU;
}

void printStruct(rectangle r[]) // ����ü�� ����� �� ��� ���
{
    for (int i = 0; i < 10; i++)
        printf("x: %d y: %d height: %d width: %d\n", (r + i)->x, (r + i)->y, (r + i)->height, (r + i)->width);
}