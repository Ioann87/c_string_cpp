#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int MAXLEN = 2048;

void memory_cleaner(char* array);
void memory_cleaner(int* array);
void memory_cleaner(string* array);

//task1 count the number of sentences of each type in the text
void sentence(char* text, char* mark, int* count);
void counter(char* text, char* mark, int& count);
void output_result(int* count);

//task2 capital letter of a word in a sentence and back
void upper_case(char* text, char* mark);
void lower_case(char* text);

//task3 the number of all letters in the text
void output_result(char* alphabet, int* result);
//task4

//task5 find word in text
void word_counter(char* text, char* word, int& number);

//body tasks
void task_1(char* text, int* counter, int& len);
void task_2(char* text, char* punctuation);
void task_3(char* text, int* counter, int& len);
void task_4(char* text, int* counter, int& len);
void task_5(char* text);

int main()
{
    char* text = nullptr;
    text = new char[MAXLEN];
    cout << "Input string: " << endl;
    fgets(text, MAXLEN, stdin);

    int* counter = nullptr;
    int len = 0;

    //task1----------------------------------------------------------
    task_1(text, counter, len);
    counter = nullptr;

    //task2----------------------------------------------------------
    // run from void task_1()

    //task3----------------------------------------------------------
    task_3(text, counter, len);
    counter = nullptr;

    //task4----------------------------------------------------------
    task_4(text, counter, len);
    counter = nullptr;

    //task5----------------------------------------------------------
    task_5(text);

    memory_cleaner(text);
    system("pause");
    return 0;
}

void task_1(char* text, int* counter, int& len)
{
    cout << "Task 1: " << endl;
    char* punctuation = new char[4] { '.', '!', '?' };

    len = strlen(punctuation);
    counter = new int[len] { 0 };

    sentence(text, punctuation, counter);
    output_result(counter);

    //task2------------------
    task_2(text, punctuation);

    memory_cleaner(counter);
    memory_cleaner(punctuation);
    return;
}

void task_2(char* text, char* punctuation)
{
    cout << "Task 2: " << endl;
    upper_case(text, punctuation);
    puts(text);
    lower_case(text);
    puts(text);

    return;
}

void task_3(char* text, int* counter, int& len)
{
    cout << "Task 3: " << endl;
    char* alphabet = new char[27] {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
        'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
        's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'
    };

    len = strlen(alphabet);

    counter = new int[len] { 0 };

    sentence(text, alphabet, counter);
    output_result(alphabet, counter);

    memory_cleaner(counter);
    memory_cleaner(alphabet);
    return;
}

void task_4(char* text, int* counter, int& len)
{
    cout << "Task 4: " << endl;
    char* digits = new char[11] {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
    };

    len = strlen(digits);

    counter = new int[len] { 0 };

    sentence(text, digits, counter);
    output_result(digits, counter);

    int quantity = 0;

    for (int i = 0; i < len; i++) {
        quantity += counter[i];
    }

    cout << "Quantity of digits in text - " << quantity << endl;

    memory_cleaner(counter);
    memory_cleaner(digits);
    return;
}

void task_5(char* text)
{
    cout << "Task 5: " << endl;

    char* word = nullptr;
    word = new char[MAXLEN];
    cout << "Input word: ";
    cin >> word;

    int quantity = 0;

    word_counter(text, word, quantity);

    cout << word << " reapeted in text " << quantity << " times." << endl;

    memory_cleaner(word);
    return;
}

void word_counter(char* text, char* word, int& quantity)
{
    char* res = nullptr;

    res = text;
    do {
        res = strstr(res, word);
        if (res == nullptr) {
            break;
        }
        quantity++;
        res++;
    } while (true);

    return;
}

void sentence(char* text, char* mark, int* count)
{
    int len = strlen(mark);

    for (int i = 0; i < len; i++) {
        counter(text, (mark + i), *(count + i));
    }

    return;
}

void counter(char* text, char* mark, int& count)
{
    char* res = nullptr;

    res = text;
    do {
        res = strchr(res, *mark);
        if (res == nullptr) {
            break;
        }
        count++;
        res++;
    } while (true);

    return;
}

void upper_case(char* text, char* mark)
{
    char* res = nullptr;

    res = text;
    res[0] -= 32;

    do {
        res = strpbrk(res, mark);
        if (res == nullptr) {
            break;
        }
        res++;
        if (*(res + 1) == '\0') {
            break;
        }
        res[1] -= 32;
    } while (true);

    return;
}

void lower_case(char* text)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        if ('A' <= text[i] && text[i] <= 'Z') {
            text[i] += 32;
        }
    }
    return;
}

void output_result(int* count)
{
    string* str_res = new string[MAXLEN] { "dot", "exclamation", "quetion" };
    for (int i = 0; i < 3; i++) {
        cout << str_res[i] << " = " << count[i] << endl;
    }

    memory_cleaner(str_res);
    return;
}

void output_result(char* alphabet, int* count)
{
    int len = strlen(alphabet);
    for (int i = 0; i < len; i++) {
        if (count[i] != 0) {
            cout << alphabet[i] << " - " << count[i] << endl;
        }
    }
    return;
}

void memory_cleaner(char* array)
{
    delete[] array;
    return;
}
void memory_cleaner(int* array)
{
    delete[] array;
    return;
}
void memory_cleaner(string* array)
{
    delete[] array;
    return;
}
