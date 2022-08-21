#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    int a;
    for (a = 0; a < candidate_count; a++)
    {
        if (strcmp(candidates[a], name) == 0)
        {
            // Update ranks array with rank preference
            ranks[rank] = a;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    int a, b;

    for (a = 0; a < candidate_count; a++)
    {
        for (b = a + 1; b < candidate_count; b++)
        {
            preferences[ranks[a]][ranks[b]]++;
        }
    }
    return;
}
// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int a, b;

    for (a = 0; a < candidate_count; a++)
    {
        for (b = a + 1; b < candidate_count; b++)
        {
            if (preferences[b][a] < preferences[a][b])
            {
                pairs[pair_count].winner = a;

                pairs[pair_count].loser = b;

                pair_count++;
            }
            else if (preferences[b][a] > preferences[a][b])
            {
                pairs[pair_count].loser = a;

                pairs[pair_count].winner = b;

                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int a, b;
    for (a = pair_count - 1; a >= 0 ; a--)
    {
        for (b = 0; b <= a - 1; b++)
        {
            if ((preferences[pairs[b + 1].winner][pairs[b + 1].loser]) > (preferences[pairs[b].winner][pairs[b].loser]))
            {
                pair part = pairs[b];

                pairs[b] = pairs[b + 1];

                pairs[b + 1] = part;
            }
        }
    }
    return;
}

bool ball(int finished, int ball_c)
{
    int a;

    for (a = 0; a < candidate_count; a++)
    {
        if (locked[finished][a])
        {
            if (ball(a, ball_c))
            {
                return true;
            }
        }
    }
    return false;

    if (finished == ball_c)
    {
        return true;
    }

}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    int a;

    for (a = 0; a < pair_count; a++)
    {
        if (!ball(pairs[a].winner, pairs[a].loser))
        {
            locked[pairs[a].loser][pairs[a].winner] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int a, b;
    for (a = 0; a < candidate_count; a++)
    {
        int avaliation = 0;

        for (b = 0; b < candidate_count; b++)
        {
            if (locked[b][a] == false)
            {
                avaliation++;
                if (candidate_count == avaliation)
                {
                    printf("%s\n", candidates[a]);
                }
            }
        }
    }
    return;
}
