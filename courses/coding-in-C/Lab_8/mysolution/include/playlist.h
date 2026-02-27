#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_SONGS 2

typedef struct Song
{
    char *title;
    char *artist;
    struct Song *next;
} Song;

typedef struct Playlist
{
    struct Song *head;
    unsigned int size;
} Playlist;

void init_playlist(Playlist *pl);

int count_songs(Playlist *pl);

void add_song(char *song_title, char *song_artist, Playlist *pl);

void add_song_index(char *song_title, char *song_artist, unsigned int index, Playlist *pl);

void print_playlist(Playlist *pl);

void delete_firstSong(Playlist *pl, unsigned short print_action);

void delete_playlist(Playlist *pl);

#endif