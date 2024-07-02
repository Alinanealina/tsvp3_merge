#include <iostream>
using namespace std;
const int N = 8;
int main()
{
	setlocale(LC_ALL, "Russian");
    int A[N], i, j, obm, M = 0, C = 0, k, B[N], m, L1, L2, R1, R2;
	cout << " " << N << " чисел: ";
    for (i = 0; i < N; i++)
        cin >> A[i];
	cout << "\n Исходный массив: ";
	for (i = 0; i < N; i++)
		cout << A[i] << " ";

    cout << "\n Сортировка по:";
    for (i = 1; i < N; i *= 2)
    {
        m = 0;
        for (L1 = 0; L1 + i < N; L1 = R2 + 1)
        {
            L2 = L1 + i;
            R1 = L2 - 1;
            R2 = R1 + i;
            if (R2 >= N)
                R2 = N - 1;
            for (j = L1, k = L2; j <= R1 && k <= R2; m++)
            {
                if (A[j] <= A[k])
                    B[m] = A[j++];
                else
                    B[m] = A[k++];
                M++;
                C++;
            }
            while (j <= R1)
            {
                B[m++] = A[j++];
                M++;
            }
            while (k <= R2)
            {
                B[m++] = A[k++];
                M++;
            }
        }
        for (j = L1; m < N; j++, m++)
        {
            B[m] = A[j];
            M++;
        }

        cout << "\n " << i * 2 << "-ам: ";
        for (j = 0; j < N; j++)
        {
            A[j] = B[j];
            cout << A[j] << " ";
        }
    }

	cout << "\n Отсортированный MergeSort массив: ";
	for (i = 0; i < N; i++)
		cout << A[i] << " ";
	cout << "\n________________________________\n Количество операций:\n -сравнения " << C << "\n -присваивания " << M << "\n -их сумма " << C + M << endl;
	return 0;
}