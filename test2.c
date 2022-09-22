//Includes the functions needed for our program
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#pragma warning(disable:4996)

//Price for each book
const double BOOK_PRICE[16] = { 69.00, 70.00, 55.50, 75.00, 58.00, 65.00, 89.00, 79.00, 73.50, 80.00, 50.00, 75.00, 69.00, 99.00, 88.50, 109.00 };

//Global variables
int total[16], salesOrder = 0, un;
double ttlDis;
char inputTest[51];

//User defined functions
void logoHeading(), summary(), order(), menu(), field1(), field2(), field3(), field4(), exitP();
char next(), nameTest(), confirmTest(), nextTest();
int fieldSelect(), quantityTest(), fieldTest(), mainTest();

//The main function
void main()
{
    int option;
    char nextOption;
    //Calls the logoHeading function to display the logoHeading
    logoHeading();

    //Get the user's option
    do
    {
        option = mainTest();//Calls the main test function and assigns the return value of the main test function to the option variable
        printf("\n");
        switch (option)
        {
        case 1://View the menu
            menu();
            break;
        case 2: //Make an order
            do {
                order();//Calls the order function for the customer to make his/her order
                nextOption = next();//Calls the next function and stores the return value into the variable nextOption
                if (nextOption == 'N')
                    summary();//If the user chooses not to go to the next order the days sales order summary report is displayed
            } while (nextOption == 'Y');//If the user chooses to go to the next sales order the the loop will continue
            break;
        case 3://The user will exit the program
            exitP();//Calls the exit program function 
            break;
        default:
            printf("Please enter a choice that has been given.\n");
        }
    } while (option != 2 && option != 3);
}

void logoHeading()
{
    printf("%78s\n", "**********************************************************");
    printf("%77s\n", "*                                                        *");
    printf("%76s\n", "*       ==    ==     ==          ==      ========        *");
    printf("%75s\n", "*       ==    ==     ===        ===      ========        *");
    printf("%74s\n", "*       ==    ==     ====      ====         ==           *");
    printf("%73s\n", "*       ==    ==     == ==    == ==         ==           *");
    printf("%72s\n", "*        ==  ==      ==  ==  ==  ==         ==           *");
    printf("%71s\n", "*          ==        ==   ====   ==         ==           *");
    printf("%70s\n", "*                                                        *");
    printf("%69s\n", "**********************************************************");
    printf("%45s\n", "==============");
    printf("%45s\n", "UMT POS SYSTEM");
    printf("%45s\n", "==============");
}

char nameTest()//Input validation for book selection 
{
    char testName;
    do {
        inputTest[0] = '\0';
        printf("Which book would you like to purchase?(A/B/C/D/E/F/G/H/I/J/K/L/M/N/O/P) (X = Exit) : ");
        scanf("%c%[^\n]", &testName, inputTest);//The %[^\n] reads if there is any other input after the alphabet
        rewind(stdin);

        if (inputTest[0] != '\0') //This validation will ensure the user will only be able to enter one alphabet only , input such as A1, B2, BB will be read as invalid input as it consists of more than one alphabet
            printf("\nPlease re-enter the book you wish to purchase or enter X to exit your order.\n");
    } while (inputTest[0] != '\0');//Loops if the user doesn't input the correct format
    return testName;
}

char confirmTest()
{
    char testConfirm;
    do {
        inputTest[0] = '\0';
        printf("\nConfirm the order? (Y = Yes, N = No , C = Cancel Order) : ");//This validation will ensure the user will only be able to enter one alphabet only , input such as A1, B2, BB will be read as invalid input as it consists of more than one alphabet
        scanf("%c%[^\n]", &testConfirm, inputTest);//The %[^\n] reads if there is any other input after the alphabet
        rewind(stdin);

        if (inputTest[0] != '\0')
            printf("\n**Invalid Input**\nPlease enter a choice that has been given.\n");
    } while (inputTest[0] != '\0');
    return testConfirm;
}

char nextTest()
{
    char testNext;
    do {
        inputTest[0] = '\0';
        printf("\nNext order? (Y = Yes, N = No) : ");
        scanf("%c%[^\n]", &testNext, inputTest);//This validation works the same as the function above
        rewind(stdin);
        printf("\n");
        if (inputTest[0] != '\0')
            printf("\n**Invalid Input**\nPlease enter a choice that has been given.\n");
    } while (inputTest[0] != '\0');
    return testNext;
}

int fieldTest()
{
    char testField;
    int testFieldInt;
    do {
        inputTest[0] = '\0';
        printf("\nWhich field would you like to view? : ");
        scanf("%c%[^\n]", &testField, inputTest);//This function also works the same as the three functions above
        rewind(stdin);

        if (inputTest[0] != '\0')
            printf("\n**Invalid Input**\nPlease enter a choice that has been given.\n");
    } while (inputTest[0] != '\0');
    testFieldInt = (int)testField - 48;

    return testFieldInt;
}

int mainTest()
{
    char testMain;
    int testMainInt;
    do {
        inputTest[0] = '\0';
        printf("\nWhat is your option? (1 = View Menu, 2= Sales Order, 3 = Exit) : ");
        scanf("%c%[^\n]", &testMain, inputTest);//This function checks if the user enters more than one number in his input
        rewind(stdin);

        if (inputTest[0] != '\0')
            printf("\n**Invalid Input**\nPlease enter a choice that has been given.\n");
    } while (inputTest[0] != '\0');
    testMainInt = (int)testMain - 48;//Using the ASCII value of a number we can find out which number is inputted by the user 
                                     //Example : The ASCII value of the number 1 is 49 , minus 48 and we will get 1
    return testMainInt;
}

int quantityTest()
{
    char testQuantity;
    int testQuantityInt;
    do {
        inputTest[0] = '\0';
        printf("\nQuantity (1~9): ");
        scanf("%c%[^\n]", &testQuantity, inputTest);
        printf("\n");
        rewind(stdin);

        if (inputTest[0] != '\0' || isdigit(testQuantity) == 0) // This function tests if the quantity entered is a digit
            printf("**Invalid Input**\nPlease re-enter the quantity.\n");//If not it will be read as invalid input
    } while (inputTest[0] != '\0' || isdigit(testQuantity) == 0);
    testQuantityInt = (int)testQuantity - 48;//Using the ASCII value of a number we can find out the quantity inputted by the user 
                                             //Example : The ASCII value of the number 1 is 49 , minus 48 and we will get 1
    return testQuantityInt;
}

void exitP()
{
    printf("\n\n");
    printf("%78s\n", "*******************************************************************");
    printf("%78s\n", "*******************************************************************");
    printf("%78s\n", "**                                                               **");
    printf("%78s\n", "**                                                               **");
    printf("%78s\n", "**    EEEEEEEEEEE     XXX       XXX    IIIIIIIII    TTTTTTTTT    **");
    printf("%78s\n", "**    EEEEEEEEEEE      XXX     XXX     IIIIIIIII    TTTTTTTTT    **");
    printf("%78s\n", "**    EEE               XXX   XXX         III          TTT       **");
    printf("%78s\n", "**    EEE                XXX XXX          III          TTT       **");
    printf("%78s\n", "**    EEEEEEEEEEE         XXXXX           III          TTT       **");
    printf("%78s\n", "**    EEEEEEEEEEE         XXXXX           III          TTT       **");
    printf("%78s\n", "**    EEE                XXX XXX          III          TTT       **");
    printf("%78s\n", "**    EEE               XXX   XXX         III          TTT       **");
    printf("%78s\n", "**    EEEEEEEEEEE      XXX     XXX     IIIIIIIII       TTT       **");
    printf("%78s\n", "**    EEEEEEEEEEE     XXX       XXX    IIIIIIIII       TTT       **");
    printf("%78s\n", "**                                                               **");
    printf("%78s\n", "**                                                               **");
    printf("%78s\n", "*******************************************************************");
    printf("%78s\n", "*******************************************************************");

    system("pause");
}

void menu()
{
    int field;
    //Displays all the books from the field chosen by the user
    do
    {
        field = fieldSelect();//Calls the fieldselect function which prompts the user to enter his field selection and returns the value to the field variable
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
            printf("\nPlease enter a choice that has been given.\n\n");
        }
    } while (field < 1 || field>4);
}

int fieldSelect()//Displays the field selection menu and returns the selection
{
    char selection;

    printf("+=======================================+\n");
    printf("|Select a field to view:                |\n");
    printf("+===+===================================+\n");
    printf("| 1 | Software Development Programming  |\n");
    printf("| 2 | Web Programming                   |\n");
    printf("| 3 | Mobile Programming                |\n");
    printf("| 4 | Mathematics for Programming       |\n");
    printf("+===+===================================+\n");
    selection = fieldTest();

    return selection;
}

void field1()//The first field
{
    printf("\n+===============================================================+\n");
    printf("|Software Development Programming Books :                       |\n");
    printf("+======+==============================================+=========+\n");
    printf("%-54s|  %s  |\n", "| Book |", "Price");
    printf("+======+==============================================+=========+\n");
    printf("%-54s|RM%7s|\n", "|   A  | Beginning with Programming Logic and Design", "69.00");
    printf("%-54s|RM%7s|\n", "|   B  | C Programming", "70.00");
    printf("%-54s|RM%7s|\n", "|   C  | Programming Fundamentals", "55.50");
    printf("%-54s|RM%7s|\n", "|   D  | C++ Programming", "75.00");
    printf("+======+==============================================+=========+\n");
}

void field2()//Second field
{
    printf("\n+===============================================================+\n");
    printf("|Web Programming :                                              |\n");
    printf("+======+==============================================+=========+\n");
    printf("%-54s|  %s  |\n", "| Book |", "Price");
    printf("+======+==============================================+=========+\n");
    printf("%-54s|RM%7s|\n", "|   E  | HTML and CSS Design", "58.00");
    printf("%-54s|RM%7s|\n", "|   F  | Web Programing", "65.00");
    printf("%-54s|RM%7s|\n", "|   G  | ASP .NET Programming", "89.00");
    printf("%-54s|RM%7s|\n", "|   H  | Javascript Programming", "79.00");
    printf("+======+==============================================+=========+\n");
}

void field3()//Third field
{
    printf("\n+===============================================================+\n");
    printf("|Mobile Programming :                                           |\n");
    printf("+======+==============================================+=========+\n");
    printf("%-54s|  %s  |\n", "| Book |", "Price");
    printf("+======+==============================================+=========+\n");
    printf("%-54s|RM%7s|\n", "|   I  | Mobile Design and Programming", "73.50");
    printf("%-54s|RM%7s|\n", "|   J  | Building Mobile App", "80.00");
    printf("%-54s|RM%7s|\n", "|   K  | Android Programming", "50.00");
    printf("%-54s|RM%7s|\n", "|   L  | Objective C Programming", "75.00");
    printf("+======+==============================================+=========+\n");
}

void field4()//Fourth Field
{
    printf("\n+===============================================================+\n");
    printf("|Mathematics for Programming:                                   |\n");
    printf("+======+==============================================+=========+\n");
    printf("%-54s|  %s  |\n", "| Book |", "Price");
    printf("+======+==============================================+=========+\n");
    printf("%-54s|RM%7s|\n", "|   M  | Discrete Mathematics", "69.00");
    printf("%-54s|RM%7s|\n", "|   N  | Linear Algebra", "80.00");
    printf("%-54s|RM%7s|\n", "|   O  | Algebra and Trigonometry", "50.00");
    printf("%-54s|RM%7s|\n", "|   P  | Calculus", "109.00");
    printf("+======+==============================================+=========+\n");
}

void order()//Make an order
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

    logoHeading();

    //Sales order number
    printf("\n%45s %d\n", "Sales order No:", ++salesOrder);
    printf("%48s\n\n", "-------------------");
    //Loops back here if the customer chooses to make another order
    do
    {
        //Ordering
        do
        {
            book = nameTest();
            book = toupper(book);
            un = (int)book - 65;//Using the ASCII value of each character we can find out which book the user inputs and store the data in the respected location of their respected array
            if (un >= 0 && un <= 15)//If book A,B,C,...,P is selected
            {
                // The number of books the user wants to order
                do
                {
                    qty = quantityTest();
                    if (qty <= 0)
                        printf("Error : Please enter a valid quantity\n");
                } while (qty <= 0);
                //Transfer data to the books's respected location in the array based on the book chosen
                bookQty[un] += qty;
                total[un] += qty;
                bookPay[un] = bookQty[un] * BOOK_PRICE[un];
            }
            else if (book != 'X')
                printf("\nPlease re-enter the book you wish to purchase or enter X to exit your order.\n\n");
        } while (book != 'X');
        //Confirm order

        if (book == 'X')
        {
            do {
                confirm = confirmTest();//Calls the confirm test function
                confirm = toupper(confirm);
                printf("\n");
                //If the order is confirmed then the receipt is automatically displayed
                if (confirm == 'Y')
                {
                    printf("%71s\n", "+=========+==========+================+=============+");
                    printf("%27s%2s%9s%2s%15s%2s%10s%4s\n", "| Books  ", "|", "Quantity", "|", "Price per book", "|", "Amount", "|");
                    printf("%71s\n", "+=========+==========+================+=============+");
                    for (un = 0; un < 16; un++)
                    {
                        if (bookQty[un] > 0)
                        {
                            printf("%24s %c%3s%8d%3s%4s%11.2lf%2s%3s%10.2lf|\n", "| Book", 65 + un, "|", bookQty[un], "|", "RM", BOOK_PRICE[un], "|", "RM", bookPay[un]);//Displays the books and quantity of books inputted from the user
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

                    disAmt = subtotal * disRate;//Calculation of the amount of discount given for the order
                    totalPay = subtotal - disAmt;//Calculation of the total amount that has to be paid for the order
                    ttlDis += disAmt;//Adds the discount from the order into the total discount from all orders

                    printf("%71s\n", "+=========+==========+================+=============+");
                    printf("%19s", "|");
                    printf(" *  *  ** **  ***** ");
                    printf("%s", "|");
                    printf("%15s | RM%10.2lf|\n", "Subtotal", subtotal);
                    printf("%19s", "|");
                    printf(" *  * *  *  *   *   ");
                    printf("%s", "|");
                    printf("%15s | RM%10.2lf|\n", "(-) Discounts", disAmt);
                    printf("%19s", "|");
                    printf(" *  * *  *  *   *   ");
                    printf("%s", "+");
                    printf("================");
                    printf("%15s", "+=============+\n");
                    printf("%19s", "|");
                    printf("  **  *  *  *   *   ");
                    printf("%s", "|");
                    printf("%15s | RM%10.2lf|\n", "Total to Pay", totalPay);
                    printf("%71s\n", "+====================+================+=============+");
                    printf("\n%67s\n", "HAVE A NICE DAY! WE HOPE TO SEE YOU SOON!");
                }
                //If the user cancels the order, the data from the order is cleared
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
                    printf("Please enter a choice that has been given\n");

            } while (!(confirm == 'Y' || confirm == 'C' || confirm == 'N'));
        }
    } while (confirm == 'N');
    //If confirm = Y or confirm = C, end looping 
}

char next()
{
    char nextOrder;
    do
    {
        //The user is asked if he wants to go to the next order
        nextOrder = nextTest();
        nextOrder = toupper(nextOrder);
        if (nextOrder != 'Y' && nextOrder != 'N')//Input validation
            printf("\nPlease enter a choice that has been given.\n");
    } while (nextOrder != 'Y' && nextOrder != 'N');

    return nextOrder;
}

void summary() {
    //Variables
    double amt[16];//The total earnings for each book
    int totalBooks = 0;
    double totalAmt = 0;

    printf("\n\n");
    logoHeading();

    printf("\n%59s\n", "**DAILY SALES ORDER SUMMARY REPORT**");
    printf("%60s\n", "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    printf("%52s = %d}\n", "{Total Number of Sales Order", salesOrder);
    printf("%60s\n", "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv");
    printf("%27s+%s+%s+\n", "+=======", "=====================", "============");
    printf("%20c%5s%3c%20s%2c%9s%4c\n", '|', "Book", '|', "Quantity Sold Sales", '|', "Amount", '|');
    printf("%27s+%s+%s+\n", "+=======", "=====================", "============");

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
        printf("%20c%4c%4c%11d %10c%s %9.2lf|\n", '|', 65 + un, '|', total[un], '|', "RM", amt[un]);
    }

    printf("%27s+%s+%s+\n", "+=======", "=====================", "============");
    //Display the total amount of books sold and cash accumulated from each order
    printf("%20c %s|%11d %10c%s %9.2lf|\n", '|', "TOTAL:", totalBooks, '|', "RM", totalAmt);
    printf("%27s+%s+%s+\n", "+=======", "=====================", "============");
    //Display the total discount given for all orders
    printf("%20c%29s|RM %9.2lf|\n", '|', "**TOTAL DISCOUNT GIVEN** :", ttlDis);
    printf("%27s=%s+%s+\n", "+=======", "=====================", "============");

    system("pause");
    //The end of the program
    exitP();
}
