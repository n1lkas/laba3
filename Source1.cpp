#include <iostream>
#include <ctime>
#include <Windows.h>


using namespace std;
int N;
void zadania(int a) {
    cout << "1. Используя арифметику указателей, заполняет квадратичную целочисленную матрицу порядка N (6,8,10) случайными числами от 1 до  N*N согласно схемам, приведенным на рисунках. Пользователь должен видеть процесс заполнения квадратичной матрицы (*Для манипуляции с элементами используйте только арифметику указателей)" << endl;
    cout << "2. Получает новую матрицу, из матрицы п. 1, переставляя ее блоки в соответствии со схемами (*Для манипуляции с элементами используйте только арифметику указателей)" << endl;
    cout << "3. Используя арифметику указателей, сортирует элементы bubble sort" << endl;
    cout << "4.Уменьшает, увеличивает, умножает или делит все элементы матрицы на введенное пользователем число (*Для манипуляции с элементами используйте только арифметику указателей)." << endl;
    cout << "5. idz: Заполните матрицу случайными числами от 1 до N^2. Создайте еще одну матрицу порядка N. Заполните ее случайными числами от 1 до N^2. Вычтите первую матрицу из второй, при этом отобразите все промежуточные выводы." << endl;

}
void zero(int* matrix, int size) {
    int* endMatrix = matrix + size * size - 1;
    for (int* i = matrix; i <= endMatrix; i++)
        *i = 0;
}


void printMatrix(int* matrix, int size) {
    
    for (int i = 0; i < size * size; i++) {
        if (i % size == 0 && i != 0) {
            cout << endl;
        }
        cout << *(matrix + i) << " ";
    }
    cout << endl;
}

//1
void spiral(int* matrix, int size) {
    zero(matrix, size);
    int value = 1;
    int startRow = 0, endRow = size - 1;
    int startCol = 0, endCol = size - 1;

    while (startRow <= endRow && startCol <= endCol) {
        for (int i = startCol; i <= endCol; i++) {
            *(matrix + startRow * size + i) = value++;
            system("cls");
            printMatrix(matrix, size);
            Sleep(100);
            
        }
       
        startRow++;

        for (int i = startRow; i <= endRow; i++) {
            *(matrix + i * size + endCol) = value++;
            system("cls");
            printMatrix(matrix, size);
            Sleep(100);
        }
        
        endCol--;

        if (startRow <= endRow) {
            for (int i = endCol; i >= startCol; i--) {
                *(matrix + endRow * size + i) = value++;
                system("cls");
                printMatrix(matrix, size);
                Sleep(100);
            }
            endRow--;
        }

        if (startCol <= endCol) {
            for (int i = endRow; i >= startRow; i--) {
                *(matrix + i * size + startCol) = value++;
                system("cls");
                printMatrix(matrix, size);
                Sleep(100);
            }
            
            startCol++;
        }
    }
}

void snake(int* matrix, int size) {
    zero(matrix, size);
    int value = 1;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < size; j++) {
                *(matrix + j * size + i) = value++;
                system("cls");
                printMatrix(matrix, size);
                Sleep(100);
                
            }
        }
        else {
            for (int j = size - 1; j >= 0; j--) {
                *(matrix + j * size + i) = value++;
                system("cls");
                printMatrix(matrix, size);
                Sleep(100);
            }
        }
    }
}
//2
void changeA(int* matrix, int size) {
    int tmp;
    
    for (int i = 0; i < size / 2; i++)
    {
        for (int j = 0; j < size / 2; j++)
        {
            int* a = matrix + i * size + j;
            int* b = matrix + size / 2 + i * size + j;
            int* c = a + (size / 2) * size;
            int* d = b + (size / 2) * size;
            tmp = *a;
            *a = *c;
            *c = *d;
            *d = *b;
            *b = tmp;
        }
    }
   
}

void changeB(int* matrix, int size) {
    
    for (int i = 0; i < size / 2; i++)
    {
        for (int j = 0; j < size / 2; j++)
        {
            int* a = matrix + i * size + j;
            int* b = matrix + size / 2 + i * size + j;
            int* c = a + (size / 2) * size;
            int* d = b + (size / 2) * size;
            swap(*a, *d);
            swap(*b, *c);

        }
    }

}

void  changeC(int* matrix, int size) {
    
    for (int i = 0; i < size / 2; i++)
    {
        for (int j = 0; j < size / 2; j++)
        {
            int* a = matrix + i * size + j;
            int* b = matrix + size / 2 + i * size + j;
            int* c = a + (size / 2) * size;
            int* d = b + (size / 2) * size;
            swap(*a, *c);
            swap(*b, *d);

        }
    }

}

void  changeD(int* matrix, int size) {
    
    for (int i = 0; i < size / 2; i++)
    {
        for (int j = 0; j < size / 2; j++)
        {
            int* a = matrix + i * size + j;
            int* b = matrix + size / 2 + i * size + j;
            int* c = a + (size / 2) * size;
            int* d = b + (size / 2) * size;
            swap(*a, *b);
            swap(*c, *d);

        }
    }

}

//3
void sort_bubble(int* matrix, int size) {
    for (int i = 0; i < size * size - 1; i++) {
        for (int j = 0; j < size * size - i - 1; j++) {
            if (*(matrix + j) > *(matrix + j + 1)) {
                int temp = *(matrix + j);
                *(matrix + j) = *(matrix + j + 1);
                *(matrix + j + 1) = temp;
            }
        }
    }
}

//4
void modifyMatrix(int* matrix, int size, int number, int operation) {
   
    for (int i = 0; i < size * size; i++) {
            switch (operation) {
            case '+':
                *(matrix + i) += number;
               
                break;
            case '-':
                *(matrix + i) -= number;
                
                break;
            case '*':
                *(matrix + i) *= number;
               
                break;
            case '/':
                *(matrix + i) /= number;
                
                break;
            
          
            }
            system("cls");
            printMatrix(matrix, size);
            Sleep(100);
        }
    }

//idz
void fillMatrix(int* matrix, int size, int n) {
   
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            *(matrix + i * size + j) = rand() % 99;
            
        }
    }
}

void subMatrices(int* matrix1, int* matrix2, int* result, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            *(result + i * size + j) = *(matrix2 + i * size + j) - *(matrix1 + i * size + j); 
        }
    }
}

int main() {
    setlocale(0, "");
    int choice;
    bool p = true;
    
    while (p) {
        zadania(N);
        cout << "Выберите номер задания:" << endl;
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1:
        //1.1
        {srand(time(NULL));
        int N;
        cout << "Введите порядок матрицы (6, 8 или 10): ";
        cin >> N;

        if (N != 6 && N != 8 && N != 10) {
            cout << "Некорректный размер матрицы. Введите 6, 8 или 10." << endl;
            return 1;
        }
        cout << "Спиральная матрица:" << endl;
        int* matrix = new int[N * N];
        spiral(matrix, N);
        
        delete[] matrix;
        }
        //1.2
        {srand(time(NULL));

        int N;
        cout << "Введите порядок матриц (6, 8 или 10): ";
        cin >> N;

        if (N != 6 && N != 8 && N != 10) {
            cout << "Некорректный размер матриц. Введите 6, 8 или 10." << endl;
            return 1;
        }
        cout << "Змейка матрица:" << endl;
        int* matrix = new int[N * N];
        snake(matrix, N);
        
        delete[] matrix;
        }
            break;
        case 2:
        {srand(time(NULL));

        int N;
        cout << "Введите порядок матрицы (6, 8 или 10): ";
        cin >> N;

        if (N != 6 && N != 8 && N != 10) {
            cout << "Некорректный размер матрицы. Введите 6, 8 или 10." << endl;
            return 1;
        }
        int* matrix = new int[N * N];
        spiral(matrix, N);
        cout << "Исходная матрица" << endl;
        printMatrix(matrix, N);
        //A
        changeA(matrix, N);

        cout << "После перестановки A" << endl;
        printMatrix(matrix, N);

        //B
        
        changeB(matrix, N);

        cout << "После перестановки B" << endl;
        printMatrix(matrix, N);

        //C
        
        changeC(matrix, N);

        cout << "После перестановки C" << endl;
        printMatrix(matrix, N);

        //D
        
        changeD(matrix, N);

        cout << "После перестановки D" << endl;
        printMatrix(matrix, N);

        delete[] matrix;
        }
            break;
        case 3:

        {srand(time(NULL));
       
        int N;
        cout << "Введите порядок матрицы (6, 8 или 10): ";
        cin >> N;

        if (N != 6 && N != 8 && N != 10) {
            cout << "Некорректный размер матрицы. Введите 6, 8 или 10." << endl;
            return 1;
        }

        int* matrix = new int[N * N];
        cout << "Неотсортированная матрица:" << endl;
        zero(matrix, N);
        for (int i = 0; i < N * N; i++) {
            *(matrix + i) = rand() % (N * N) + 1;
            system("cls");
            printMatrix(matrix, N);
            Sleep(100);
        }

        sort_bubble(matrix, N);
        cout << "Отсортированная матрица:" << endl;
        printMatrix(matrix, N);
        delete[] matrix;
        }
            break;

        case 4:
        {int number;
        char operation;
        srand(time(NULL));
        int N;
        cout << "Введите порядок матрицы (6, 8 или 10): ";
        cin >> N;

        if (N != 6 && N != 8 && N != 10) {
            cout << "Некорректный размер матрицы. Введите 6, 8 или 10." << endl;
            return 1;
        }
        int* matrix = new int[N * N];

        spiral(matrix, N);
        
        cout << "Введите операцию (+, -, *, /): ";
        cin >> operation;
        cout << "Введите число-модификатор: ";
        cin >> number;
       
        modifyMatrix(matrix, N, number, operation);
        
        delete[] matrix;
        }
        break;
        case 5:
        {srand(time(0));

        int N;
        cout << "Введите порядок матрицы (6, 8 или 10): ";
        cin >> N;

        int* matrix1 = new int[N * N];
        int* matrix2 = new int[N * N];
        int* resultMatrix = new int[N * N];
        cout << "Матрица 1:" << endl;
        zero(matrix1, N);
        for (int i = 0; i < N * N; i++) {
            *(matrix1 + i) = rand() % (N * N) + 1;
            system("cls");
            printMatrix(matrix1, N);
            Sleep(100);
        }
        cout << "Матрица 2:" << endl;
        zero(matrix2, N);
        for (int i = 0; i < N * N; i++) {
            *(matrix2 + i) = rand() % (N * N) + 1;
            system("cls");
            printMatrix(matrix2, N);
            Sleep(100);
        }
       
        subMatrices(matrix2, matrix1, resultMatrix, N);
        system("cls");
        cout << "Результат вычитания:" << endl;
        printMatrix(resultMatrix, N);
        Sleep(100);
        delete[] matrix1;
        delete[] matrix2;
        delete[] resultMatrix;
 
        }
            break;
            system("pause");
            system("cls");
        }
    }
}