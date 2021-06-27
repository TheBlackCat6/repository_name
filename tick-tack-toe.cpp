#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>


enum cell {CROSS = 'X', ZERO = 'O', EMPTY = '_'};

struct coord 
{
    size_t y;
    size_t x;
};

enum progress
{
    IN_PROGRESS,
    WON_HUMAN,
    WON_AI,
    DRAW
};

#pragma pack(push, 1)
struct field
{
    cell** ppfield = nullptr;
    const size_t size = 3;
    cell human = EMPTY;
    cell ai = EMPTY;
    size_t turn = 0;
    progress progress = IN_PROGRESS;
};
#pragma pack (pop)

int32_t getRandomNum(int32_t min, int32_t max)
{
    const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937_64 generator(seed);
    std::uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}

void init_field(field& r)
{
    r.ppfield = new cell * [r.size];
    for (size_t i = 0; i < r.size; i++)
        r.ppfield[i] = new cell[r.size];

    for (size_t y = 0; y < r.size; y++)
        for (size_t x = 0; x < r.size; x++)
            r.ppfield[y][x] = EMPTY;

    if (getRandomNum(0, 1000) > 500)
    {
        r.human = CROSS;
        r.ai = ZERO;
        r.turn = 0;
    }
    else
    {
        r.human = ZERO;
        r.ai = CROSS;
        r.turn = 1;
    }
}

void deinit_field(field& r)
{
    for (size_t i = 0; i < r.size; i++)
        delete [] r.ppfield[i];
    delete [] r.ppfield;
    r.ppfield = nullptr;
}

void print_field(const field& r)
{
    std::cout << "    ";
    for (size_t x = 0; x < r.size; x++)
        std::cout << " " << x + 1 << "  ";
    std::cout << std::endl;
    for (size_t y = 0; y < r.size; y++)
    {
        std::cout << " " << y+1 << " | ";
        for (size_t x = 0; x < r.size; x++)
            std::cout << static_cast <char> (r.ppfield[y][x]) << " | ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Player: " << static_cast <char> (r.human) << std::endl;
    std::cout << "   CPU: " << static_cast <char> (r.ai) << std::endl;
}

void inline clear_screen()
{
    system("cls");
}

coord getHumanCoord(field & f)
{
    coord c;
    do
    {
        std::cout << " Enter x: ";
        std::cin >> c.x;

        std::cout << " Enter y: ";
        std::cin >> c.y;
        if (f.ppfield[c.y - 1][c.x - 1] != EMPTY)
        {
            std::cerr << "This cell is busy!" << std::endl;
        }
    }     while (c.x == 0 || c.y == 0 || c.x > 3 || c.y > 3 || f.ppfield[c.y-1][c.x-1] != EMPTY);

    c.x--;
    c.y--;
    
    return c;
}

coord getAiCoord(field& f)
{
    if (f.ppfield[1][1] == EMPTY)
    {
        return { 1,1 };
    }

    coord arr[4] = { 0 };
    size_t num = 0;
    if (f.ppfield[0][0] == EMPTY)
    {
        arr[num++] = { 0,0 };
    }

    if (f.ppfield[2][2] == EMPTY)
    {
        arr[num++] = { 2,2 };
    }

    if (f.ppfield[0][2] == EMPTY)
    {
        arr[num++] = { 0,2 };
    }

    if (f.ppfield[2][0] == EMPTY)
    {
        arr[num++] = { 2,0 };
    }

    if (num > 0)
    {
        const size_t index = getRandomNum(0, 1000) % num;
        return arr[index];
    }

    num = 0;
    if (f.ppfield[0][1] == EMPTY)
    {
        arr[num++] = { 0,1 };
    }

    if (f.ppfield[2][1] == EMPTY)
    {
        arr[num++] = { 2,1 };
    }

    if (f.ppfield[1][0] == EMPTY)
    {
        arr[num++] = { 1,0 };
    }

    if (f.ppfield[1][2] == EMPTY)
    {
        arr[num++] = { 1,2 };
    }

    if (num > 0)
    {
        const size_t index = getRandomNum(0, 1000) % num;
        return arr[index];
    }
    return { 0,0 };
}

        

progress getWon(field& f)
{

    for (size_t y = 0; y < f.size; y++)
    {
        if (f.ppfield[y][0] == f.ppfield[y][1] && f.ppfield[y][0] == f.ppfield[y][2])
        {
            if (f.ppfield[y][0] == f.ai)
            {
                return WON_AI;
            }
            else if (f.ppfield[y][0] == f.human)
            {
                return WON_HUMAN;
            }
        }
    }

    for (size_t x = 0; x < f.size; x++)
    {
        if (f.ppfield[0][x] == f.ppfield[1][x] && f.ppfield[0][x] == f.ppfield[2][x])
        {
            if (f.ppfield[0][x] == f.ai)
            {
                return WON_AI;
            }
            else if (f.ppfield[0][x] == f.human)
            {
                return WON_HUMAN;
            }
        }
    }

    if (f.ppfield[0][0] == f.ppfield[1][1] && f.ppfield[0][0] == f.ppfield[2][2])
    {
        if (f.ppfield[0][0] == f.ai)
        {
            return WON_AI;
        }
        else if (f.ppfield[0][0] == f.human)
        {
            return WON_HUMAN;
        }
    }

    if (f.ppfield[2][0] == f.ppfield[1][1] && f.ppfield[1][1] == f.ppfield[0][2])
    {
        if (f.ppfield[1][1] == f.ai)
        {
            return WON_AI;
        }
        else if (f.ppfield[1][1] == f.human)
        {
            return WON_HUMAN;
        }
    }

    bool draw = true;
    for (size_t y = 0; y < f.size; y++)
    {
        for (size_t x = 0; x < f.size; x++)
        {
            if (f.ppfield[y][x] == EMPTY)
            {
                draw = false;
                break;
            }
        }
        if (!draw)
        {
            break;
        }
    }

    if (draw)
    {
        return DRAW;
    }
    return IN_PROGRESS;
}



void congrats(progress progress)
{
    if (progress == WON_HUMAN)
    {
        std::cout << " Player won! =)" << std::endl;
    }
    else if (progress == WON_AI)
    {
        std::cout << " CPU won! =(" << std::endl;
    }
    else if (progress == DRAW)
    {
        std::cout << "Draw! =/" << std::endl;
    }
}

int main()
{
    field f;
    init_field(f);

    clear_screen();
    print_field(f);

    do
    {
        if (f.turn % 2 == 0)
        {
            coord c = getHumanCoord(f);
            f.ppfield[c.y][c.x] = f.human;
        }
        else if (f.turn % 2 == 1)
        {
            coord c = getAiCoord(f);
            f.ppfield[c.y][c.x] = f.ai;
        }

        f.turn++;

        clear_screen();
        print_field(f);

        f.progress = getWon(f);
    } while (f.progress == IN_PROGRESS);

    congrats(f.progress);

    deinit_field(f);
    return 0;
}