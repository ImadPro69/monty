#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMITER " "

/* Function to count the number of words in a string */
int count_words(const char *str) {
    int count = 0;
    int in_word = 0;
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            if (!in_word) {
                in_word = 1;
                count++;
            }
        } else {
            in_word = 0;
        }
    }
    
    return count;
}

/* Function to split a string into words */
char** strtow(const char *str) {
    if (str == NULL || *str == '\0')
        return NULL;
    
    int num_words = count_words(str);
    if (num_words == 0)
        return NULL;
    
    char **words = malloc((num_words + 1) * sizeof(char *));
    if (words == NULL)
        return NULL;
    
    int word_index = 0;
    const char *delim = DELIMITER;
    char *copy = strdup(str);
    
    char *token = strtok(copy, delim);
    while (token != NULL) {
        words[word_index++] = strdup(token);
        token = strtok(NULL, delim);
    }
    words[word_index] = NULL;
    
    free(copy);
    return words;
}

/* Function to free the memory allocated by strtow */
void free_words(char **words) {
    if (words == NULL)
        return;
    
    int i = 0;
    while (words[i] != NULL) {
        free(words[i]);
        i++;
    }
    
    free(words);
}

