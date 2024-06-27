# Тестовое задание C/C++ для вывода погоды через API www.weatherapi.com

## Использование

Установите libssl-dev и cmake с помощью команд:
```sh
$ sudo apt-get install curl
$ sudo apt-get install libssl-dev libcurl4-openssl-dev
$ sudo apt install cmake
```

Создайте исполняемый файл
```sh
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Вариант запуска #1
```sh
$ ./show-weather Tokyo
Weather in Tokyo: "Partly cloudy", 26.2°C
```

Вариант запуска #2
```sh
$ ./show-weather Tokyo Luxembourg
Weather in Tokyo: "Partly cloudy", 26.2°C
Weather in Luxembourg: "Partly cloudy", 26.0°C
```

Вариант запуска #3 (запускаем из любого места; PATH прописываем из build/)
```sh
$ export PATH=$PATH:$(pwd)
$ show-weather Tokyo
Weather in Tokyo: "Partly cloudy", 26.2°C
```

Дистрибутив
```sh
Ubuntu 22.04.2 LTS
```

## To do
Написать консольное (CLI) клиентское (HTTP) приложение, которое будет отображать 
данные по погоде в указанном городе(-ах) в “дружелюбном” для пользователя формате.
- [x] Язык программирования: C/C++.
- [x] Интерфейс для запуска приложения: # show-weather Tokyo
- [x] Cборка приложения должна осуществляться с помощью CMake и Make в Linux среде.
- [x] API для получения данных по погоде: https://www.weatherapi.com/
- [x] Разрешено использование любых сторонних библиотек для работы с HTTP и JSON.

