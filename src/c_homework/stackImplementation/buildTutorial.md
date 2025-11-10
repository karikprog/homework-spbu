# Здесь инструкции по сборке проекта

### Так как все ветки сливаются в одну было принято решение писать все инструкции в одном CMake файле. Так как во время запуска возникали конфликты кешов переменных SOURCES я решил создавать разные buld папки каждая под свою задачу.

## Команды для баланса скобок
```bash
cd src/c_homework/stackImplementation
cmake -S . -B buildBracked -DBUILD_BRACKED_BALANCE=ON
cmake --build buildBracked
```
## Команды для сортировочной станции
```bash
cd src/c_homework/stackImplementation
cmake -S . -B buildShunting -DBUILD_SHUNTING_YARD=ON
cmake --build buildShunting
```