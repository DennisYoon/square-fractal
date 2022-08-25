#include <stdio.h>

int board[6561][6561];

int draw(int left_up_x, int left_up_y, int size) {
  if (size == 1) {
    board[left_up_x][left_up_y] = 1;
    return 0;
  }
  int size3 = size / 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 1 && j == 1) {
        continue;
      }
      draw(left_up_x + size3 * i, left_up_y + size3 * j, size3);
    }
  }
  return 0;
}

int main(void) {
  int init_size;
  scanf("%d", &init_size);
  if (init_size == 1 || init_size == 3 || init_size == 9 || init_size == 27|| init_size == 81) {
    draw(0, 0, init_size);
    for (int i = 0; i < init_size; i++) {
      for (int j = 0; j < init_size; j++) {
        if (board[i][j] == 0) {
          printf("  ");
        } else {
          printf("* ");
        }
      }
      printf("\n");
    }
  } else {
    printf("81이하의 삼의 거듭제곱만 사용 가능");
  }
  return 0;
}