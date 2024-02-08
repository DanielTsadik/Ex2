#include <stdio.h>

#define MAX_WEIGHT 20
#define MAX_ITEMS 5

int knapSack(int weights[], int values[], int selected_bool[]) {
    int dp[MAX_ITEMS + 1][MAX_WEIGHT + 1];

    // Calculate the maximum profit for all subproblems
    for (int i = 0; i <= MAX_ITEMS; i++) {
        for (int w = 0; w <= MAX_WEIGHT; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w) {
                // Determine whether including the current item would yield a higher profit
                int include_current_item = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                int exclude_current_item = dp[i - 1][w];
                if (include_current_item > exclude_current_item)
                    dp[i][w] = include_current_item;
                else
                    dp[i][w] = exclude_current_item;
            }
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Backtrack to find which items were selected
    int res = dp[MAX_ITEMS][MAX_WEIGHT];
    int w = MAX_WEIGHT;
    for (int i = MAX_ITEMS; i > 0 && res > 0; i--) {
        if (res == dp[i - 1][w])
            continue;
        else {
            selected_bool[i - 1] = 1;
            res -= values[i - 1];
            w -= weights[i - 1];
        }
    }

    return dp[MAX_ITEMS][MAX_WEIGHT];
}

int main() {
    char items[MAX_ITEMS];
    int values[MAX_ITEMS];
    int weights[MAX_ITEMS];
    int selected_bool[MAX_ITEMS] = {0};
 
    for(int i = 0; i < MAX_ITEMS; i++)
    scanf(" %c %d %d", &items[i], &values[i], &weights[i]);
    
    // Calculate maximum profit and select items
    int maxProfit = knapSack(weights, values, selected_bool);

    // Display results
    printf("Maximum profit: %d\n", maxProfit);
    printf("Items that give the maximum profit: [");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (selected_bool[i] == 1) {
            printf("%c, ", items[i]);
        }
    }
    printf("\b\b]\n");

    return 0;
}

