#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int f15(int a) {
    int n, k, s = 0;
    for (n = a; n != 0; n = n / 10) {
        k = n % 10;
        s = s * 10 + k;
    }
    return s;
}

int* f24(int* A, int n) {
    int j = 0;
    int s, m;
    int* B = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        if (abs(A[i]) == 1 || A[i] == 0) continue;
        for (s = 0, m = 2; m < A[i]; m++)
            if (A[i] % m == 0) {
                s = 1;
                break;
            }
        if (s == 0) B[j++] = A[i];
    }
    
    if (j < n) B[j] = 0;
    return B;
}

int f29(int* A, int n) {
    int v = A[0];

    for (int i = 0; i < n; i++)
        if (A[i] % v != 0) {
            v--;
            i = -1;
        }

    return v;
}

typedef struct {
    int numberOfEntries;
    int index;
} MostCommonNumber;

MostCommonNumber f37(int* c, int n) {
    int s = 0, m, b;
    for (int i = 0; i < n - 1; i++) {
        m = 1;
        for (int j = i + 1; j < n; j++)
            if (c[i] == c[j]) m++;
        if (m > s) {
            s = m;
            b = i;
        }
    }

    return (MostCommonNumber){ s, b };
}

int f51(int* A, int n) {
    int s = A[0];
    for (int i = 0; i < n; i++)
        if (A[i] > s) s = A[i];

    return s;
}


void startF15() { 
    printf("��� ������� ������������� ������������� �����\n");

    int num;

    printf("������� �����\n");
    scanf_s("%d", &num);

    int res = f15(num);
    printf("%d\n\n", res);
}

void startF24() { 
    printf("��� ������� �������� �� ��������� ������� ������������� ����� � ����� ������ ������� �����\n");

    int n;
    printf("������� ������ �������\n");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n*4);
    printf("%������� %d �����\n", n);
    for (int i = 0; i < n; i++) 
        scanf_s("%d", &arr[i]);

    int* res = f24(arr, n);
    int newSize, i;
    for (i = 0; res[i] != 0 && i < n; i++)
        printf("%d ", res[i]);
    printf("\n\n");
    newSize = i;

}

void startF29() { 
    printf("��� ������� ���� ���������� ����� �������� ��� ���� ��������� �������\n");

    int n;
    printf("������� ������ �������\n");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * 4);
    printf("%������� %d �����\n", n);
    for (int i = 0; i < n; i++)
        scanf_s("%d", &arr[i]);

    int res = f29(arr, n);
    printf("%d\n\n", res);
}

void startF37() { 
    printf("��� ������� ���� ����� ���������������� ����� � ������ � ���������� ���-�� ��������� � ������ ���������\n");

    int n;
    printf("������� ������ �������\n");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * 4);
    printf("%������� %d �����\n", n);
    for (int i = 0; i < n; i++)
        scanf_s("%d", &arr[i]);

    MostCommonNumber res = f37(arr, n);
    printf("���-�� ���������: %d\n������ ���������: %d\n\n", res.numberOfEntries, res.index);
}

void startF51() {
    printf("��� ������� ���� �������� � �������\n");

    int n;
    printf("������� ������ �������\n");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * 4);
    printf("%������� %d �����\n", n);
    for (int i = 0; i < n; i++)
        scanf_s("%d", &arr[i]);

    int res = f51(arr, n);
    printf("%d\n\n", res);

}

int main() {
    system("chcp 1251");

    int userChoice = 10;

    while (userChoice != 0) {
        printf("�������� �������:\n1) F15\n2) F24\n3) F29\n4) F37\n5) F51\n0) ��������� ���������\n");
        scanf_s("%d", &userChoice);

        switch (userChoice)
        {
        case 1: { startF15(); break; }
        case 2: { startF24(); break; }
        case 3: { startF29(); break; }
        case 4: { startF37(); break; }
        case 5: { startF51(); break; }
        default:
            break;
        }
    }

}