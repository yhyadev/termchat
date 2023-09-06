#include "vector.h"

#include <stdlib.h>

char_vector *init_char_vec() {
	char_vector *vec = malloc(sizeof(char_vector));

	vec->size = 0;
    vec->capacity = 10;
    
	vec->values = malloc(vec->capacity * sizeof(char));

	return vec;
}

void push(char_vector *vec, char value) {
    if (vec->size == vec->capacity) {
        vec->capacity *= 2;
        vec->values = realloc(vec->values, vec->capacity * sizeof(char));
    }

    vec->values[vec->size] = value;
    vec->size++;
}

void pop(char_vector *vec) {
	if (vec->size > 0) {
		vec->size--;
	}
}
