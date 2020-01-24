/* THIS PROGRAM SORTS ARRAY DEMONSTRATION PURPOSES */
/* GTU RULEZ */
#include<stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0

void addiction();
void sorting_numbers();
void substract_numbers();
void devide_numbers();
void summarize_numbers();
void exponent_numbers();

int PrintSelection(int selection){
	printf("Selected Menu item is:");
	printf("%d\n",selection);
	return 1;
}

int DisplayMenu(){
 int selection;
 printf("\e[2J"); // clears screen

 printf("%s","\e[5;31;47mWELCOME TO ADDING PROGRAM\e[0m\n");
 printf("%s","(1) Add two numbers\n");
 printf("%s","(2) Sort an array\n");
 printf("%s","(3) Subtract two numbers\n");
 printf("%s","(4) Divide numbers\n");
 printf("%s","(5) Summarize numbers with words\n");
 printf("%s","(6) Exponent two numbers x to the y\n");
 printf("%s","(0) quit\n");
 printf("Selection:");
 scanf("%d",&selection);
 PrintSelection(selection);
 return selection;
}

int main(){

    char wanttoexit = FALSE;
    int choice;


// main loop
while(wanttoexit == FALSE){

	// display menu and get result
	choice = DisplayMenu();

	if(choice == 1){

        addiction();
	}
	if(choice == 2){

        sorting_numbers();
	}
	if (choice == 3){

        substract_numbers();
	}
	if (choice == 4){

        devide_numbers();
	}
	if (choice == 5){

        summarize_numbers();
	}
	if (choice == 6){

        exponent_numbers();
	}

	if(choice == 0){
		wanttoexit = TRUE;
		printf("exiting...");
	}
} // end of while

}

void addiction(){

    int first_number, second_number, sum_of_numbers;
    char c;

    printf("%s","PLEASE  ENTER FIRST NUMBER\n");
    scanf("%d",&first_number);
    if(first_number<1073741824 && first_number>=0){
	printf("PLEASE ENTER SECOND NUMBER:\n");
	scanf("%d",&second_number);
        if(second_number<1073741824 && second_number>=0){
	    sum_of_numbers = first_number + second_number;
	    if(sum_of_numbers<1073741824 && sum_of_numbers>=0){
	        printf("THE RESULT IS : %d\n",sum_of_numbers);
   	    }else{
    		printf("THE RESULT IS TOO BIG");
    	    }
        }else{
	    printf("SECOND NUMBER IS TOO BIG.");
        }
    }else{
	printf("FIRST NUMBER IS TOO BIG.");
    }
	
    printf("\nPlease Enter For Return The Menu...");
    c=getchar();
    c=getchar();
}
void sorting_numbers(){

    int choice;
    int i,j,c;
    int myArray[100];
    int max;
    int pivot;
    int temp;

    printf("%s","Enter numbers for array and 0 for end\n");
		for(i=0;i<100;i++){
			scanf("%d",&choice);
			if(choice == 0) break;
			myArray[i] = choice;
			max = i ;
		}
		printf("Numbers are entered.. \n");
		printf("Now sorting.. ");
	    for(i=0;i<=max;i++){
	       for(j=0;j<max; j++){
	           if(myArray[j] > myArray[j+1]){
	           		temp = myArray[j];
	           		myArray[j]= myArray[j+1];
	           		myArray[j+1]=temp;
	           }
		    }

		}
		printf("finished..\n ");
	    for(i=0;i<=max;i++){
	      printf("%d  ",myArray[i]);
	    }
	      printf("are the numbers.\n");
	      printf("\nPlease Enter For Return The Menu...");


		c=getchar();
		c=getchar();
}
void substract_numbers(){
    int first_number,second_number,sub,c;

    printf("%s","PLEASE  ENTER FIRST NUMBER\n");
    scanf("%d",&first_number);
	if(first_number>1073741824){		//1073741824 is overflow number. When a number is bigger than this,numbers turn negative side
	  printf("First Number Is Too Big.");
	}
    printf("%s","PLEASE  ENTER SECOND NUMBER\n");
    scanf("%d",&second_number);
	if(second_number>1073741824){		//1073741824 is overflow number. When a number is bigger than this,numbers turn negative side
	  printf("Second Number Is Too Big.");
	}
    sub = first_number - second_number;
    printf("The Result Is: ");
    printf("%d\n",sub);
    printf("\nPlease Enter For Return The Menu...");

    c=getchar();
    c=getchar();

}
void devide_numbers(){

    int i,j,k,devided_number,devider_number,temp,temp_float,c;

    printf("%s","PLEASE  ENTER DEVIDED NUMBER\n");
    scanf("%d",&devided_number);
    printf("%s","PLEASE  ENTER DEVIDER NUMBER\n");
    scanf("%d",&devider_number);
        for(i=0;devided_number>=devider_number;i++){
            temp = devided_number-devider_number;
            devided_number = temp;
        }
        if (devided_number==0){
            printf("The Result Is %d,0",i);
        }else if(devider_number==0){
	    printf("The Result Is Infinite.");
        }else{
            printf("The Result Is :%d,",i);
                for(j=1;j<16;j++){              //How Many Digits The Program Will Calculate
                    devided_number=devided_number*10;
                        for(k=0;devided_number>devider_number;k++){
                            temp_float = devided_number-devider_number;
                            devided_number = temp_float;
                        }
                    printf("%d",k);
                }

        }
    printf("\nPlease Enter For Return The Menu...");

    c=getchar();
    c=getchar();

}
void summarize_numbers(){
/*SEPERATING NUMBERS TO DIGITS*/

    int input,remained,c;
    int i=1;

    //The User Enters The Number That Wanted To Be Decomposed
    printf("Please Enter A Number That Is Wanted To Be Decomposed:");
    scanf("%d",&input);

    if(input<10 && input>=0){                                   //Numbers Between 0 and 9 including these numbers.
        printf("The Result Is : %d*10^0",input);                //Specilized Area For Numbers That Are Smaller Then 10
    }else if(input>10){
        printf("The Result Is : ");
        while (input>0){
                        /* remained=input%10;               //Taking The Number From One's Digit With The Mode Operation
                        printf("%d*10^%d",remained,i);     //Printing Digits With Using PrintF
                        //input = input - remained;        (Unnecessary)//The Number In The Result Of The Mode Operation Is Subtracted From The Number Of Entries To Make A Digit Of 0 Which is Unnecessary
   (For symbol 10^a)    input = input/10;                  //A Reduction Of The Digit
                        i++;                               //Adding One To Digit Numbers
                        if(input>0){
                        printf("+");            //For Saving The "+" Symbol
                        */
                        remained=input%10;                  //Taking The Number From One's Digit With The Mode Operation
                        printf("%dx%d",remained,i);         //Printing Digits With Using PrintF
 /*(For Symbol 10xa)    //input = input - remained;         (Unnecessary Part)//The Number In The Result Of The Mode Operation Is Subtracted*/ 				input = input/10;  		    //From The Number Of Entries To Make A Digit Of 0 Which Is Unnecessary
                        i=i*10;                		    //A Reduction Of The Digit
                        
                        if(input>0){
                            printf("+");            /*For Saving The "+" Symbol*/
                        }
        }
    }else{                                                     //For The integers less than zero
        input=input*(-1);   					//Switch Numbers To Positive Side
	printf("The Result İs:");                                     
         while (input>0){
                        remained=input%10;			//Taking The Number From One's Digit With The Mode Operation                  
                        printf("(-%d)x%d",remained,i);     //Printing Digits With Using PrintF
 /*(For Symbol 10xa)*/    /*input = input - remained;      (Unnecessary Part)//The Number In The Result Of The Mode Operation Is Subtracted*/ 								   //From The Number Of Entries To Make A Digit Of 0 Which Is Unnecessary
                        input = input/10;                  //A Reduction Of The Digit
                        i=i*10;
                        if(input>0){
                        printf("+");
                        }
        }
    }
    printf("\nPlease Enter For Return The Menu...");

    c=getchar();
    c=getchar();
}
void exponent_numbers(){
    int first_number,second_number,i,c;
    int result;
    int temp=1;

    printf("%s","PLEASE  ENTER NUMBER THAT WILL BE AT THE BOTTOM\n");
    scanf("%d",&first_number);
    printf("%s","PLEASE  ENTER NUMBER THAT WILL BE AT THE TOP\n");
    scanf("%d",&second_number);

    if (second_number==1){                        //As We Know;If Top Will Be 1,The Result Will be number1
        printf("%d",first_number);
    }else if(0== second_number || 1== first_number){     //As We Know;If The Bottom Is 1 OR The Top Is Zero,The Result Will Be 1
        printf("The Result Is: 1");
    }else if(first_number==0){                   //As We Know;If The Bottom Is 0,The Result Will Be Zero
        printf("The Result Is: 0");
    }else if(second_number==0){                   //As We Know;If The Top Is 0,The Result Will Be One
        printf("The Result Is: 1");
    }else{
        for (i=0;i<second_number;i++){            //Multiply The First Given Number By The Second Given Number
            temp = temp*first_number;
    }
	if(second_number >30 || temp>1073741824){//This Number is 2 over 30 +1 which means when a number exceed 20 over 30, number will overflow.
    	    printf("The Result is too big."); 
	    printf("\nPlease Enter For Return The Menu...");
    	}else{		 
            printf("The Result Is:%d",temp);            //Printing The Result
            printf("\nPlease Enter For Return The Menu...");
    	}
    }
        c=getchar();                                   //For Returning The Main Menu
        c=getchar();
}
