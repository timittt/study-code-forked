#ifndef STRING_UTILS_H
#define STRING_UTILS_H

/**
 * @brief Gibt die Länge eines übergebenen Strings ohne \0 zurück
 * @param[in] string
 * @return length
 */
int custom_len(const char *string);

/**
 * @brief String einlesen und speichern
 * 
 * Liest String von der Tastatur ein, berechnet dessen Länge mit custom_len(),
 * allokiert dann mit malloc() einen passenden Speicher und kopiert dort den String hinein.
 * 
 * @return NULL bei Fehler
 */
char* read_line_dynamic();

#endif