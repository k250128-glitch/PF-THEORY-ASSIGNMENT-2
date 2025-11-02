
#include <stdio.h>
#include <stdlib.h>


#define MAX_COL 3
#define MAX_ROW 3




int get_valid_int_input(int *value,char *message){
    while (1){
        printf("%s",message);
        if(scanf("%d",value)!=1){
            printf("Invalid Input\n");
            continue;
        }
        break;
    }
   
}


int displayMenu(void) {
    int choice;
    while (1){
    printf("\n========= Operator Menu =========\n");
    printf("1. Update Sector Status\n");
    printf("2. Query Sector Status\n");
    printf("3. Run System Diagnostic\n");
    printf("4. Exit\n");
    printf("=================================\n");
    get_valid_int_input(&choice,"Enter your choice: ");
    if(choice <= 0){
        printf("Invalid Input\n");
        continue;
    }
    break;
    }
    return choice;
}




int validate_position_index(int x , int y){
      if (x > MAX_ROW-1 || y > MAX_COL-1){
        printf("Invalid position\n");
        return 1;
      }
      return 0;
}


int get_sector_report(int power_grid[MAX_ROW][MAX_COL],int x, int y){
    if (validate_position_index(x,y)!=0){
        return 1;
    };
    printf("Power is %s\n",power_grid[x][y] & 1?"ON":"OFF");
    printf("there's %s\n",power_grid[x][y] & 2?"overload warning":"no overload warning");
    printf("Maintainence is %s\n",power_grid[x][y] & 4?"required":"not required");
    return 0;
};


int update_sector_status(int power_grid[MAX_ROW][MAX_COL],int x, int y){
    if (validate_position_index(x,y)!=0){
        return 1;
    };
    get_sector_report(power_grid,x,y);


    printf("\n\n");
    int power_status = 0, overload_status = 0, maintainence_status = 0;


    get_valid_int_input(&power_status,"Enter Power status (0/1) : ");
    get_valid_int_input(&overload_status,"Enter Overload warning status (0/1) : ");
    get_valid_int_input(&maintainence_status,"Enter Maintainece status (0/1) : ");


    int final_code  = power_status != 0 + (overload_status != 0 ? 2 : 0) + (overload_status != 0 ? 4 : 0);
    power_grid[x][y] = final_code;


    printf("Sector status has been updated\n");
    return 0;
}






int diagnose_report(int power_grid[MAX_ROW][MAX_COL]){
    int total =0;
    for (int i = 0; i < MAX_ROW; i++){
        for (int j = 0; i < MAX_COL; j++){
            if(power_grid[i][j] & 2||power_grid[i][j] & 4) total++;
        }
    }


    printf("Grid Report");
    printf("Total sectors which required maintainence or overloaded required : %d\n",total);
   
}


int grid_operations(int power_grid[MAX_ROW][MAX_COL]){
    while (1){
    system("cls");
    printf("===========================\n| Power Grid Operations |\n===========================\n");
    int code = displayMenu();
    if(code >= 4) return 0;
    if(code == 1 || code ==2){
        int x =0 , y= 0;
        get_valid_int_input(&x,"Enter row of sector (starts from 0) : ");
        get_valid_int_input(&y,"Enter col of sector (starts from 0) : ");


        if(code == 1)  update_sector_status(power_grid,x,y);
        else get_sector_report(power_grid,x,y);
    }
    else diagnose_report(power_grid);




    printf("\n\n Press Enter to continue : \n\n");
    getchar();


    }
}




int main(){
 int power_grid[MAX_ROW][MAX_COL] = {
    {2,3,5},
    {1,7,4},
    {2,4,3}
 };    


 grid_operations(power_grid);
    return 0;
}
