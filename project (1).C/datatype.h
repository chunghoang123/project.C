#include<stdbool.h>
#include<string.h>
// cau truc
typedef struct Category{
	int id;
	char nameCategory[50];
}Category;
typedef struct Product{
	int id;
	int idCategory;
	char nameProduct[50];
	int quantity;
	int price;
}Product;
