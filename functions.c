#include<stdio.h>
#include"functions.h"
#include<string.h>
//logic ham
void printMenu(){
	printf("\n");
	printf("|-----------------------------| \n");
	printf("| ***___STORE MANAGEMENT___***| \n");
	printf("|-----------------------------| \n");
	printf("|1.Quan ly danh muc           | \n");
	printf("|-----------------------------| \n");
	printf("|2.Quan ly san pham           | \n");
	printf("|-----------------------------| \n");
	printf("|3.Thoat                      | \n");
	printf("|-----------------------------| \n");
}
void printFunction(){
	printf("\n");
	printf("***____Quan ly danh muc____***\n");
	printf("|=============================|\n");
	printf("|1.Hien thi danh muc          |\n");
    printf("|-----------------------------| \n");
	printf("|2.Them danh muc              | \n");
	printf("|-----------------------------| \n");
	printf("|3.Sua danh muc               | \n");
	printf("|-----------------------------| \n");
	printf("|4.Xoa danh muc               | \n");
	printf("|-----------------------------| \n");
	printf("|5.Tim kiem danh muc          | \n");
	printf("|-----------------------------| \n");
	printf("|6.Sap xep danh muc           | \n");
	printf("|-----------------------------| \n");
	printf("|7.Thoat                      | \n");
	printf("|=============================| \n");
}
// in danh muc
void printCategory(Category category[],int n){
	printf("____________________________ \n");
	printf("| ID|TEN                   |\n");
	printf("|---|----------------------| \n");
	int i;
	for(i=0;i<n;i++) {
		printf("|% -2d |%-21s |\n",category[i].id,category[i].nameCategory);
		printf("|---|----------------------| \n");
	}
}
// kiem tra ten trung hay ko
int checkName(Category category[],int n,char *name){
	int i;
	for(i=0;i<n;i++){
		if(strcmp(category[i].nameCategory,name)==0){
			// trung
			return 1;
		}
	}
	// khong
	return 0;
}
// them danh muc
void addCategory(Category category[], int *n) {
    if(*n>=50){
    	printf("Danh sach danh muc da day\n");
    	return;
	}
	int newId;
	printf("Moi nhap ID cho danh muc moi: ");
	scanf("%d",&newId);
	int i;
	for(i=0;i<*n;i++){
		if(category[i].id==newId){
			printf("ID %d da ton tai\n",newId);
			return;
		}
	}
	char newName[50];
	fflush(stdin);
	printf("Moi nhap ten cho danh muc moi: ");
	fgets(newName,50,stdin);
	newName[strcspn(newName,"\n")]='\0';
	if(checkName(category,*n,newName)){
		printf("Ten da ton tai\n");
		return;
	}
	category[*n].id=newId;
	strcpy(category[*n].nameCategory,newName);
	(*n)++;
	printf("Them thanh cong\n");
	printf("Danh muc da duoc them vao file \n");

}
//sua danh muc
void fixCategory(Category category[],int n,int checkId){
	fflush(stdin);
	printf("Moi ban chon id muon sua:");
	scanf("%d",&checkId);
	getchar();
	int check=-1;
	int i;
	for(i=0;i<n;i++){
		if(category[i].id==checkId) {
			check=i;
			break;
		}	
	}
	if(check==-1){
		printf("id khong hop le\n");
		return;
	}
	char newName[50];
	fflush(stdin);
	printf("Moi nhap ten cho danh muc muon sua:");
	fgets(newName,50,stdin);
	newName[strcspn(newName,"\n")]='\0';
	if(checkName(category,n,newName)){
		printf("ten da ton tai\n");
		return;
	}
	strcpy(category[check].nameCategory,newName);
	printf("sua thanh cong\n");
	printf("Danh muc da duoc them vao file \n");
}
// xoa danh muc
void deleteCategory(Category category[], int *n){
	fflush(stdin);
	int idDelete,found=0;
	printf("Moi ban chon id muon xoa:");
	scanf("%d",&idDelete);
	getchar();
	int i,j;
	for(i=0;i<*n;i++){
		if(category[i].id == idDelete) {
			found=1;
			for(j=i;j<*n-1;j++){
				category[j]=category[j+1];
			}
			(*n)--;	
			printf("xoa thanh cong\n");
			printf("Danh muc da duoc them vao file \n");
			break;
		}
	}
	if(!found){
		printf("ko tim thay ID");
	}
}
// tim kiem danh muc
void searchCategory(Category category[], int n){
	char keyword[50];
	int found=0;
	fflush(stdin);
	printf("nhap tu khoa de tim kiem danh muc; ");
	fgets(keyword,50,stdin);
	keyword[strcspn(keyword,"\n")]='\0';
	printf("ket qua tim kiem: \n");
	int i;
	for(i=0;i<n;i++){
		if(strstr(category[i].nameCategory,keyword)!=NULL){
			printf("| ID|TEN                   |\n");
			printf("|___|______________________|\n");
			printf("| %-2d| %-21s|\n", category[i].id, category[i].nameCategory);
            printf("|___|______________________|\n");
            found = 1;
		}
	}
	if (!found) {
        printf("Khong tim thay danh muc nao phu hop voi tu khoa '%s'.\n", keyword);
    }
}
// sap xep danh muc
void sortCategory(Category category[],int n){
	int a;
	system("cls");
	printf("[1]. sap xep A-Z\n");
	printf("[2]. sap xep Z-A\n");
	printf("moi chon: ");
	scanf("%d",&a);
	system("cls");
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if((a==1&&strcmp(category[i].nameCategory,category[j].nameCategory)>0)||(a==2&&strcmp(category[i].nameCategory,category[j].nameCategory)<0)){
				Category temp=category[i];
				category[i]=category[j];
				category[j]=temp;
			}
		}
	}
		printf("  ***______Danh muc____***\n");
		printCategory(category,n);
		printf("Danh muc da duoc them vao file \n");
}
// mo file
int loadCategory(const char *filename, Category category[]){
	FILE *file =fopen (filename,"rb");
	if(!file){
		printf("khong the mo file");
		return 0;
	}
	int n=0;
	while(fscanf(file,"%d %[^\n]",&category[n].id,category[n].nameCategory)==2){
		n++;
	}
	fclose(file);
	return n;
}
// luu file
void saveCategory(const char *filename, Category category[],int n){
	FILE *file =fopen (filename,"wb");
	if(!file){
		printf("khong the mo file");
		return;
	}
	int i;
	for(i=0;i<n;i++){
		fprintf(file, "%d %s\n", category[i].id, category[i].nameCategory); 
	}
	fclose(file);
}
void printProductMenu() {
    printf("\n");
    printf("***____Quan ly san pham____***\n");
    printf("|-----------------------------|\n");
    printf("|1. Hien thi san pham         |\n");
    printf("|-----------------------------|\n");
    printf("|2. Them san pham             |\n");
    printf("|-----------------------------|\n");
    printf("|3. Sua san pham              |\n");
    printf("|-----------------------------|\n");
    printf("|4. Xoa san pham              |\n");
    printf("|-----------------------------|\n");
    printf("|5. Tim kiem san pham         |\n");
    printf("|-----------------------------|\n");
    printf("|6. Sap xep san pham          |\n");
    printf("|-----------------------------|\n");
    printf("|7. Thoat                     |\n");
	printf("|-----------------------------|\n");
}
void printProduct(Product product01[], int n) {
    printf("|Product ID|Category ID| Name Product     | So luong | Gia tien   |\n");
    printf("|-----------------------------------------------------------------|\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("|%-10d| %-10d| %-10s       | %-5d    | %-6d VND |\n", product01[i].id,product01[i].idCategory ,product01[i].nameProduct, product01[i].quantity, product01[i].price);
        printf("|-----------------------------------------------------------------|\n");
    }
}
int checkProductName(Product product[], int n, char *name) {
	int i;
    for (i = 0; i < n; i++) {
        if (strcmp(product[i].nameProduct, name) == 0) {
            return 1;
        }
    }
    return 0;
}
void addProduct(Product product01[], int *n) {
    if (*n >= 50) {
        printf("Danh sach san pham da day\n");
        return;
    }
    int newId;
    printf("Moi nhap ID cho san pham moi: ");
    scanf("%d", &newId);
    int i;
    for ( i = 0; i < *n; i++) {
        if (product01[i].id == newId) {
            printf("ID %d da ton tai\n", newId);
            return;
        }
    }
    int newIdCategory; 
    printf("Moi bn nhap Id danh muc: ");
    scanf("%d",&newIdCategory);
    char newName[50];
    fflush(stdin);
    printf("Moi nhap ten cho san pham moi: ");
    fgets(newName, 50, stdin);
    newName[strcspn(newName, "\n")] = '\0';	
    if (checkProductName(product01, *n, newName)) {
        printf("Ten san pham da ton tai\n");
        return;
	}
    int quantity;
    int price;
    printf("Moi nhap so luong: ");
    scanf("%d", &quantity);
    printf("Moi nhap gia tien: ");
    scanf("%d", &price);
    product01[*n].id = newId;
    product01[*n].idCategory=newIdCategory;
    strcpy(product01[*n].nameProduct, newName);
    product01[*n].quantity = quantity;
    product01[*n].price = price;
    (*n)++;
    printf("Them san pham thanh cong\n");
}
void fixProduct(Product product01[], int n) {
    int checkId;
    printf("Moi nhap ID san pham muon sua: ");
    scanf("%d", &checkId);
    int index = -1;
    int i;
    for (i = 0; i < n; i++) {
        if (product01[i].id == checkId) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("ID khong hop le\n");
        return;
    }
    int newIdCategory;
	printf("Moi nhap ID danh muc muon sua: ");
    scanf("%d", &newIdCategory);
    char newName[50];
    fflush(stdin);
    printf("Moi nhap ten moi cho san pham: ");
    fgets(newName, 50, stdin);
    newName[strcspn(newName, "\n")] = '\0';
    if (checkProductName(product01, n, newName)) {
        printf("Ten san pham da ton tai\n");
        return;
    }
    int newQuantity, newPrice;
    printf("Moi nhap so luong moi: ");
    scanf("%d", &newQuantity);
    printf("Moi nhap gia tien moi: ");
    scanf("%d", &newPrice);
    product01[index].idCategory = newIdCategory;
    strcpy(product01[index].nameProduct, newName);
    product01[index].quantity = newQuantity;
    product01[index].price = newPrice;
    printf("Sua san pham thanh cong\n");
}
void deleteProduct(Product product01[], int *n) {
    int idDelete;
    printf("Moi nhap ID san pham muon xoa: ");
    scanf("%d", &idDelete);
    int index = -1;
    int i;
    for (i = 0; i < *n; i++) {
        if (product01[i].id == idDelete) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Khong tim thay san pham\n");
        return;
    }
    for (i = index; i < *n - 1; i++) {
        product01[i] = product01[i + 1];
    }
    (*n)--;

    printf("Xoa san pham thanh cong\n");
}
void searchProduct(Product product01[], int n) {
    char keyword[50];
    fflush(stdin);
    printf("Nhap tu khoa de tim kiem san pham: ");
    fgets(keyword, 50, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';
    printf("Ket qua tim kiem:\n");
    int found = 0;
    int i;
	for (i = 0; i < n; i++) {
        if (strstr(product01[i].nameProduct, keyword) != NULL) {
            printf("|Product ID|Category ID| Name Product     | So luong | Gia tien   |\n");
			printf("| %-8d |%-10d | %-16s | %8d | %7d VND|\n", product01[i].id,product01[i].idCategory, product01[i].nameProduct, product01[i].quantity, product01[i].price);
            printf("|-----------------------------------------------------------------|\n");
			found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay san pham nao\n");
    }
}
void sortProduct(Product product01[], int n) {
    int choice;
    printf("[1] Sap xep giam dan\n");
    printf("[2] Sap xep tang dan\n");
    printf("Moi ban chon: ");
    scanf("%d", &choice);
    int i,j;
	for ( i = 0; i < n - 1; i++) {
        for ( j = i + 1; j < n; j++) {
            if ((choice == 1 && product01[i].idCategory>product01[j].idCategory) ||
                (choice == 2 && product01[i].idCategory<product01[j].idCategory)) {
                Product temp = product01[i];
                product01[i] = product01[j];
                product01[j] = temp;
            }
        }
    }
    printf("Sap xep thanh cong\n");
    printProduct(product01, n);
}


