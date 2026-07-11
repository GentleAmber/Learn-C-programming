/**
* Write a program that formats product information entered by the user. A session with the
* program should look like this:

* Enter item number: 583
* Enter unit price: 13.5
* Enter purchase date (mm/dd/yyyy): 10/24/2010
* Item  Unit    Purchase
*       Price   Date
* 583   $13.50  10/24/2010

* The item number and date should be left justified; the unit price should be right justified.
* Allow dollar amounts up to $9999.99. Hint: Use tabs to line up the columns.
 */

#include <stdio.h>
int main(void) {
  int num, month, day, year;
  float unit_price, sum_price;

  printf("Enter item number: ");
  scanf("%d", &num);
  printf("Enter unit price: ");
  scanf("%f", &unit_price);
  printf("Enter purchase date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &month, &day, &year);

  sum_price = unit_price * num;

  printf("Item\tUnit\tPurchase\n\tPrice\tDate\n");
  printf("%-4d\t$%8.2f\t%.2d/%.2d/%.4d", num, sum_price, month, day, year);

  return 0;
}