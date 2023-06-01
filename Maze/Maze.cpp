#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

// светлые цвета
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
// темные цвета
#define COLOR__RED     "\x1b[91m"
#define COLOR__GREEN   "\x1b[92m"
#define COLOR__YELLOW  "\x1b[93m"
#define COLOR__BLUE    "\x1b[94m"
#define COLOR__MAGENTA "\x1b[95m"
#define COLOR__CYAN    "\x1b[96m"
//откат цвета
#define COLOR_RESET   "\x1b[0m"
//отчистка консоли
#define cls system("cls");

//функция для отката курсора в начальное положения, дабы исправить мерцание всего масиива
void clear(int x, int y)//установка курсора на позицию  x y
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void CursoreVisable(bool a)
{
    CONSOLE_CURSOR_INFO curs = { 0 };
    curs.dwSize = sizeof(curs);
    curs.bVisible = a;
    ::SetConsoleCursorInfo(::GetStdHandle(STD_OUTPUT_HANDLE), &curs);
}

int main()
{
start:
    CursoreVisable(FALSE);
    clear(0, 0);
    setlocale(0, "");
    bool door = false;
    int user_stepI = 1;
    int user_stepJ = 1;
    int map[15][15] =
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,0,1,0,1,3,3,3,1,1,1,3,0,1},
        {1,1,3,1,0,1,1,1,1,0,6,1,3,0,1},
        {1,1,3,0,0,0,0,7,1,0,0,1,3,0,1},
        {1,1,3,1,1,1,3,1,3,0,0,1,1,0,1},
        {1,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
        {5,0,3,1,0,1,1,1,0,3,1,1,1,0,1},
        {3,0,3,1,0,0,0,0,0,0,0,3,1,3,1},
        {1,0,0,1,1,1,1,0,3,1,0,0,1,3,1},
        {1,3,0,1,3,3,1,3,0,0,0,0,1,3,1},
        {1,0,0,1,3,3,1,1,4,1,1,1,1,1,1},
        {1,0,3,0,0,0,0,3,0,3,3,3,3,3,1},
        {1,0,0,0,3,3,0,0,0,3,3,3,3,3,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
    while (true)
    {
        cout << COLOR_CYAN << "\t\t\t\t\t\t\t   Лабиринт" << COLOR_RESET << "\n\n";
        for (int i = 0; i < 15; i++)
        {
            cout << "\t\t\t\t\t\t";
            for (int j = 0; j < 15; j++)
            {
                if (map[i][j] == 2)
                {
                    cout << COLOR_GREEN << (char)4 << COLOR_RESET << ' ';
                }
                else if (map[i][j] == 1)
                {
                    cout << COLOR__CYAN << '#' << COLOR_RESET << ' ';
                }
                else if (map[i][j] == 3)
                {
                    cout << COLOR__RED << '^' << COLOR_RESET << ' ';
                }
                else if (map[i][j] == 4)
                {
                    cout << COLOR_YELLOW << '_' << COLOR_RESET << ' ';
                }
                else if (map[i][j] == 5)
                {
                    cout << COLOR__GREEN << '|' << COLOR_RESET << ' ';
                }
                else if (map[i][j] == 6)
                {
                    cout << COLOR_YELLOW << (char)23 << COLOR_RESET << ' ';
                }
                else if (map[i][j] == 7)
                {
                    cout << COLOR_YELLOW << (char)23 << COLOR_RESET << ' ';
                }
                else if (map[i][j] == 0)
                {
                    cout << "  ";
                }
                else if (door = true)
                {
                    map[12][9] = 3;
                }
            }
            cout << "\n";
        }
        int key = _getch();
        switch (key)
        {
            //W
        case 87:
        case 119:
        case 230:
        case 72:
            if (map[user_stepI - 1][user_stepJ] != 1 && map[user_stepI - 1][user_stepJ] != 3 && map[user_stepI - 1][user_stepJ] != 6)
            {
                map[user_stepI][user_stepJ] = 0;
                map[--user_stepI][user_stepJ] = 2;
            }
            else if (map[user_stepI - 1][user_stepJ] == 3)
            {
                cls;
                cout << COLOR_RED << "\t\t\t\t\t\t\t\    ПОМЕР " << COLOR_RESET << endl;
                Sleep(2000);
                cls;
                goto start;
            }
            else if (map[user_stepI - 1][user_stepJ] == 6)
            {
                map[user_stepI][user_stepJ] = 0;
                map[--user_stepI][user_stepJ] = 2;
                door = true;
                cout << COLOR_CYAN << "\t\t\t\t\t\t\t\ Вы взяли ключ " << COLOR_RESET << endl;
                Sleep(500);
                cls;

            }
            break;
            //A
        case 97:
        case 65:
        case 228:
        case 75:
            if (map[user_stepI][user_stepJ - 1] != 1 && map[user_stepI][user_stepJ - 1] != 3 && map[user_stepI][user_stepJ - 1] != 5)
            {
                map[user_stepI][user_stepJ] = 0;
                map[user_stepI][--user_stepJ] = 2;
            }
            else if (map[user_stepI][user_stepJ - 1] == 3)
            {
                cls;
                cout << COLOR_RED << "\t\t\t\t\t\t\t\    ПОМЕР " << COLOR_RESET << endl;
                Sleep(2000);
                cls;
                goto start;
            }
            else if ((map[user_stepI][user_stepJ - 1] == 5))
            {
                cls;
                cout << COLOR_GREEN << "\t\t\t\t\t\t\t\ Вы победили!!! " << COLOR_RESET << endl;
                Sleep(5000);
                cls;
                goto start;
            }
            break;
            //S
        case 83:
        case 115:
        case 235:
        case 80:
            if (map[user_stepI + 1][user_stepJ] != 1 && map[user_stepI + 1][user_stepJ] != 3 && map[user_stepI + 1][user_stepJ] != 4)
            {
                map[user_stepI][user_stepJ] = 0;
                map[++user_stepI][user_stepJ] = 2;
            }
            else if (map[user_stepI + 1][user_stepJ] == 3)
            {
                cls;
                cout << COLOR_RED << "\t\t\t\t\t\t\t\    ПОМЕР " << COLOR_RESET << endl;
                Sleep(2000);
                cls;
                goto start;
            }
            else if (map[user_stepI + 1][user_stepJ] == 4 && door == false)
            {
                cout << COLOR_YELLOW << "\t\t\t\t\t\t         Дверь " << COLOR_RED << "ЗАПЕРТА!" << COLOR_RESET << endl;
                Sleep(500);
                cls;
            }
            else if (map[user_stepI + 1][user_stepJ] == 4 && door == true)
            {
                map[user_stepI][user_stepJ] = 0;
                map[++user_stepI][user_stepJ] = 2;
            }
            break;
            //D
        case 100:
        case 68:
        case 162:
        case 77:
            if (map[user_stepI][user_stepJ + 1] != 1 && map[user_stepI][user_stepJ + 1] != 3 && map[user_stepI][user_stepJ + 1] != 6 && map[user_stepI][user_stepJ + 1] != 7)
            {
                map[user_stepI][user_stepJ] = 0;
                map[user_stepI][++user_stepJ] = 2;
            }
            else if (map[user_stepI][user_stepJ + 1] == 3)
            {
                cls;
                cout << COLOR_RED << "\t\t\t\t\t\t\t\    ПОМЕР " << COLOR_RESET << endl;
                Sleep(2000);
                cls;
                goto start;
            }
            else if (map[user_stepI][user_stepJ + 1] == 6)
            {
                map[user_stepI][user_stepJ] = 0;
                map[user_stepI][++user_stepJ] = 2;
                door = true;
                cout << COLOR_CYAN << "\t\t\t\t\t\t\t\ Вы взяли ключ " << COLOR_RESET << endl;
                Sleep(500);
                cls;

            }
            else if (map[user_stepI][user_stepJ + 1] == 7)
            {
                map[user_stepI][user_stepJ] = 0;
                map[user_stepI][++user_stepJ] = 2;
                cout << COLOR__RED << "\t\t\t\t\t\t\      Что-то произошло... " << COLOR_RESET << endl;
                Sleep(900);
                map[2][4] = 3;
                cls;
            }
            break;
        case 27:
            goto exit;
            break;
        case 32:
            goto start;
            break;
        }
        clear(0, 0);
    }
exit:
    cout << COLOR_CYAN << "\n\n\t\t\t\t\t\t |!**Выход из программы**!| " << COLOR_RESET;
    Sleep(1000);
    cls;
    return 0;
}
