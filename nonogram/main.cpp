#include <vector>
#include <iostream>

using namespace std;

void print(vector<int> r)
{
    for (auto it : r)
        cout << it << " ";

    cout << endl;
}

vector<int> row_map(vector<vector<int>> mat, int row) // given row index
{

    vector<int> r;
    int c = 0;
    int n = mat[row].size(); // rows
    // row const, iterate through cols
    for (int j = 0; j < n; j++)
    {
        if (mat[row][j] == 0)
        {
            c++;
        }
        else if (mat[row][j] == 1 && c > 0)
        {
            r.push_back(c);
            c = 0;
        }
    }
    if (c > 0)
        r.push_back(c);
    cout << row << ":";
    print(r);

    return r;
}

vector<int> col_map(vector<vector<int>> mat, int col)
{
    int n = mat.size();
    vector<int> r;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (mat[i][col] == 0)
        {
            c++;
        }
        else if (mat[i][col] == 1 && c > 0)
        {
            r.push_back(c);
            c = 0;
        }
    }

    if(c>0)
        r.push_back(c);
    return r;
}

bool validate(vector<vector<int>> &nonogram, vector<vector<int>> &row_c,vector<vector<int>> &col_c)
{
    int m = nonogram.size(), n = nonogram[0].size();

    for (int i = 0; i < m; i++)
        if (row_c[i] != row_map(nonogram, i))
            return false;

    for(int j=0;j<n;j++)
        if(col_c[j]!=col_map(nonogram,j))
            return false;
    
    
    return true;
}



int main()
{

    vector<vector<int>> nonogram = {{1, 1, 1, 1},
                                    {0, 1, 1, 1},
                                    {0, 1, 0, 0},
                                    {1, 1, 0, 1},
                                    {0, 0, 1, 1}};
    vector<vector<int>> row_c = {{}, {1}, {1, 2}, {1}, {2}};
    vector<vector<int>> col_c = {{2,1},{1},{2},{1}};
    cout << validate(nonogram, row_c,col_c);
    return 0;
}