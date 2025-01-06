#include"datatype.h"

// nguyen mau ham
void printMenu();
void printFunction();
void printCategory(Category category[],int n);
void addCategory(Category category[], int *n);
int checkName(Category category[],int n,char *name);
void fixCategory(Category category[],int n,int checkId);
void deleteCategory(Category category[], int *n);
void searchCategory(Category category[], int n);
void sortCategory(Category category[],int n);
void saveCategory(const char *filename, Category category[],int n);
int loadCategory(const char *filename, Category category[]);
void printProduct(Product product01[],int n);
void addProduct(Product product01[],int *n);
void fixProduct(Product product01[], int n);
void deleteProduct(Product product01[], int *n);
void searchProduct(Product product01[], int n);
void sortProduct(Product product01[], int n);
