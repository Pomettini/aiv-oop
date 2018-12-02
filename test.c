#include "aiv-oop.h"
#include <stdio.h>

void test_virtual_method()
{
    printf("Hello\n");
}

void test_event(void *ret)
{
    printf("%d\n", (int)ret);
}

void player_on_death()
{
    printf("I died\n");
}

typedef struct player
{
    int x;
    int y;
    VMETHOD(on_death);
} player;

int main(int argc, char **argv)
{
    VMETHOD(virtual_method) = test_virtual_method;
    virtual_method();

    EVENT(aiv_event) = test_event;
    aiv_event(ARG(10));

    player *test_player = NEW(player);
    test_player->x = 20;
    test_player->on_death = player_on_death;

    printf("%d\n", test_player->x);
    test_player->on_death();

    DELETE(test_player);
}
