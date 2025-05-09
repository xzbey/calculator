# Руководство пользователя для калькулятора

Данный калькулятор представляет собой приложение на основе **Qt**, которое включает 2 основных модуля:

## Основные модули (*СКРИНШОТЫ ИНТЕРФЕЙСА В КОНЦЕ*)

- **Обычный калькулятор**  
  - Выполнение базовых математических операций  
  - Выполнение тригонометрических вычислений  

- **Геокалькулятор**  
  - Решение прямой геодезической задачи на плоскости  
  - Решение обратной геодезической задачи на плоскости  

## Запуск приложения

**Чтобы запустить приложение, существует 2 варианта:**

### Способ 1
1. Скачайте архив с проектом.  
2. Разархивируйте архив с проектом.  
3. Разархивируйте архив с названием `build.rar`, находящийся в папке с проектом, в эту же папку, чтобы появилась папка `build` в папке проекта.  
4. Перейдите по пути:  
   `...\calculator-main\build\build\Desktop_Qt_6_8_2_MinGW_64_bit-Release\release`  
   *Или пошагово:*  
   - Зайдите в папку проекта.  
   - Найдите папку `build`.  
   - Если внутри папки `build` есть еще одна папка `build`, перейдите в нее, если нет — оставайтесь.  
   - Перейдите в папку с названием `Desktop_Qt_6_8_2_MinGW_64_bit-Release`.  
   - Перейдите в папку с названием `release`.  
5. Найдите приложение с названием `calculator.exe` (или просто `calculator`, если не включены расширения файлов).  
6. Запустите приложение.  

### Способ 2  
*Может не работать на компьютерах со старой версией Qt.*  
1. Скачайте архив с проектом.  
2. Разархивируйте архив с проектом.  
3. Откройте среду Qt Creator.  
4. Найдите кнопку `Open Project...` и нажмите на неё.  
5. Найдите папку проекта и выберите для открытия файл с расширением `.pro`.  
6. Если проект не открылся, используйте первый способ.  
7. Если проект успешно открылся, нажмите на кнопку запуска слева снизу (зеленый треугольный)  

## Инструкция по использованию

При запуске приложения открывается окно с выбором одной из двух кнопок: для открытия обычного калькулятора и геокалькулятора.

### Обычный калькулятор

#### Описание
Модуль позволяет выполнять базовые арифметические операции и тригонометрические вычисления. Результаты округляются до 4-х знаков после запятой.

#### Интерфейс
- **Левая панель** включает список операций:  
  - `+` (сложение)  
  - `-` (вычитание)  
  - `*` (умножение)  
  - `/` (деление)  
  - `sin` (синус)  
  - `cos` (косинус)  
  - `tan` (тангенс)  
  - `ctan` (котангенс)  
  - `arcsin` (арксинус)  
  - `arccos` (арккосинус)  
  - `arctan` (арктангенс)  
  - `arcctan` (арккотангенс)  

- **Правая панель** включает:  
  - Поля ввода чисел (`Число 1` и, при необходимости, `Число 2`).  
  - Надпись, указывающая, что угол должен быть в градусах (для тригонометрических операций).  
  - Кнопка `Решить` для выполнения вычислений.  
  - Поле для вывода результата.  
  - Информационная надпись о округлении.  

#### Инструкция по использованию
1. Выберите операцию в меню слева.  
2. Введите значения в поля `Число 1` и, при необходимости, `Число 2`.  
3. Нажмите кнопку `Решить`.  
4. **Ошибки и предупреждения:**  
   - Для тригонометрических функций угол вводится в градусах. Если угол более 360 или менее 0, будет использован эквивалентный угол.  
   - Если операция невозможна (например, деление на 0), появится предупреждение.  
   - Аналогично для некорректных аргументов для `arcsin`, `arccos`, `tan`, `ctan`.

### Геокалькулятор

#### Описание
Модуль позволяет решать 2 геодезические задачи на плоскости:  
- **Прямая геодезическая задача**: Определение координат конечной точки B на основе начальной точки A, расстояния и угла (азимута).  
- **Обратная геодезическая задача**: Определение расстояния и угла (азимута) между двумя точками A и B по их координатам.  

Подробнее:  
- Прямая задача - https://terraingis.ru/pryamaya-geodezicheskaya-zadacha-reshenie-na-ploskosti.html)  
- Обратная задача - https://terraingis.ru/obratnaya-geodezicheskaya-zadacha.html)  

Результаты округляются до 4-х знаков после запятой.

#### Интерфейс 
- **Левая панель** включает:
  - 2 кнопки для выбора задачи: `Прямой` или `Обратный`
  - Поля ввода координат точки A.  
  - Поля ввода координат точки B (*только для обратной задачи*).  
  - Поле ввода расстояния (*только для прямой задачи*).  
  - Поле ввода угла (*только для прямой задачи*).  
- **Правая панель** включает:  
  - Кнопка `Решить` для выполнения вычислений.  
  - Поле для вывода результата.  
  - Информационная надпись о округлении.  

#### Инструкция по использованию

##### Прямая геодезическая задача
1. Выберите кнопку `Прямой` в меню слева.  
2. Введите координаты начальной точки A.  
3. Введите расстояние от точки A до точки B.  
4. Введите угол в градусах, минутах и секундах:  
    Градусы: [0, 359], минуты и секунды [0, 59]  
5. Нажмите кнопку `Решить`.  

##### Обратная геодезическая задача
1. Выберите кнопку `Обратный` в меню слева.  
2. Введите координаты точки A и точки B.  
3. Нажмите кнопку `Решить`.  

#### Примечание
- Координаты и расстояния могут быть любыми числами в диапазоне от `-20000000` до `20000000` с точностью до 4-х знаков после запятой.  
- Угол для прямой задачи вводится в градусах, минутах и секундах. Для обратной задачи угол вычисляется автоматически и округляется до ближайших целых минут и секунд.

## Технические особенности
- Приложение выполнено на основе **Qt** и использует **C++** для реализации логики.  
- Разработано в среде **Qt Creator** версии 15.0.1 и **Qt 6.8.1** (MSVC 2022, x86_64).  
- Все вычисления выполняются с использованием библиотеки `<cmath>`.  
- Интерфейс автоматически адаптируется к выбранной операции, показывая только необходимые поля ввода.

## Скриншоты интерфейса

- **Главная страница**
  
  ![image](https://github.com/user-attachments/assets/064416a7-b6f0-4d50-be66-aaf06609b7ab)

- **Обычный калькулятор**
      *пример функции* `+`
  
  ![image](https://github.com/user-attachments/assets/659e5317-0524-4840-8b98-6bcd162af02b)

- **Геокалькулятор**
    - *Пример выбора* `Прямой` *задачи*
      
      ![image](https://github.com/user-attachments/assets/86b8a5a1-d9f6-4c68-8ca9-142146ba02c4)


    - *Пример выбора* `Обратной` *задачи*
      
      ![image](https://github.com/user-attachments/assets/79ab0c43-cbdb-48e1-aa3c-4c39d9972f46)



