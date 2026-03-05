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

void test_add_song_index(void)
{
    Playlist p;
    init_playlist(&p);
    add_song_index("Tirol", "DJ Ötzi", 3, &p); //should not be added (invalid index)
    
    assert(p.size == 0);

    add_song("First Song", "First Artist", &p);
    add_song("Second Song", "Second Artist", &p);
    add_song("Third Song", "Third Artist", &p);
    add_song("Fourth Song", "Fourth Artist", &p);
    add_song_index("Tirol", "DJ Ötzi", 3, &p); // should be added between second and third song
    add_song_index("Tirol", "DJ Ötzi", 0, &p); //should not be added (invalid index)
    assert(p.size == 5);
    
    Song *temp = p.head;
    for(int i = 0; i < 2; i++) // go to index 3
    {
        temp = temp->next;
    }
    assert(temp != NULL);
    assert(strcmp(temp->title, "Tirol") == 0);
    
    temp = temp->next; // go to index 4
    assert(temp != NULL);
    assert(strcmp(temp->artist, "Third Artist") == 0);

    temp = temp->next; // go to index 5
    assert(temp != NULL);
    assert(strcmp(temp->title, "Fourth Song") == 0);

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
    delete_playlist(&p);
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

    for (int i = 0; i < MAX_SONGS; i++)
    {
        add_song("X", "Y", &p);
    }
    assert(p.size == MAX_SONGS);

    add_song("Overflow", "Error", &p);
    assert(p.size == MAX_SONGS); // should not be increased

    delete_playlist(&p);
}

void test_find_song_by_title(void)
{
    Playlist p;
    init_playlist(&p);
    add_song("First Song", "First Artist", &p);
    add_song("Second Song", "Second Artist", &p);
    add_song("Third Song", "Third Artist", &p);

    assert(find_song_by_title(&p, "Tirol") == NULL);

    Song *found = find_song_by_title(&p, "First Song");
    assert(found == p.head);
    assert(strcmp(found->title, "First Song") == 0);

    found = find_song_by_title(&p, "Third Song");
    assert(found == p.head->next->next);
    assert(strcmp(found->artist, "Third Artist") == 0);

    delete_playlist(&p);
}

void test_count_songs_recursive(void)
{
    Playlist p;
    init_playlist(&p);
    assert(count_songs_recursive(p.head) == 0);
    for (int i = 0; i < 69; i++)
    {
        add_song("Title", "Artist", &p);
    }

    assert(count_songs_recursive(p.head) == p.size);

    delete_playlist(&p);
}

void test_sort_playlist_by_title(void)
{
    Playlist p;
    init_playlist(&p);
    add_song("Bravoooooo", "Artist", &p);
    add_song("Donut", "Artist", &p);
    add_song("c", "Artist", &p);
    add_song("asjlfslakdjaskjfsa", "Artist", &p);
    sort_playlist_by_title(&p);

    assert(p.size == 4);
    assert(strcmp(p.head->title, "asjlfslakdjaskjfsa") == 0);
    assert(strcmp(p.head->next->title, "Bravoooooo") == 0);
    assert(strcmp(p.head->next->next->title, "c") == 0);
    assert(strcmp(p.head->next->next->next->title, "Donut") == 0);

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
    test_add_song_index();
    test_find_song_by_title();
    test_count_songs_recursive();
    test_sort_playlist_by_title();

    printf("Alle Playlist-Tests erfolgreich bestanden.\n");
    return 0;
}
