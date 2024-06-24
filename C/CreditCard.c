#include <stdio.h>
#define MAX_ITEMS 10
int main()
{
	struct Item {
		int sku;
		float price;
		int quantity;
	};
	struct Item item[MAX_ITEMS];
	int sku2,sku3, quantity2;
	float price2;
	int choice;
	int size = 0;
	int l = 1;
	int i;
	int found = 0;
	printf("Welcome to the Shop\n");
	printf("===================\n");
	while (l) {
		printf("Please select from the following options:\n");
		do {
			printf("1) Display the inventory.\n");
			printf("2) Add to shop.\n");
			printf("3) Price check.\n");
			printf("0) Exit.\n");
			printf("Select:");
			scanf("%d", &choice);
			if (choice < 0 || choice > 3)
			{
				printf("Invalid input, try again: Please select from the following options:\n");
			}
		} while (choice < 0 || choice > 3);
		if (choice == 0)
		{
			printf("Good bye!\n");
			l = 0;
		}
		if (choice == 2) {
			printf("Please input a SKU number:");
			scanf("%d", &sku2);
			printf("Quantity:");
			scanf("%d", &quantity2);
			for (i = 0; i < size; i++)
			{
				if (sku2 == item[i].sku)
				{
					item[i].quantity = item[i].quantity + quantity2;
					found = 1;
					printf("The item exists in the repository, quanity is updated.\n");
				}

			}
			if (sku2 != item[size].sku)
			{
				if (size != MAX_ITEMS && found == 0)
				{
					printf("Price:");
					scanf("%f", &price2);
					item[size].sku = sku2;
					item[size].price = price2;
					item[size].quantity = quantity2;
					size = size + 1;
					printf("The item is successfully added to the inventory.\n");
				}
				else if (size == MAX_ITEMS)
				{
					printf("It is full\n");
				}
			}
		}
		if (choice == 3)
		{
			printf("Please input the sku number of the item:\n");
			scanf("%d", &sku3);
			for (i = 0; i < size; i++)
			{
				if (sku3 == item[i].sku)
				{
					printf("Item %d costs $%.2f\n", item[i].sku, item[i].price);
					break;
				}
				else if(sku3 != item[i].sku)
					printf("Item does not exist in the shop! Please try again.\n");
				break;
			}
		}


		if (choice == 1)
		{
			printf("\n\nInventory\n");
			printf("=========================================\n");
			printf("Sku         Price       Quanity\n");
			for (i = 0; i < size; i++)
			{
				printf("%d        %.2f       %d         \n", item[i].sku, item[i].price, item[i].quantity);

			}
			printf("=========================================\n");
		}
	}
	return 0;
}
