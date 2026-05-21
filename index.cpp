#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<vector>

using namespace std;

/* Hardcoded grid */
char grid[10][10] = {
  {'A', 'C', 'E', 'D', 'V', 'L', 'X', 'O', 'I', 'L'},
  {'A', 'Z', 'A', 'G', 'G', 'O', 'O', 'S', 'F', 'T'},
  {'H', 'H', 'A', 'I', 'Z', 'X', 'P', 'E', 'S', 'N'},
  {'M', 'U', 'X', 'E', 'O', 'X', 'V', 'A', 'T', 'R'},
  {'K', 'I', 'G', 'S', 'K', 'G', 'N', 'R', 'Z', 'K'},
  {'S', 'X', 'Z', 'O', 'R', 'J', 'W', 'R', 'D', 'B'},
  {'E', 'Z', 'O', 'C', 'W', 'H', 'G', 'A', 'W', 'F'},
  {'D', 'E', 'B', 'M', 'F', 'F', 'Z', 'Y', 'A', 'N'},
  {'S', 'I', 'D', 'X', 'D', 'S', 'P', 'H', 'H', 'O'},
  {'B', 'P', 'A', 'P', 'O', 'O', 'L', 'M', 'T', 'M'}
};

/* Hardcoded words to search */
vector<string> words = {"STACK", "ARRAY", "LOOP", "CLASS", "POINTER"};

/* Unit vectors that represent direction */
vector<vector<int>> d_check = {
        {0,-1}, {1,-1}, {1,0}, {1,1}, {0,1}, {-1,1}, {-1,0}, {-1,-1}
};

/* Location of the starting word will be inserted here */
vector<vector<int>> found_indices;

/* Check weather match is found */
bool is_match = false;

/* Function declerations */
void check_match(const vector<int>& c_idx);
void full_word_check(
    const int flag_dir, 
    const int flag_word, 
    const vector<int> c_idx
);
vector<int> add_cord(
    const vector<int>& cord, 
    const vector<int>& dir
);

/* main */
int main() {

    /* Dynamic grid will be added in future */

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int f_idx = 0; f_idx < size(words); f_idx++)
            {
                if (words[f_idx][0] == grid[i][j])
                {
                    check_match({i,j});
                }
            }
        }
    }

    return 0;
}

// Checks for the first letter match
void check_match(const vector<int>& c_idx)
{
    unsigned int flag_dir = 10;
    unsigned int flag_word = 10;

    for (int f_idx = 0; f_idx < words.size(); f_idx++)
    {
        for (int d_idx = 0; d_idx < d_check.size(); f_idx++, d_idx++)
        {
            vector<int> added_cord = add_cord(c_idx, d_check[d_idx]);
            if ((added_cord[0] < 0 || added_cord[0] > 9) && 
                (added_cord[1] < 0 || added_cord[1] > 9))
                continue;
            
            if (grid[added_cord[0]][added_cord[1]] == words[f_idx][0])
            {
                flag_dir = d_idx;
                flag_word = f_idx;
                full_word_check(flag_dir, flag_word, c_idx);
                return;
            }
        }
    }
}


// Full word is checked in this function
void full_word_check(
    const int flag_dir, 
    const int flag_word, 
    const vector<int> c_idx)
{
    string word = words[flag_word];

    int count = 0;
    vector<int> curr_idx = c_idx;
    for (int i = 0; i < word.size(); i++)
    {
        if (grid[curr_idx[0]][curr_idx[1]] == word[i])
        {
            count++;
            if (count == word.size())
                found_indices.push_back(c_idx);
                return;
        }
        vector<int> move = add_cord(curr_idx, d_check[flag_dir]);
        if ((move[0] < 0 || move[0] > 9) && 
            (move[1] < 0 || move[1] > 9))
                return;
    }
}

// adds two coordinates together
vector<int> add_cord(const vector<int>& cord, const vector<int>& dir) 
{
    return {cord[0] + dir[0], cord[1] + dir[1]};
}


// returns direction of the match
// vector<int> direction (const vector<int>& cord1, const vector<int>& cord2) 
// {
//     return {abs(cord2[0] - cord1[0]), abs(cord2[1] - cord1[1])};
// }