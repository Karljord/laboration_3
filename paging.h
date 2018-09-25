#define NUMBER_OF_CHAR 4
#define NUMBER_OF_FRAMES 4
#define NUMBER_OF_PAGES 7
#define LOWERCASE_ASCII_BOUND 97
#define LIMIT 28
#define USER_INPUT_SIZE 10
#define BUFFERSIZE 100
#define ASCII_DIFF 48
#define FP_OFFSET_THREE 3
#define FP_OFFSET_TWO 3
#define WHITE_SPACE_ASCII 32
#define DOT_ASCII 46
#define PAGE_MOD 4

typedef struct {
  char c[NUMBER_OF_CHAR];
  int counter;
}page;

typedef struct {
  page p;
}frame;
