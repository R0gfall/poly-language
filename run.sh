#!/bin/bash

# Компиляция Bison
bison -d -y gram.y
if [ $? -ne 0 ]; then
    echo "Ошибка в gram.y"
    exit 1
fi

# Компиляция Flex
flex lexparser.l
if [ $? -ne 0 ]; then
    echo "Ошибка в lexparser.l"
    exit 1
fi

# Сборка проекта
gcc lex.yy.c y.tab.c main.c -o parser -lm
if [ $? -ne 0 ]; then
    echo "Ошибка компиляции"
    exit 1
fi

# Запуск парсера
echo "Парсер запущен:"
./parser
