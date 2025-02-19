#include <stdio.h>

// Function to find the maximum and minimum values in the given array
void findMaxMin(int arr[], int n, int *maxIndex, int *minIndex)
{
    *maxIndex = 0;
    *minIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[*maxIndex])
        {
            *maxIndex = i;
        }
        if (arr[i] < arr[*minIndex])
        {
            *minIndex = i;
        }
    }
}

// Function to minimize cash flow among a group of people
void minimizeCashFlow(int amount[], int n)
{
    int maxCreditIndex, maxDebitIndex;
    findMaxMin(amount, n, &maxCreditIndex, &maxDebitIndex);

    if (amount[maxCreditIndex] == 0 && amount[maxDebitIndex] == 0)
    {
        return; // All balances settled
    }

    int minBalance = (amount[maxCreditIndex] < -amount[maxDebitIndex]) ? amount[maxCreditIndex] : -amount[maxDebitIndex];

    // Update the balances
    amount[maxCreditIndex] -= minBalance;
    amount[maxDebitIndex] += minBalance;

    printf("Person %d pays %d to Person %d\n", maxDebitIndex, minBalance, maxCreditIndex);

    minimizeCashFlow(amount, n); // Recursively minimize the remaining balances
}

int main()
{
    int n; // Number of people
    printf("Enter the number of people: ");
    scanf("%d", &n);

    int amount[n]; // Balances for each person
    printf("Enter the balances for each person:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &amount[i]);
    }

    minimizeCashFlow(amount, n);
    return 0;
}