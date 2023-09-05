#include "vector.h"

#include <stdlib.h>

char_vector *init_char_vec() {
	char_vector *vec = malloc(sizeof(char_vector));

	vec->values = malloc(sizeof(char));
	vec->size = 0;
	vec->capacity = 1;

	return vec;
}

void push(char_vector *vec, char value) {
    vec->values = realloc(vec->values, vec->capacity * sizeof(char));
    vec->capacity *= 2;
    vec->values[vec->size] = value;
    vec->size++;
}

void pop(char_vector *vec) {
    vec->size--;
    vec->capacity /= 2;
    vec->values = realloc(vec->values, vec->capacity * sizeof(char));
}
