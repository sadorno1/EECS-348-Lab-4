#include <stdio.h>

//function to find the the combinations of scoring plays when you put in an int
void findCombinations(int score) {
    printf("Possible combinations of scoring plays if a team's score is %d:\n", score);
    
    //loop through possible touchdowns+2
    for (int td2 = 0; td2 * 8 <= score; td2++) {
        //loop through possible touchdowns+1
        for (int td1 = 0; td1 * 7 + td2 * 8 <= score; td1++) {
            //loop through possible touchdowns
            for (int td = 0; td * 6 + td1 * 7 + td2 * 8 <= score; td++) {
                //loop through possible field goals
                for (int fg = 0; fg * 3 + td * 6 + td1 * 7 + td2 * 8 <= score; fg++) {
                    //loop through possible safeties
                    for (int safety = 0; safety * 2 + fg * 3 + td * 6 + td1 * 7 + td2 * 8 <= score; safety++) {
                        int total = td2 * 8 + td1 * 7 + td * 6 + fg * 3 + safety * 2;
                        if (total == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safety\n", td2, td1, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    
    while (1) {
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);
        
        //stop the program if less or equal q
        if (score <= 1) {
            printf("Program terminated.\n");
            break;
        }
        
        //calls function
        findCombinations(score);
    }
    
    return 0;
}
