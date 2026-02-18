#include <stdio.h>

int main(){
    FILE* values_s1 = fopen("sensor1.txt", "r");
    FILE* values_s2 = fopen("sensor2.txt", "r");
    FILE* results = fopen("results.txt", "w");

    if (values_s1 == NULL || values_s2 == NULL || results == NULL) {
        printf("Fehler beim Oeffnen der Dateien!\n");
        return 1;
    }

    char line1[100]; // Puffer für Sensor 1
    char line2[100]; // Puffer für Sensor 2

    // fgets liest bis zum Zeilenumbruch \n oder bis der Puffer voll ist
    while (fgets(line1, sizeof(line1), values_s1) != NULL && 
           fgets(line2, sizeof(line2), values_s2) != NULL) 
    {
        
        // In die Ergebnisdatei schreiben
        // Da fgets das \n meist mitleast, hängen wir sie direkt an
        fprintf(results, "S1: %s", line1);
        fprintf(results, "S2: %s", line2);
    }

    // 3. Dateien schließen
    fclose(values_s1);
    fclose(values_s2);
    fclose(results);

    return 0;
}