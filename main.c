#define _CRT_SECURE_NO_WARNINGS  // Отключение предупреждений о небезопасных функциях (например, scanf)
#include <stdio.h>               // Подключение библиотеки для работы с вводом/выводом
#include <stdlib.h>              // Подключение стандартной библиотеки для работы с памятью, математикой и т.д.
#include <time.h>                // Подключение библиотеки для работы с временем

// Структура для хранения даты
struct Date {
    int day;    // День месяца
    int month;  // Месяц года
    int year;   // Год
};

// Функция для вычисления возраста
int calculateAge(struct Date birthdate, struct Date currentDate) {
    int age = currentDate.year - birthdate.year;  // Начальный расчет возраста (разница между годами)

    // Если день рождения в текущем году ещё не был, уменьшаем возраст
    if (currentDate.month < birthdate.month || (currentDate.month == birthdate.month && currentDate.day < birthdate.day)) {
        age--;  // Уменьшаем возраст, если день рождения еще не был в текущем году
    }

    return age;  // Возвращаем возраст
}

int main() {
    struct Date birthdate, currentDate;  // Создаем две переменные типа Date для даты рождения и текущей даты

    // Получаем текущее время
    time_t t = time(NULL);  // Получаем текущее время в формате time_t (количество секунд с 1970 года)
    struct tm tm = *localtime(&t);  // Преобразуем time_t в структуру tm для получения компонентов времени

    // Извлекаем текущую дату
    currentDate.day = tm.tm_mday;  // Сохраняем день месяца
    currentDate.month = tm.tm_mon + 1;  // Сохраняем месяц (tm_mon начинается с 0, поэтому прибавляем 1)
    currentDate.year = tm.tm_year + 1900;  // Сохраняем год (tm_year отсчитывается от 1900 года)

    // Ввод даты рождения пользователя
    printf("Enter your birth day: ");  // Запрос дня рождения
    scanf("%d", &birthdate.day);  // Считываем день рождения
    printf("Enter your birth month: ");  // Запрос месяца рождения
    scanf("%d", &birthdate.month);  // Считываем месяц рождения
    printf("Enter your birth year: ");  // Запрос года рождения
    scanf("%d", &birthdate.year);  // Считываем год рождения

    // Вычисляем возраст и выводим его
    int age = calculateAge(birthdate, currentDate);  // Вычисляем возраст с помощью функции calculateAge
    printf("Your age is: %d years\n", age);  // Выводим результат

    return 0;  // Завершаем программу с кодом 0 (успешное выполнение)
}