#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../include/playlist.h"

/* === Unit-tests === */

// example unit test
void test_init_playlist(void)
{
    Playlist p;
    init_playlist(&p);

    assert(p.head == NULL);
    assert(p.size == 0);
}

void test_add_song(void)
{
    Playlist p;
    init_playlist(&p);
    add_song("EFN", "vrig ger", &p);

    assert(p.head != NULL);
    assert(p.head->next == NULL);
    assert(strcmp(p.head->artist, "vrig ger") == 0);
    assert(strcmp(p.head->title, "EFN") == 0);
    assert(p.size == 1);

    delete_playlist(&p);
}

void test_delete_firstSong(void)
{
    Playlist p;
    init_playlist(&p);
    add_song("First Song", "First Artist", &p);
    add_song("Second Song", "Second Artist", &p);
    delete_firstSong(&p, 0);

    assert(p.size == 1);
    assert(strcmp(p.head->artist, "Second Artist") == 0);
    assert(strcmp(p.head->title, "Second Song") == 0);
}

void test_delete_firstSong_empty(void)
{
    Playlist p;
    init_playlist(&p);
    delete_firstSong(&p, 1);

    assert(p.size == 0);
    assert(p.head == NULL);
}

void test_delete_playlist(void)
{
    Playlist p;
    init_playlist(&p);
    add_song("First Song", "First Artist", &p);
    add_song("Second Song", "Second Artist", &p);
    add_song("Third Song", "Third Artist", &p);
    delete_playlist(&p);

    assert(p.size == 0);
    assert(p.head == NULL);
}

void test_max_songs_limit(void)
{
    Playlist p;
    init_playlist(&p);    
    add_song("First Song", "First Artist", &p);
    add_song("Second Song", "Second Artist", &p);
    add_song("Third Song", "Third Artist", &p);
    add_song("Fourth Song", "Fourth Artist", &p); // Should not be added because limit is set at 3
    
    assert(p.size == 3);
    Song *temp = p.head;
    while(temp->next != NULL) // go to last song
    {
        temp = temp->next;
    }
    assert(temp != NULL);
    assert(strcmp(temp->title, "Third Song") == 0);

    delete_playlist(&p);
}
/* === Test-Runner === */

int main(void)
{
    test_init_playlist();
    test_add_song();
    test_delete_firstSong();
    test_delete_firstSong_empty(); // what happens if we delete first song from empty playlist
    test_delete_playlist();
    test_max_songs_limit(); // verify if the limit will be not be surpassed

    printf("Alle Playlist-Tests erfolgreich bestanden.\n");
    return 0;
}
