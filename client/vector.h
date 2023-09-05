typedef struct {
    char* values;
    int size;
    int capacity;
} char_vector;

char_vector *init_char_vec();
void push(char_vector *vec, char value);
void pop(char_vector *vec);
