// Л.р. №1
// Monte Karlo

#include <iostream>
#include <bitset>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0)));

    bool key;              // Проверка на повтор строки
    int i = 0, j = 0;
    int max = 0;         // Максимальное значение приспособленности
    int L = 15;         // Длина кодировки
    int p=0;           // Приспособленность
    int N = 0;        // Число шагов
    int s[32];       // Массив десятичных чисел
    int x = 0;      // Сами десятичные числа 
    string M[32];  // Массив бинарных строк
    string* Z;
    int* R;
    string maxS = " ";  // Пустая кодировка (далее максимальная)
    int D[40];
    int P[32];
 
    for (int i = 0; i <32 ; i++)
    {
        string S;
        for (int i = 0; i < L; i++)   // Cоздаем случайную строку
        {
            int a = rand() % 2;
            S += '0' + a;  
        } 
        M[i] = S;
       
             cout << "S: " << S << '\t';
        
        for (int i = 0; i < L; i++)  // Переводим из двоичной в десятичную
        {
            x *= 2;
            x += S[i] - '0';
            S[i] = x;
        }
        P[i] = (x - pow(2, (L - 1))) * (x - pow(2, (L - 1)));
        cout << "приспособленность:" << P[i] << endl;
        cout << "x: " << x << endl;
        x = 0;
    }

    cout << endl;
    cout << "Введите число шагов" << endl;
    cin >> N;

    Z = new string [N];    // Бинарный массив без повторений
    i = 0;
    R = new int[N];       // Ландшафт приспособленностей
    
    while (i < N)
    {
        cout << endl;
        key=false;
        int r = rand() % 32;
        string t = M[rand() % 32];     // Генератор случайной строки из бинарного массива 
        cout << "Случайное значение: " << t << endl;
        Z[i] = t;

        cout << "Приспособленность: " << P[r] << endl;

            if (P[r] > max)
            {
                cout << "Значение максимума изменилось!" << endl;
                maxS = Z[i];
                max = P[r];
            }
            i++;
            cout << endl;
            cout << "i= " << i <<"     "<< "maxS= " << maxS << "     "<< "max= " << max <<endl;      
    }
    cout << endl;
  
    delete[]Z;
    delete[]R;
}