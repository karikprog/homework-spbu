# Для компиляции используйте команды

### Задание сортировочный список:
``` bash
gcc -Wall  linkedList.c sortingList.c -o program
```
# Запуск:
```bash
./program 
```
## Запуск тестов через cmake:
``` bash
cmake . -B build
cmake --build build
cd build
ctest
```