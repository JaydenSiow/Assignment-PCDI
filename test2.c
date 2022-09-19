//Includes the functions needed for our program
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#pragma warning(disable:4996)

//Price of each book
const double BOOK_PRICE[16] = { 69.00, 70.00, 55.50, 75.00, 58.00, 65.00, 89.00, 79.00, 73.50, 80.00, 50.00, 75.00, 69.00, 99.00, 88.50, 109.00 };

//Global variable
int total[16], salesOrder = 0, un;
double ttlDis;
char nextOrder;

//User defined functions
void logoHeading(), summary(), order(), menu(), field1(), field2(), field3(), field4(), exitP();
int fieldSelect();
char next();

//the main function
void main()
{
    int option;
    //Calls the logoHeading function to display the logoHeading
    logoHeading();

    //Get the user's option
    do
    {
        printf("\n\nSelect an option (1 = View Menu, 2= Sales Order, 3 = Exit) :  ");
        scanf("%d", &option);
        rewind(stdin);

        switch (option)
        {
        case 1://View the menu
            menu();
            break;
        case 2: //Make an order
            order();
            break;
        case 3://Exit the program
            exitP();
            break;
        default:
            printf("\nPlease enter a valid number.");
        }
    } while (option != 2 && option != 3);
}

void logoHeading()
{
    printf("                 //     \n");
    printf("   /            //     \\\n");
    printf("  /            //       \\\n");
    printf(" /            //         \\\n");
    printf("/            //           \\\n");
    printf("\\           //            /\n");
    printf(" \\         //            /\n");
    printf("  \\       //            /\n");
    printf("   \\     //            /\n");
    printf("        //             \n");
    printf("\nUMT POS SYSTEM");
}

void exitP()
{
    printf("\nXXXXXXXXXXXXXXXXXXXXX\n");
    printf("Exiting the program...\n");

    system("pause");
}

void menu()
{
    int field;
    //Display all the books from the field chosen from the user
    do
    {
        field = fieldSelect();
        switch (field)
        {
        case 1:
            field1();
            break;
        case 2:
            field2();
            break;
        case 3:
            field3();
            break;
        case 4:
            field4();
            break;
        default:
            printf("Please enter a valid input\n");
        }
    } while (field < 1 || field > 4);
}

int fieldSelect()
{
    int selection;
    printf("\nSelect a field to view:\n");
    printf("1 = Software Development Programming\n");
    printf("2 = Web Programming\n");
    printf("3 = Mobile Programming\n");
    printf("4 = Mathematics for Programming\n");
    printf("Input: ");
    scanf("%d", &selection);
    rewind(stdin);

    return selection;

}

void field1()
{
    printf("\nSoftware Development Programming Books :\n");
    printf("A = Beginning with Programming Logic and Design RM69.00\n");
    printf("B = C Programming RM70.00\n");
    printf("C = Programming Fundamentals RM55.50\n");
    printf("D = C++ Programming RM75.00\n");
}

void field2()
{
    printf("\nWeb Programming :\n ");
    printf("E = HTML and CSS Design RM58.00\n");
    printf("F = Web Programing RM65.00\n");
    printf("G = ASP .NET Programming RM89.00\n");
    printf("H = Javascript Programming RM79.00\n");
}

void field3()
{
    printf("\nMobile Programming :\n ");
    printf("I = Mobile Design and Programming RM73.50\n");
    printf("J = Building Mobile App RM80.00\n");
    printf("K = Android Programming RM50.00\n");
    printf("L = Objective C Programming RM75.00\n");
}

void field4()
{
    printf("\nMathematics for Programming: \n");
    printf("M = Discrete Mathematics RM69.00\n");
    printf("N = Linear Algebra RM99.00\n");
    printf("O = Algebra and Trigonometry RM88.50\n");
    printf("P = Calculus RM109.00\n\n");
}

void order()
{
    //Constants
    const double DIS_RATE_FIRST = 0.05, DIS_RATE_SECOND = 0.10, DIS_RATE_THIRD = 0.15;
    //Variables
    char book = '\0', confirm = '\0';
    int qty = 0;
    double disAmt = 0, subtotal = 0, totalPay = 0, disRate = 0;
    //Arrays for storing the users input during their order
    int bookQty[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    double bookPay[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    do
    {
        //Sales order
        printf("\nSales order No: %d", ++salesOrder);
        //Loops back here if the customer chooses to make another order
        do
        {
            //Ordering
            do
            {
                printf("\nBook A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P (X = Exit) : ");
                scanf(" %c", &book);
                rewind(stdin);
                book = toupper(book);
                un = (int)book - 65;//Using the ASCII value of each character we can find out which book the user inputs and store the data in the respected location of their respected array
                if (un >= 0 && un <= 15)//if book A,B,C,...,P is selected
                {
                    // The number of books the user wants to order
                    do
                    {   
                        printf("Quantity : ");
                        rewind(stdin);
                        scanf("%d", &qty);
                        rewind(stdin);
                        if (qty <= 0)
                            printf("Error : Invalid value\n");
                    } while (qty <= 0);
                    //Transfer data to the books's respected location in the array based on the book chosen
                    bookQty[un] += qty;
                    total[un] += qty;
                    bookPay[un] = bookQty[un] * BOOK_PRICE[un];
                    qty = 0;    //reset the number for qty variable
                }
                else if (book != 'X')
                    printf("\nPlease enter a valid character\n");
            } while (book != 'X');
            //Confirm order
            do
            {
                if (book == 'X')
                {
                    printf("\nConfirm the order? (Y = Yes, N = No , C = Cancel Order) : ");
                    scanf("%c", &confirm);
                    rewind(stdin);
                    confirm = toupper(confirm);
                    printf("\n");
                    //If the order is confirmed then the receipt is automatically displayed
                    if (confirm == 'Y')
                    {
                        for (un = 0; un < 16; un++)
                        {
                            if (bookQty[un] > 0)
                            {
                                printf("Book %c: %d @ RM%6.2lf = RM%10.2lf\n", 65 + un, bookQty[un], BOOK_PRICE[un], bookPay[un]);//Displays the books and quantity of books inputted from the user
                                subtotal += bookPay[un];//The subtotal from the order is summed up 
                            }
                        }
                        if (subtotal >= 500)  //The given discount based on the subtotal 
                            disRate = DIS_RATE_THIRD;
                        else if (subtotal >= 300 && subtotal < 500)
                            disRate = DIS_RATE_SECOND;
                        else if (subtotal >= 200 && subtotal < 300)
                            disRate = DIS_RATE_FIRST;
                        else
                            disRate = 0;

                        disAmt = subtotal * disRate;
                        totalPay = subtotal - disAmt;
                        ttlDis += disAmt;

                        printf("%36s", "============\n");
                        printf("%-20s = RM%10.2lf\n", "Subtotal", subtotal);
                        printf("%-20s = RM%10.2lf\n", "Discounts", disAmt);
                        printf("%36s", "============\n");
                        printf("%-20s = RM%10.2lf\n", "Total to Pay", totalPay);
                        printf("\nTHANK YOU, HAVE A NICE DAY!!\n");
                    }
                    //if the user cancels the order then the data accumulated from the order is cleared
                    else if (confirm == 'C')
                    {
                        salesOrder -= 1;
                        for (un = 0; un < 16; un++)
                        {
                            total[un] -= bookQty[un];
                        }
                    }
                    //If the user doesn't enter a valid character
                    else if (confirm != 'N')
                        printf("\nPlease enter a valid character.");
                }
            } while (!(confirm == 'Y' || confirm == 'C' || confirm == 'N'));
        } while (confirm == 'N');
        //If confirm = Y or confirm = C, the user is asked if he wants to go to the next order 
        nextOrder = next();//calls the next function that asks the user if he/she wants to go to the next order
        if (nextOrder == 'Y')
        {
            //clear data
            book = '\0';
            confirm = '\0';
            qty = 0;
            disAmt = 0;
            subtotal = 0;
            totalPay = 0;
            disRate = 0;
            //clear array
            for (un = 0; un < 16; un++)
            {
                bookQty[un] = 0;
                bookPay[un] = 0;
            }
        }
        else//If the user chooses not to go to the next order the days sales order summary report is displayed
            summary();
    } while (nextOrder == 'Y');//The user starts a new order
}

char next()
{
    do
    {
        //the user is asked if he wants to go to the next order
        printf("\nNext order? (Y = Yes, N = No) : ");
        scanf("%c", &nextOrder);
        rewind(stdin);
        nextOrder = toupper(nextOrder);
        if (nextOrder != 'Y' && nextOrder != 'N')
            printf("\nPlease enter a valid character.");
    } while (nextOrder != 'Y' && nextOrder != 'N');

    return nextOrder;
}

void summary() {
    //Variables
    double amt[16];//The total earnings for each book
    int totalBooks = 0;
    double totalAmt = 0;

    printf("\n%s", "DAILY SALES ORDER SUMMARY REPORT");
    printf("\n\nTotal Number of Sales Order = %d\n", salesOrder);
    printf("%-6s %20s %11s\n", "Book", "Quantity Sold Sales", "Amount");

    //calculation of the money earned for each book , sum of the total books sold for all orders, sum of the total amount of money earned for all books from all orders
    for (un = 0; un < 16; un++)
    {
        //calculate the money earned from each seperate book
        amt[un] = BOOK_PRICE[un] * total[un];
        //sum of the total number of books sold from all orders
        totalBooks += total[un];
        //sum of the total amount of money earned from all orders
        totalAmt += amt[un];
        //display the total number of books sold from all orders and the total amount of money earned from all orders
        printf("%c %14d %15s %7.2lf\n", 65 + un, total[un], "RM", amt[un]);
    }

    printf("%-6s %19s %13s\n", "======", "===================", "==========");
    //Display the total amount of books sold and cash accumulated from each order
    printf("%-6s %9d %15s %7.2lf\n", "TOTAL:", totalBooks, "RM", totalAmt);

    //Display the total discount given for all orders
    printf("\n%s RM%.2lf\n", "TOTAL DISCOUNT GIVEN: ", ttlDis);

    //The end of the program
    exitP();
}