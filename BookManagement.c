#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book{
    int bookId;
    char bookName[100];
	char authorName[100];
	char bookCategory[50];
	char bookLanguage[50];
    float bookPrice;
	float bookRating;	
}Book;

struct Book *books=NULL;
int bookCount=0;


void addBook();
void removeBook();
void searchBook();
void showAuthorsBooks();
void showbookCategoryBooks();
void updateBook();
void displayAllBooks();
void displaySortedBooks();

void main(){
    books=(struct Book*)malloc(3*sizeof(struct Book));
    if(!books){
        printf("Memory allocation failed!\n");
    
    }
    bookCount=3;

    books[0].bookId=101;
    strcpy(books[0].bookName,"Faster Fene");
    strcpy(books[0].authorName,"B.R.Bhagwat");
    strcpy(books[0].bookCategory,"Crime Thriller");
    strcpy(books[0].bookLanguage,"Marathi"); 
    books[0].bookPrice=399.99;
    books[0].bookRating=4.8;

    books[1].bookId=102;
    strcpy(books[1].bookName,"Rich Dad Poor Dad");
    strcpy(books[1].authorName,"Robert Kiyosaki");
    strcpy(books[1].bookCategory,"Finance");
    strcpy(books[1].bookLanguage,"English");
    books[1].bookPrice=299.99;
    books[1].bookRating=4.7;

    books[2].bookId=103;
    strcpy(books[2].bookName,"Meluha");
    strcpy(books[2].authorName,"Amish Tripathi");
    strcpy(books[2].bookCategory,"Mythology");
    strcpy(books[2].bookLanguage,"Hindi");
    books[2].bookPrice=499.99;
    books[2].bookRating=4.9;


    int choice;
    while(1){
        printf("\nBook Management System\n1. Add Book\n2. Remove Book\n3. Search Book\n4. Show Author's Books\n5. Show Category's Books\n6. Update Book\n7. Display All Books\n8. Display Sorted Books\n9. Exit\nEnter choice: ");
        scanf("%d",&choice);
        printf("\n--------------------\n");
        switch(choice){
            case 1:addBook();break;
            case 2:removeBook();break;
            case 3:searchBook();break;
            case 4:showAuthorsBooks();break;
            case 5:showbookCategoryBooks();break;
            case 6:updateBook();break;
            case 7:displayAllBooks();break;
            case 8:displaySortedBooks();break;
            case 9:free(books);
            default:printf("Invalid choice! Try again.\n");
        }
    }
}

void addBook(){
    books=realloc(books,(bookCount+1)*sizeof(struct Book));
    if(!books){
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter Book ID: ");
    scanf("%d",&books[bookCount].bookId);
    
    printf("Enter Book Name: ");
    scanf(" %[^\n]",books[bookCount].bookName);
    
    printf("Enter Author Name: ");
    scanf(" %[^\n]",books[bookCount].authorName);
    
    printf("Enter Book Category: ");
    scanf(" %[^\n]",books[bookCount].bookCategory);
    
    printf("Enter Book Language: ");
    scanf(" %[^\n]",books[bookCount].bookLanguage);
    
    printf("Enter Book Price: ");
    scanf("%f",&books[bookCount].bookPrice);
    
    printf("Enter Book Rating: ");
    scanf("%f",&books[bookCount].bookRating);
    bookCount++;
    printf("Book added successfully!\n");
}

void removeBook(){
    int id,found=0;
    printf("Enter Book ID to remove: ");
    scanf("%d",&id);
    for(int i=0;i<bookCount;i++){
        if(books[i].bookId==id){
            found=1;
            for(int j=i;j<bookCount-1;j++){
                books[j]=books[j+1];
            }
            bookCount--;
            books=realloc(books,bookCount*sizeof(struct Book));
            if(!books&&bookCount>0){
                printf("Memory reallocation failed!\n");
                return;
            }
            printf("Book removed successfully!\n");
            break;
        }
    }
    if(!found)printf("Book not found!\n");
}

void searchBook(){
    int id,found=0;
    char name[100];
    printf("Search by:\n1. Book ID\n2. Book Name\nEnter choice: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        printf("Enter Book ID: ");
        scanf("%d",&id);
        for(int i=0;i<bookCount;i++){
            if(books[i].bookId==id){
                printf("Book Found: %s by %s\n",books[i].bookName,books[i].authorName);
                found=1;
                break;
            }
        }
    }else{
        printf("Enter Book Name: ");
        scanf(" %[^\n]",name);
        for(int i=0;i<bookCount;i++){
            if(strcmp(books[i].bookName,name)==0){
                printf("Book Found: %s by %s\n",books[i].bookName,books[i].authorName);
                found=1;
                break;
            }
        }
    }
    if(!found)printf("Book not found!\n");
}

void showAuthorsBooks(){
    char author[100];
    int found=0;
    printf("Enter Author Name: ");
    scanf(" %[^\n]",author);
    for(int i=0;i<bookCount;i++){
        if(strcmp(books[i].authorName,author)==0){
            printf("- %s (ID: %d)\n",books[i].bookName,books[i].bookId);
            printf("--------------------\n");
            found=1;
        }
    }
    if(!found)printf("No books found by this author.\n");
}

void showbookCategoryBooks(){
    char bookCategory[50];
    int found=0;
    printf("Enter Book Category: ");
    scanf(" %[^\n]",bookCategory);
    for(int i=0;i<bookCount;i++){
        if(strcmp(books[i].bookCategory,bookCategory)==0){
            printf("- %s by %s (ID: %d)\n",books[i].bookName,books[i].authorName,books[i].bookId);
            found=1;
            printf("--------------------\n");
        }
    }
    if(!found)printf("No books found in this Book Category.\n");
}

void updateBook(){
    int id,found=0;
    printf("Enter Book ID to update: ");
    scanf("%d",&id);
    for(int i=0;i<bookCount;i++){
        if(books[i].bookId==id){
            printf("Enter new Book Price: ");
            scanf("%f",&books[i].bookPrice);
            printf("Enter new Book Rating: ");
            scanf("%f",&books[i].bookRating);
            printf("Book updated successfully!\n");
            found=1;
            break;
        }
    }
    if(!found)printf("Book not found!\n");
}

void displayAllBooks(){
    if(bookCount==0){
        printf("No books available.\n");
        return;
    }
    for(int i=0;i<bookCount;i++){
        printf("Book ID: %d.\nBook Name : %s\nBook Author: %s\nBook Category: %s\nBook Language : %s\nBook Price: Rs.%.f\nBook Rating: %.1f\n",
               books[i].bookId,books[i].bookName,books[i].authorName,books[i].bookCategory,books[i].bookLanguage,books[i].bookPrice,books[i].bookRating);
        printf("--------------------\n");
    }
}

void displaySortedBooks(){
    if(bookCount == 0){
        printf("No books available to sort!\n");
        return;
    }
    int choice;
    printf("\nSort by:\n1. Price (High to Low)\n2. Rating (High to Low)\nEnter choice: ");
    scanf("%d", &choice);

    struct Book temp;
    for(int i = 0; i < bookCount - 1; i++){
        for(int j = i + 1; j < bookCount; j++){
            if((choice == 1 && books[i].bookPrice < books[j].bookPrice) ||
               (choice == 2 && books[i].bookRating < books[j].bookRating)){
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }

    printf("\nBooks Sorted by %s (High to Low):\n", choice == 1 ? "Price" : "Rating");
    displayAllBooks();
}

