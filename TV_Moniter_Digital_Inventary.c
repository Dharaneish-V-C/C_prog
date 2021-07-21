/*
Dharaneish V C - CB.EN.U4CSE20315
BTech CSE 2024, Amrita University, Coimbatore
20 July, 2021
Based on Basic C Programming - Basics, Functions, Arrays, Structures

-------------------------------------------------------------TV & Moniter Digital Inventary---------------------------------------------
Let a electronics store sells Televisions and Computer Monitors. It is attempting to create a digital inventory for its products. 
Each electronic is defined by its model id (numeric), price, quantity available and  Numbers_sold. 
A television has certain specifications such as screen resolution, refresh rate, and type (OLED, LED, Plasma). 
Monitors have specifications such as Screen size, brightness, and response time.

Following functions are done -
1. To allow user to enter new items/delete old items from the inventory (except Numbers_sold)
2. allowing a user to update the specifications as well as quantity of the product (except Numbers_sold)
3. a user can input any specification and all models with that specification are displayed along with full info (filter) (except Numbers_sold)
4. To get input of Numbers_sold for each item and calculate the total revenue the store has generated.
5. Sort the products based on number of units sold and determine most popular product.
6. Output info about inventory
-------------------------------------------------------------------------------------------------------------------------------------------- */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct              // structure for electronics 
{
    int model_id;
    float price;
    unsigned int Quantity;
    unsigned int numbers_sold;
}electronic;

typedef struct           // structure for Resolution
{
    unsigned int x;
    unsigned int y;
}resolution;

typedef struct          // structure for television
{
    electronic Info;
    resolution screen;
    int refresh_rate;
    char type[10];
}television;

typedef struct          //structure for Moniter
{
    electronic Info;
    int screen;
    int brightness;
    int response_time;
}monitor;

television tv[25];      // array data of TV
monitor mon[25];        // array data of Moniter

int no_of_tv = 0;       //No of array elements filled. Initialsed as 0. incremented when data added, decremented when data deducted
int no_of_mon = 0;      //No of array elements filled. Initialsed as 0. incremented when data added, decremented when data deducted

void sort_tv();     
void sort_mon();
void update();
void sales();
int choice();
int check_mon(int);
int check_tv(int);
void data_tv();
void data_mon();
void view();
void add_remove();
void print_tv(int);
void print_mon(int);
void find_mon();
void find_tv();
void main()
{
    int menu;
do
 {
    menu = choice();
    switch (menu)
    {
    case 1:
        add_remove();
        break;

    case 2:
        update();
        break;

    case 3:
        find_tv();
        break;

    case 4:    
        find_mon();
        break;

    case 5:
        sales();
        break;

    case 6:
        sort_tv();
        break;

    case 7:    
        sort_mon();
        break;

    case 8:
        view();
        break;    

    case 9:
        printf("Thank You for using");
        return;
        break;  

    default:
        printf("ERROR!! PLEASE QUIT!");
        break;
    }
 } while (menu!=6);       // loop until exit is given
}
int choice() // return the choice. called first in the main
{
    int ch;
    printf("\n---------------------------------------------------------Menu-------------------------------------------------------\n");
    printf(" 1. Enter new items/delete old items from the inventory \n 2. Update the specifications + quantity of the product \n 3. Filter TV with specs \n 4. Filer Monitor with specs \n 5. Input for Quantity sold. Total revenue the store has generated. \n 6. Sort TVs based on number of units sold and determine most popular product \n7. Sort Moniters based on number of units sold and determine most popular product \n 8. View Data \n 9. Exit");
    printf(" Enter your choice(1-9): ");
    fflush(stdin);
    scanf("%d", &ch);
    while (ch>9 || ch<1)
    {
        printf("Wrong Value. Enter Again (1-9):");
        scanf("%d", &ch);
    }
    return ch;
}
void print_tv(int i) // takes index as input and displays all structure details in the corressponding index of tv array
{
    printf("ID: %d \n",tv[i].Info.model_id);
    printf("Quantity: %d \n",tv[i].Info.Quantity);
    printf("Price: %f \n",tv[i].Info.price);
    printf("Resolution: %d X %d \n",tv[i].screen.x,tv[i].screen.y );
    printf("Refresh Rate: %d \n", tv[i].refresh_rate);
    printf("Type:",tv[i].type);
    if(tv[i].Info.numbers_sold != NULL)
    printf("Numbers Sold:",tv[i].Info.numbers_sold);
}
void print_mon(int i)   // takes index as input and displays all structure details in the corressponding index of moniter array
{
    printf("\n ID: %d", mon[i].Info.model_id);
    printf("\n Quantity: %d",mon[i].Info.Quantity);
    printf("\n Price: %f",mon[i].Info.price);
    printf("\n Screen size: %d",mon[i].screen);
    printf("\n Brightness: %d",mon[i].brightness);  
    printf("\n Response Time: %d",mon[i].response_time);
    if(mon[i].Info.numbers_sold != NULL)
    printf("Numbers Sold:",mon[i].Info.numbers_sold);
}
void data_tv(int i) // i = index, takes index as input and askes input for all struct details in the corressponding index of tv array
{
        printf("Enter Quantity:");
        scanf("%d", &tv[i].Info.Quantity);
        fflush(stdin);
        printf("Enter Price:");
        scanf("%f", &tv[i].Info.price);
        fflush(stdin);
        printf("Enter Resolution - X:");
        scanf("%d", &tv[i].screen.x);
        fflush(stdin);
        printf("Enter Resolution - Y:");
        scanf("%d", &tv[i].screen.y);
        fflush(stdin);
        printf("Enter Refresh Rate:");
        scanf("%d", &tv[i].refresh_rate);
        fflush(stdin);
        printf("Enter Type:");
        gets(tv[i].type);
        fflush(stdin);
}
void data_mon(int i) // i = index takes index as input and asks input for all struct details in the corressponding index of moniter array
{
        printf("Enter Quantity:");
        scanf("%d", &mon[i].Info.Quantity);
        fflush(stdin);
        printf("Enter Price:");
        scanf("%f", &mon[i].Info.price);
        fflush(stdin);
        printf("Enter Screen size:");
        scanf("%d", &mon[i].screen);
        fflush(stdin);
        printf("Enter Brightness:");
        scanf("%d", &mon[i].brightness);
        fflush(stdin);
        printf("Enter Response Time :");
        scanf("%d", &mon[i].response_time);
        fflush(stdin);
}
int check_tv(int id)    //check if particular id exists in tv array or not
{
    for (int i = 0; i < no_of_tv; i++)
    {
        if(tv[i].Info.model_id==id)
        return 1;
    }
    return 0;
}

int check_mon(int id)   //check if particular id exists in moniter array or not
{
    for (int i = 0; i < no_of_mon; i++)
    {
        if(mon[i].Info.model_id==id)
        return 1;
    }
    return 0;
}

void add_remove() // function to add or remove an item in inv - both tv, moniter
{
    int opt;
    printf("1.Enter New TV \n 2.Delete Old TV \n3. Enter New Moniter \n4.Delete old monitor \n Enter(1-4):");
    scanf("%d",&opt);
    while(opt>4 || opt<1)
    {
        printf(" Error Input.1.Enter New TV \n 2.Delete Old TV \n3. Enter New Moniter \n4.Delete old monitor \n Enter(1-4):");
        scanf("%d",&opt);
    }
    if(opt ==1) //add tv
    {
        int i = no_of_tv;
        printf("Enter ID:");
        scanf("%d",&tv[i].Info.model_id);
        while (check_tv(tv[i].Info.model_id))  
        {
            printf("ID already exists. Enter a Unique Number:");
            scanf("%d",&tv[i].Info.model_id);
        }
        fflush(stdin);
        data_tv(i);
        no_of_tv++;
    }
    else if(opt==2) //delete tv
    {
        unsigned int id;
        printf("Enter ID:");
        scanf("%d",&id);
        fflush(stdin);
        for (int i = 0; i < no_of_tv; i++)
        {
            if(id == tv[i].Info.model_id)
            {
                char c;
                printf("Details of Deleted Element: \n");
                print_tv(i);
                printf("\n Do you wish to delete:(y/n):");
                scanf("%c",&c);
                fflush(stdin);
                if ( c=="Y" || c=="y")
                {
                    while(i<no_of_tv-1)
                    {
                        tv[i]=tv[i+1];
                        i++;
                    } 
                printf("Deleted successfully.");
                no_of_tv--;
                }
                else
                {
                    printf("Deletion NOT done!!!");
                }
                 break;
            }
        }
        
    }
    else if(opt==3) //add moniter
    {
        int i = no_of_mon;
        printf("Enter ID:");
        scanf("%d", &mon[i].Info.model_id);
        while (check_mon(mon[i].Info.model_id))
        {
            printf("ID already exists. Enter a Unique Number:");
            scanf("%d",&mon[i].Info.model_id);
        }
        fflush(stdin);
        data_mon(i);
        no_of_mon++;
    }
     else if(opt==4)    //delete moniter
    {
        unsigned int id;
        printf("Enter ID:");
        scanf("%d",&id);
        fflush(stdin);
        for (int i = 0; i < no_of_mon; i++)
        {
            if(id == mon[i].Info.model_id)
            {
                char c;
                printf("Details of Deleted Element: \n");
                print_mon(i);
                printf("\n Do you wish to delete:(y/n):");
                scanf("%c",&c);
                fflush(stdin);
                if (c=="Y" || c=="y")
                {
                    while(i<no_of_mon-1)
                    {
                        mon[i]=mon[i+1];
                        i++;
                    } 
                printf("Deleted successfully.");
                no_of_mon--;
                }
                else
                {
                    printf("Deletion NOT done!!!");
                }
                 break;
            }
        }    
    }
        
}

void find_mon()     //finding a moniter by filter option
{
    int ch;
    printf("1.Screen \n2.Brightness \n3.Response Time \n Choose Specification:");
    scanf("%d",&ch);
    fflush(stdin);
    if(ch==1)
    {
        int s;
        printf("Enter Screen size:");
        scanf("%d",&s);
        fflush(stdin);
        int count=0;
        for (int i = 0; i < no_of_mon; i++)
        {
            if(s==mon[i].screen)
            {
                count++;
                print_mon(i);
            }
            printf("Total: %d results found.", count);
        }
    }
     if(ch==2)
    {
        int b;
        printf("Enter Brightness:");
        scanf("%d",&b);
        fflush(stdin);
        int count=0;
        for (int i = 0; i < no_of_mon; i++)
        {
            if(b==mon[i].brightness)
            {
                count++;
                print_mon(i);
            }
            printf("Total: %d results found.", count);
        }
    }
     if(ch==3)
    {
        char r;
        printf("Enter Response:");
        scanf("%d", &r);
        fflush(stdin);
        int count=0;
        for (int i = 0; i < no_of_mon; i++)
        {
            if(r==mon[i].response_time)
            {
                count++;
                print_mon(i);
            }
            printf("Total: %d results found.", count);
        }
    }
}

void find_tv()  // finding a tv by filter option
{
    int ch;
    printf("1.Screen Resolution \n2.Refresh Rate \n3.Type \n Choose Specification:");
    scanf("%d",&ch);
    fflush(stdin);
    if(ch==1)
    {
        int x,y;
        printf("Enter Resolution X:");
        scanf("%d",&x);
        fflush(stdin);
        printf("Enter Resolution Y:");
        scanf("%d",&y);
        fflush(stdin);
        int count=0;
        for (int i = 0; i < no_of_tv; i++)
        {
            if(x==tv[i].screen.x && y==tv[i].screen.y)
            {
                count++;
                print_tv(i);
            }
            printf("Total: %d results found.", count);
        }
    }
     if(ch==2)
    {
        int r;
        printf("Enter Refresh rate:");
        scanf("%d",&r);
        fflush(stdin);
        int count=0;
        for (int i = 0; i < no_of_tv; i++)
        {
            if(r==tv[i].refresh_rate)
            {
                count++;
                print_tv(i);
            }
            printf("Total: %d results found.", count);
        }
    }
     if(ch==3)
    {
        char t[10];
        printf("Enter Type:");
        gets(t);
        fflush(stdin);
        int count=0;
        for (int i = 0; i < no_of_tv; i++)
        {
            if(strcmpi(t,tv[i].type)==0)
            {
                count++;
                print_tv(i);
            }
            printf("Total: %d results found.", count);
        }
    }
}

void update()   // Update info in existing array - tv, momiter (ID is fixed)
{
    int opt;
    // printf("Total No of TV: %d \n Total No of Moniter: %d \n", no_of_tv, no_of_mon);
    printf("1.Update TV \n 2.Update Moniter\n Enter(1-2):");
    scanf("%d",&opt);
    while(opt>2 || opt<1)
    {
        printf(" Error Input.1.Update TV \n 2.Update Moniter\n Enter(1-2):");
        scanf("%d",&opt);
        fflush(stdin);
    }
    if(opt==1)
    {   int flag=0;
       unsigned int id;
        printf("Enter ID:");
        scanf("%d",&id);
        fflush(stdin);
        for (int i = 0; i < no_of_tv; i++)
        {
            if(id == tv[i].Info.model_id)
            {
                flag=1;
                data_tv(i);
            } 
            break;
        } 
        if (flag == 0)
        {
            printf("No item found in the given ID");
        }
           
    }
    else
    {
        int flag=0;
        unsigned int id;
        printf("Enter ID:");
        scanf("%d",&id);
        fflush(stdin);
        for (int i = 0; i < no_of_mon; i++)
        {
            if(id == mon[i].Info.model_id)
            {
                flag=1;
                data_mon(i);
            } 
            break;
        }
        if (flag == 0)
        {
            printf("No item found in the given ID");
        }
    }
}

void sales()       // takes input total items sold for all TVs, moniters
{
    float revenue=0;
    printf("TELEVISIONS:");
    for(int i=0; i<no_of_tv; i++)
    {
        printf("\n Item Details:");
        print_tv(i);
        printf("\n Enter Items Sold:");
        scanf("%d", &tv[i].Info.numbers_sold);
        fflush(stdin);
        revenue += (tv[i].Info.numbers_sold) * (tv[i].Info.price);
    }
    printf("MONITERS:");
    for(int i=0; i<no_of_mon; i++)
    {
        printf("\n Item Details:");
        print_mon(i);
        printf("\n Enter Items Sold:");
        scanf("%d", &mon[i].Info.numbers_sold);
        fflush(stdin);
        revenue += (mon[i].Info.numbers_sold) * (mon[i].Info.price);
    }
    printf("\nTotal Revenue: %d", revenue);
}

void sort_tv()  // sort TV details based on no of items sold and print
{
    char ch;
    printf("Is Quantity enetered for all products:(y/n):");
    scanf("%c",&ch);
    if (ch!="Y" && ch!= "y")
    {
        printf("Please Enter Values before you Sort.");
        return;
    }
    int i,j;
    for (i = 0; i < no_of_tv - 1; i++)          // Bubble Sort
    {
        for(j=0; j< no_of_tv -i -1; j++)
        if(tv[j].Info.numbers_sold < tv[j+1].Info.numbers_sold) // Descending Order
        {
            television temp;                    // Swap
            temp = tv[j];
            tv[j] = tv[j+1];
            tv[j+1]=temp;
        }
    }
     printf("Sorted TV in!!! The values are: \n");
    for (i = 0; i < no_of_tv; i++)
    {
        printf("TV: %d", i+1);
        print_tv(i);
    }
}

void sort_mon() //sort moniter details based on no of items sold and print
{
    char ch;
    printf("Is Quantity entered for all products:(y/n):");
    scanf("%c",&ch);
    fflush(stdin);
    if (ch!="Y" && ch!= "y")
    {
        printf("Please Enter Values before you Sort.");
        return;
    }
    int i,j;
    for (i = 0; i < no_of_mon - 1; i++)          // Bubble Sort
    {
        for(j=0; j< no_of_mon -i -1; j++)
        if(mon[j].Info.numbers_sold < mon[j+1].Info.numbers_sold)   //Descending Order
        {
            monitor temp;                    // Swap
            temp = mon[j];
            mon[j] = mon[j+1];
            mon[j+1]=temp;
        }
    }
     printf("Sorted Moniters!!! The values are: \n");
    for (i = 0; i < no_of_mon; i++)
    {
        printf("Moniter: %d", i+1);
        print_mon(i);
    }
}
void view()
{
    int ch;
    printf("1. View All TVs \n2. View All Moniters \n3. View TV based on ID \n 4. View Moniter based on ID");
    scanf("%d",&ch);
    fflush(stdin);
    switch (ch)
    {
        case 1:
            {
                for (int i = 0; i < no_of_tv; i++)
                {
                    printf("\n No %d : \n", i+1);
                    print_tv(i);
                }
                break;
            }
        case 2:
            {
                for (int i = 0; i < no_of_mon; i++)
                {
                    printf("\n No %d : \n", i+1);
                    print_mon(i);
                }
                break;
            }
        case 3:
        {
            int ch;
            printf("Enter ID:");
            scanf("%d", &ch);
            fflush(stdin);
            if(check_tv(ch))
            {
                print_tv(ch);
            }
            else{
                printf("No Model with the given ID.");
            }
            break;
        }
            
        case 4:
            {
            int ch;
            printf("Enter ID:");
            scanf("%d", &ch);
            fflush(stdin);
            if(check_mon(ch))
            {
                print_mon(ch);
            }
            else{
                printf("No Model with the given ID.");
            }
            break;
        }
        default:
        printf("Error Option.");
    }
}

//end
