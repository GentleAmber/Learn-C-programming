# include <stdio.h>
# define PI 3.14159

int main(void) {
  float radius, volume;

  printf("Enter the radius: ");
  scanf("%f", &radius);
  volume = 4.0f / 3.0f * PI * radius * radius * radius;
  printf("Volume is: %.2f\n", volume);

  return 0;
}