#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/playlist.h"

int main()
{
    Playlist braunagelsListe;
    Playlist timsListe;
    init_playlist(&braunagelsListe);
    init_playlist(&timsListe);

    add_song("Crawling", "Linkin Park", &braunagelsListe);
    add_song("Layla", "Eric Clapton", &braunagelsListe);
    add_song("Esperanto", "Max Herre", &braunagelsListe);

    print_playlist(&braunagelsListe);

    delete_firstSong(&braunagelsListe, 1);

    print_playlist(&braunagelsListe);

    delete_playlist(&braunagelsListe);

    print_playlist(&braunagelsListe);

    add_song_index("EFN", "vrigger", 8, &timsListe);

    add_song_index("EFN", "vrigger", 1, &timsListe);
    add_song_index("Never Gonna Give You Up", "Rick Astley", 1, &timsListe);

    print_playlist(&timsListe);
    
    delete_playlist(&timsListe);
    return 0;
}