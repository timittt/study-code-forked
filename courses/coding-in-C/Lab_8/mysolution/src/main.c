#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/playlist.h"

void trim_newline(char *str) 
{
    str[strcspn(str, "\r\n")] = 0;
}

int main() 
{
    Playlist my_list;
    init_playlist(&my_list);

    int choice = 0;
    int target_index = 0;
    char title_buf[100];
    char artist_buf[100];

    printf("Welcome to the Lab 7 Playlist Manager!\n");

    while (1) {
        printf("\n--- Main Menu ---\n");
        printf("1. Add a song (End)\n");
        printf("2. Add a song at specific Index\n");
        printf("3. Delete first song\n");
        printf("4. Print playlist\n");
        printf("5. Exit and clear memory\n");
        printf("Your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            while (getchar() != '\n'); 
            continue;
        }
        while (getchar() != '\n'); 

        switch (choice) {
            case 1: // Am Ende hinzufügen
                printf("Enter title: ");
                fgets(title_buf, sizeof(title_buf), stdin);
                trim_newline(title_buf);
                printf("Enter artist: ");
                fgets(artist_buf, sizeof(artist_buf), stdin);
                trim_newline(artist_buf);

                add_song(title_buf, artist_buf, &my_list);
                break;

            case 2: // An Index hinzufügen
                printf("Enter index (1 to %d): ", my_list.size + 1);
                if (scanf("%d", &target_index) != 1) 
                {
                    printf("Invalid index format.\n");
                    while (getchar() != '\n');
                    break;
                }
                while (getchar() != '\n'); // Buffer leeren für fgets

                printf("Enter title: ");
                fgets(title_buf, sizeof(title_buf), stdin);
                trim_newline(title_buf);
                printf("Enter artist: ");
                fgets(artist_buf, sizeof(artist_buf), stdin);
                trim_newline(artist_buf);

                add_song_index(title_buf, artist_buf, target_index, &my_list);
                break;

            case 3:
                delete_firstSong(&my_list, 1);
                break;

            case 4:
                print_playlist(&my_list);
                break;

            case 5:
                delete_playlist(&my_list);
                printf("Memory cleared. Goodbye!\n");
                return 0;

            default:
                printf("Unknown option. Try again.\n");
        }
    }
    return 0;
}