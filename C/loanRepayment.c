#include<stdio.h>

void main(){
    int dur,i,choice;
    float loan_amt,loan_amt1,rate,emi,new_emi,total_interest,total_amt_paid = 0.0;

    start:
    printf("    Option:- 1.Calculate Loan Repayment\n             2.Quit\n");
    scanf("%d",&choice);

    if(choice==1){
    printf("Enter the Loan Amount:- ");
    scanf("%f",&loan_amt);
    loan_amt1 = loan_amt;
    printf("\nEnter the Duration (in Months):- ");
    scanf("%d",&dur);
    printf("\nEnter the rate:- ");
    scanf("%f",&rate);
    rate = rate/100;
    emi = loan_amt/dur;
    /*printf("\n%.2f",emi);*/
    for(i=1;i<=dur;i++){
        new_emi = emi + (loan_amt*rate);
        total_amt_paid = total_amt_paid + new_emi;
        printf("\tInterest for %d month = %.2f",i,loan_amt*rate);
        loan_amt = loan_amt - emi;
        printf("\tEMI for month %d = %.2f\tRemaining Amount = %.2f\n",i,new_emi,loan_amt);
    }

    total_interest = total_amt_paid - loan_amt1;
    printf("\n\n\t\tTotal Amount Paid = %.2f \n",total_amt_paid);
    printf("\t\tTotal Interest Paid = %.2f \n",total_interest);
    goto start;
    }
    else if(choice==2){
        printf("\nThank You!\n");

    }
    else{
        printf("You entered wrong Option !\nEnter Correct Option\n");
        goto start;
    }
    system("pause");
}
