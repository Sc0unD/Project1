#include <stdio.h>
#include <stdlib.h>

//--------------------------------------------------------15 �������� �����
int f15(int a) {
    int n, k, s = 0;
    for (n = a; n != 0; n = n / 10) {
        k = n % 10;
        s = s * 10 + k;
    }
    return s;
}
//--------------------------------------------------------24 �������� � ������� ������ ������� �����

int* f24(int* A, int n) {
    int j = 0;
    int s, m;
    int* B = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        if (A[i] == 1) continue;
        for (s = 0, m = 2; m < A[i]; m++)
            if (A[i] % m == 0) {
                s = 1;
                break;
            }
        if (s == 0) B[j++] = A[i];
    }
    B[j] = 0;
    return B;
}
//--------------------------------------------------------29 ����� ����������� ������ �������� ��� ����� �������
int f29(int* A, int n) {
    int v = A[0];

    for (int i = 0; i < n; i++)
        if (A[i] % v != 0) {
            v--;
            i = -1;
        }

    return v;
}

//--------------------------------------------------------37    // �������� �� ��������


//--------------------------------------------------------51 ����� ���������?
int f51(int* A, int n) {
    int s = A[0];
    for (int i = 0; i < n; i++)
        if (A[i] > s) s = A[i];

    return s;

}

//for (i = 0, s = 0; i < 10; i++)
//    if (A[i] > s) s = A[i];
//}

int main() {
    ////////////////////////15
    int num = 123456789;
    printf("%d\n", f15(num));

    ////////////////////////24
    int arr[] = { 1,2,3,4,5,6,7,8,9,10,51,12,13,14,15,16,17,18,19,20 };
    int n = sizeof(arr) / sizeof(int);
    int* newArr = f24(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", newArr[i]);
    }
    printf("\n");

    ////////////////////////29
    int NaibOD = f29(arr, n);
    printf("%d\n", NaibOD);

    ////////////////////////37 ����� �����, ������� ����������� ������ ����� ���, ������ ���-�� ��������� � ������ ������� ���������

    int c[] = { 0, 2, 0, 1, 1, 0, 2, 2, 2, 0 };
    int nC = sizeof(c) / sizeof(int);
    int s = 0, m, b;
    for (int i = 0; i < nC - 1; i++) {
        m = 1;
        for (int j = i + 1; j < nC; j++)
            if (c[i] == c[j]) m++;
        if (m > s) {
            s = m,
                b = i;
        }
    }
    printf("%d %d\n", c[b], s);

    ////////////////////////51

    printf("%d", f51(arr, n));

}