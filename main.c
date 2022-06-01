#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "General.h"
#include "Supermarket.h"
#include "SuperFile.h"

int menu();


const char* menuStrings[eNofOptions] = { "Show SuperMarket", "Add Product",
								"Add Customer", "Customer Shopping",
								"Print Product By Type","Sort Products", "Search Product" };

int main(int argc, char* argv[])
{
	int IncryptedFlag = 0;


	SuperMarket	market;
	if (argc == 1)//NO ARGS
	{
		if (!initSuperMarket(&market, SUPER_FILE_NAME, CUSTOMER_FILE_NAME, IncryptedFlag))
		{
			printf("error init Super Market");
			return 0;
		}
	}
	else if (argc == 3)
	{
		sscanf(argv[1], "%d", &IncryptedFlag);
		printf("%d\n", IncryptedFlag);

		if (!initSuperMarket(&market, argv[2], CUSTOMER_FILE_NAME, IncryptedFlag))
		{
			printf("error init  Super Market");
			return 0;
		}
	}
	else
	{
		printf("invalid Args");
		return 0;
	}
	int option;
	int stop = 0;

	do
	{
		option = menu();
		switch (option)
		{
		case eShowSuperMarket:
			printSuperMarket(&market);
			break;


		case eAddProduct:
			if (!addProduct(&market))
				printf("Error adding product\n");
			break;

		case eAddCustomer:
			if (!addCustomer(&market))
				printf("Error adding customer\n");
			break;

		case eCustomerDoShopping:
			doShopping(&market);
			break;

		case ePrintProductByType:
			printProductByType(&market);
			break;

		case eSortProduct:
			sortProducts(&market);
			break;

		case eSearchProduct:
			findProduct(&market);
			break;

		case EXIT:
			printSentence("Thank", "You", "For", "Shopping", "At", "Daniel's", "Shop.", NULL);
			stop = 1;
			break;

		default:
			printf("Wrong option\n");
			break;
		}
	} while (!stop);

	if (IncryptedFlag)
	{
		if (!saveSuperMarketToFile(&market, argv[2], CUSTOMER_FILE_NAME, IncryptedFlag))
			printf("Error saving supermarket to file\n");
	}
	else
		if (!saveSuperMarketToFile(&market, SUPER_FILE_NAME, CUSTOMER_FILE_NAME, IncryptedFlag))
			printf("Error saving supermarket to file\n");
	freeMarket(&market);
	system("pause");
	return 1;
}

int menu()
{
	int option;
	printf("\n\n");
	printf("Please choose one of the following options\n");
	for (int i = 0; i < eNofOptions; i++)
		printf("%d - %s\n", i, menuStrings[i]);
	printf("%d - Quit\n", EXIT);
	scanf("%d", &option);
	//clean buffer
	char tav;
	scanf("%c", &tav);
	return option;
}

