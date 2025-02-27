#include <stdio.h>
#include <stdlib.h>
#include"functions.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Category category[50];
	Product product01[50]={
	{1,2,"banh mi",12,12000},
	{2,2,"ngo",12,12000},
	};
	int choice,location;
	int count=-1;
	const char *filename="category.dat";
	int n= loadCategory(filename , category);
	int productCount=2; 
	do{
		system("cls");
		printMenu();
		printf("Moi nhap lua chon: ");
		scanf("%d",&choice);
		switch(choice){
			// quan ly danh muc
			case 1:{
				system("cls");
				do{
					system("cls");
					printFunction();
					printf("Moi nhap lua chon: ");
					scanf("%d",&choice);
					switch(choice){
						// hien thi danh muc
						case 1:{
							system("cls");
							printf("  ***______Danh muc____***\n");
							printCategory(category,n);
							printf("Go Back(b): ");
							getchar();
							getchar();
							break;
						}
						// them danh muc
						case 2:{
							system("cls");
							printCategory(category,n);
							addCategory(category , &n);
							saveCategory(filename,category,n);
							printf("Go Back(b): ");
							getchar();
							getchar();
							break;
						}
						// sua danh muc
						case 3:{
							system("cls");
							printf("  ***______Danh muc____***\n");
							printCategory(category,n);
							fixCategory(category,n,location);
							saveCategory(filename,category,n);
							printf("Go Back(b): ");
							getchar();
							getchar();
							break;
						}
						//xoa danh muc
						case 4:{
							system("cls");
							printf("  ***______Danh muc____***\n");
							printCategory(category,n);
							deleteCategory(category,&n);
							saveCategory(filename,category,n);
							printf("Go Back(b): ");
							getchar();
							getchar();
							break;
						}
						// tim kiem danh muc
						case 5:{
							system("cls");
							searchCategory(category,n);
							printf("Go Back(b): ");
							getchar();
							getchar();
							break;
						}
						//sap xep danh muc
						case 6:{
							system("cls");
							sortCategory(category,n);
							printf("Go Back(b): ");
							getchar();
							getchar();
							break;
						}
						// thoat chuong trinh
						case 7:{
							system("cls");
							printf("Thoat chuong trinh");
							break;
						default:
							printf("Moi chon lai: \n");
						}
					}
				}while(choice!=7);
				break;
			}
			//quan ly san pham
			case 2:{
				system("cls");
				do{
				system("cls");
				printProductMenu();
				printf("moi nhap lua chon: ");
				scanf("%d",&choice);
				switch(choice){
					case 1:{
						system("cls");
		                printProduct(product01, productCount);
		                printf("Go Back(b): ");
		                getchar();
		                getchar();
						break;
					}	            			           
		            case 2:{
		            	system("cls");
		            	printf("  ***______San Pham____***\n");
						printProduct(product01, productCount);
		                addProduct(product01, &productCount);
		                printf("Go Back(b): ");
		                getchar();
		                getchar();
						break;
					}
		            case 3:{
		            	system("cls");
		            	printf("  ***______San Pham____***\n");
						printProduct(product01, productCount);
		                fixProduct(product01, productCount);
		                printf("Go Back(b): ");
		                getchar();
		                getchar();
		                break;
					}
		            case 4:{
		            	system("cls");
		            	printf("  ***______San Pham____***\n");
						printProduct(product01, productCount);
		                deleteProduct(product01, &productCount);
		                printf("Go Back(b): ");
		                getchar();
		                getchar();
		                break;
					}
		            case 5:{
		            	system("cls");
		                searchProduct(product01, productCount);
		                printf("Go Back(b): ");
		                getchar();
		                getchar();
		                break;
					}		                
		            case 6:{
		            	system("cls");
		                sortProduct(product01, productCount);
		                printf("Go Back(b): ");
		                getchar();
		                getchar();
		                break;
					}
		            case 7:{
		            	printf("Thoat chuong trinh\n");
		                break;
					}
		       	}
				}while(choice!=7);	
				break;
			}	
			case 3:{
				printf("thoat chuong trinh");
							break;
						default:
							printf("moi chon lai \n");
				break;
			}
		}
	}while(choice!=3);
	return 0;
}
