#include <iostream>
#include <cstdlib>
#include <locale>
#include <vector>
#include <ctime>
#include <stdio.h>
//#include <bits/stdc++.h>
using namespace std;

// Функция для генерации случайного числа от 0 до 1
double generateRandom() {
    return rand() / (RAND_MAX + 1.0);
}

// Функция для генерации последовательности из 1 и 0 с заданной вероятностью
vector<bool> generateBitSequence(int length, double probability) {
    vector<bool> bitSequence;
    for (int i = 0; i < length; ++i) {
        double randomValue = generateRandom();
        bool bit = (randomValue < probability);
        bitSequence.push_back(bit);
    }
    return bitSequence;
    }

int main() {
    setlocale(LC_ALL, "russian");

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(nullptr)));

    // Задаем длину последовательности и вероятность появления символа 1
    int length;
    double probability;

    cout << "Введите длину строки: ";
    cin >> length;

    cout << "Введите вероятность появления символа 1 (от 0 до 1, p): ";
    cin >> probability;

    // Проверка корректности введенных данных
    if (probability < 0 || probability > 1) {
        cerr << "Ошибка: Вероятность должна быть в пределах от 0 до 1." << endl;
        return 1;
    }

    cout << "Ожидайте..." << endl;

    // Генерация последовательности битов
    vector<bool> generatedBitSequence = generateBitSequence(length, probability);

    // Подсчет частости
    int countOnes = 0;
    for (bool bit : generatedBitSequence) {
        if (bit) {
            countOnes++;
        }
    }

    // Вывод частости 1
    double percentageOnes = (static_cast<double>(countOnes) / length);
    cout << "p(*): " << percentageOnes << endl;

    // Вывод сгенерированной последовательности битов
    //cout << "Сгенерированная последовательность битов: ";
    //for (bool bit : generatedBitSequence) {
    //    cout << bit;
    //}
    //cout << endl;

    //cout << "Сгенерированная строка: " << generatedSequence << endl;
    //system("pause");

    return 0;
}

