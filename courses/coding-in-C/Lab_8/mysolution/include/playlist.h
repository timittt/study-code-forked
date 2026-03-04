#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_SONGS 100

/**
 * @struct Song
 * @brief Represents a single element in the playlist.
 */
typedef struct Song {
    char *title;     
    char *artist; 
    struct Song *next;  /**< Pointer to the next song in the playlist */
} Song;

/**
 * @struct Playlist
 * @brief Container for the playlist management.
 */
typedef struct {
    Song *head;         /**< Pointer to the first song */
    unsigned int size; 
} Playlist;

void init_playlist(Playlist *pl);

/**
 * @brief Counts the number of songs currently in the playlist.
 * @param pl Pointer to the playlist.
 * @return The number of songs as an unsigned integer.
 */
int count_songs(Playlist *pl);

/**
 * @brief Adds a new song to the end of the playlist.
 * @param song_title String containing the song title.
 * @param song_artist String containing the artist's name.
 * @param pl Pointer to the playlist.
 */
void add_song(char *song_title, char *song_artist, Playlist *pl);

/**
 * @brief Inserts a song at a specific index.
 * @note Index starts at 1.
 * @param song_title String containing the song title.
 * @param song_artist String containing the artist's name.
 * @param index Position where the song should be inserted (1 = head).
 * @param pl Pointer to the playlist.
 */
void add_song_index(char *song_title, char *song_artist, unsigned int index, Playlist *pl);

/**
 * @brief Prints all songs in the playlist to the console.
 * @param pl Pointer to the playlist.
 */
void print_playlist(Playlist *pl);

/**
 * @brief Removes the first song from the playlist and frees its memory.
 * @param pl Pointer to the playlist.
 * @param print_action If non-zero, a success message is printed to stdout.
 */
void delete_firstSong(Playlist *pl, unsigned short print_action);

/**
 * @brief Clears the entire playlist and frees all allocated memory.
 * @param pl Pointer to the playlist.
 */
void delete_playlist(Playlist *pl);

/**
 * @brief Looks for a song with given title
 * @param pl Pointer to the playlist
 * @param title String which is searched
 */
Song* find_song_by_title(Playlist *pl, const char *title);
    
#endif