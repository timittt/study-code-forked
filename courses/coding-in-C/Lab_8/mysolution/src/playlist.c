#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/playlist.h"


void init_playlist(Playlist *pl)
{
    pl->head = NULL;
    pl->size = 0;
}

int count_songs(Playlist *pl)
{
    unsigned int i = 0;
    Song *temp = pl->head;
    while (temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}

void add_song(char *song_title, char *song_artist, Playlist *pl)
{
    if(pl->size >= MAX_SONGS)
    {
        printf("Error: Playlist is full!\n");
        return;
    }
    Song *new_song = malloc(sizeof(Song));
    if ((new_song) == NULL) // no memory left
    {
        printf("Allocation error.\n");
        return;
    }

    new_song->title = strdup(song_title); // strdup == malloc + strcpy
    new_song->artist = strdup(song_artist);
    new_song->next = NULL;

    if (pl->head == NULL) // leere Playlist
    {
        pl->head = new_song;
    }
    else
    {
        Song *temp = pl->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_song;
    }
    pl->size = pl->size + 1; //count up
    printf("Song \"%s\" by %s added successfully\n", new_song->title, new_song->artist);
}

void add_song_index(char *song_title, char *song_artist, unsigned int index, Playlist *pl)
{
    if(index < 1)
    {
        printf("Error: invalid index\n");
        return;
    }
    if(pl->size >= MAX_SONGS)
    {
        printf("Error: Playlist is full!\n");
        return;
    }
    if (pl->size < index - 1)
    {
        printf("Error: Index %d not available (Playlist contains %d songs)\n", index, pl->size);
        return;
    }
    Song *new_song = malloc(sizeof(Song));
    if ((new_song) == NULL) // no memory left
    {
        printf("Error: Playlist is full\n");
        return;
    }
    new_song->title = strdup(song_title); // strdup == malloc + strcpy
    new_song->artist = strdup(song_artist);
    if(index == 1)  // direkt am Anfang einfügen
    {
        new_song->next = pl->head;
        pl->head = new_song;
    }
    else
    {
        Song *temp = pl->head;
        for(int i = 0; i < index - 2; i++) //Bis zum Element vor dem neuen Song gehen
        {
            temp = temp->next;
        }
        new_song->next = temp->next;
        temp->next = new_song;
    }
    pl->size = pl->size + 1; //count up
    printf("Song \"%s\" by %s added successfully on index %d.\n", new_song->title, new_song->artist, index);
}

void print_playlist(Playlist *pl)
{
    printf("-------------------\n");
    Song *temp = pl->head;
    unsigned int i = 1;
    if (temp == NULL)
    {
        printf("Error: Playlist is empty.\n-------------------\n");
        return;
    }
    else
    {
        printf("- Printing playlist -\n");
        while (temp != NULL)
        {
            printf("Song %d: %s - \"%s\"\n", i, temp->artist, temp->title);
            temp = temp->next;
            i++;
        }
        printf("-------------------\n");
    }
}

void delete_firstSong(Playlist *pl, unsigned short print_action)
{
    if (pl->head == NULL) // leere Playlist
    {
        if (print_action)
        {
            printf("Failed. Playlist is already empty.\n");
        }
        return;
    }
    else
    {
        Song *temp = pl->head;
        pl->head = pl->head->next; // zweiter Song oder NULL
        pl->size = pl->size - 1;
        if (print_action)
        {
            printf("Deleted first song \"%s\" by %s successfully\n", temp->title, temp->artist);
        }
        free(temp->title);
        free(temp->artist);
        free(temp);
    }
}

void delete_playlist(Playlist *pl)
{
    while (pl->head != NULL)
    {
        delete_firstSong(pl, 0); // 0 -> nicht jeden gelöschten Song ausgeben
    }
    pl->size = 0;
    printf("Playlist deleted successfully\n");
}

Song* find_song_by_title(Playlist *pl, const char *title)
{
    Song *temp = pl->head;

    if (temp == NULL)
    {
        return NULL;
    }
    else
    {
        while (temp != NULL)
        {
            if(strcmp(temp->title, title) == 0)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
}
