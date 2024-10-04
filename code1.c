#include <stdio.h>

void scoring(int score)
{
    if (score == 1 || score == 0) return;
    //checks all possible scores <= entered score
    for (int eight_pt = 0; eight_pt <= score / 8; eight_pt++){
        for (int seven_pt = 0; seven_pt <= score / 7; seven_pt++){
            for (int six_pt = 0; six_pt <= score / 6; six_pt++){
                for (int three_pt = 0; three_pt <= score / 3; three_pt++){
                    for (int two_pt = 0; two_pt <= score / 2; two_pt++){
                        int total = eight_pt * 8 + seven_pt * 7 + six_pt * 6 + three_pt * 3 + two_pt * 2;
                        if (total == score){
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", eight_pt, seven_pt, six_pt, three_pt, two_pt);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int score;
    
    do {
    printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
    scanf("%d", &score);
    printf("\n");
    //checks if score is negative
    if(score < 0){
        printf("Enter a valid score\n");
    }
    else{
        scoring(score);
        }
    }
    while (score != 0 && score != 1);
    

    return 0;
}
