

// Lab 3
// DVGB01 Operativsystem
// Karlstad Universitet HT18
// Laborant: Leo Jordansson
// Medlaborant: Johan Pedersen

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "paging.h"
#include "pagehandler.h"

/*-----------------------------------------------------*/

void runprogram(long *fp_counter);
int  readfile(long*fp_counter);
void fill_virtual_mem(page virtual_mem[]);
int  menu();
void print_menu();

/*-----------------------------------------------------*/

void runprogram(long *fp_counter){
  int program_input;
  program_input = readfile(fp_counter);

}

int  readfile(long*fp_counter){

  FILE *fp;
  int value;
  int test;

  fp = fopen("program1.txt", "r");
  fseek(fp, *fp_counter , SEEK_SET);
  if(!fp) {
    perror("\n\tError\n");
    exit(-1);
  }
  else {test = fscanf(fp, "%d", &value);}
  fclose(fp);
  if(test != 1) {
    return -1;
  }
  else if(value > 9) {
    *fp_counter = *fp_counter + FP_OFFSET_THREE;
  }
  else{
    *fp_counter = *fp_counter + FP_OFFSET_TWO;
  }

  return value;
}

void fill_virtual_mem(page virtual_mem[]){

  int i;

  for(i = 0; i < LIMIT - 2; i++) {
    virtual_mem[i/PAGE_MOD].c[i%PAGE_MOD] = i + LOWERCASE_ASCII_BOUND;
  }
    virtual_mem[i/PAGE_MOD].c[(i)%PAGE_MOD] = WHITE_SPACE_ASCII;
    i++;
    virtual_mem[i/PAGE_MOD].c[(i)%PAGE_MOD] = DOT_ASCII;
}

int  menu(long *fp_counter) {

  char user_input[BUFFERSIZE];
  int return_value = 1;
  int temp;

  printf("\t");
  scanf("%s", user_input);
  fflush(0);

  temp = user_input[0] - ASCII_DIFF;

  switch (temp) {
    case 1:
      runprogram(fp_counter);                                              break;
    case 2:
      /*letter free of choice*/                                            break;
    case 3:
      printf("\n\tPrinting sidetable and primary memory\n");               break;
    case 4:
      /*Exit Program*/
      return_value = 0;                                                    break;
    default:
      printf("\n\tInvalid input, please enter a number between 1 - 4\n");  break;

  }

  return return_value;

}

void print_menu(){

  printf("\n\t1: Exekvera Program1\n");
  printf("\t2: Exekvara valfri bokstav\n");
  printf("\t3: Skriv ut sidtabell och primärminne\n");
  printf("\t4: Avsluta\n\n");

}

int  main(int argc, char* argv[]) {

  long fp_counter = 0;
  int flag = 1;
  int test;

  page virtual_mem[NUMBER_OF_PAGES];
  frame primary_mem[NUMBER_OF_FRAMES];
  pagetable page_table[NUMBER_OF_PAGES];

  fill_virtual_mem(virtual_mem);

  do {
    print_menu();
    flag = menu(&fp_counter);
  } while(flag);


  printf("\n\tExiting . . .");
  sleep(1);


  return 0;
}
