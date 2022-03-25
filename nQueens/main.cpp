#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;



class Solution {
public:
    vector<vector<string >> solveNQueens(int n) {
        

        vector<vector<string>> r ;
        vector<string> board = generate_board(n);
        int i = 0;
        for(int j=0;j<n;j++)
        {
            board[i][j] = 'Q';

            helper(board,i+1,j,n,r);
            board[i][j] = '.'; //prep for next recursion
        }
        return r;

    }

    private:
        vector<string> generate_board(int n)
        {
            vector<string> r;
            for(int i=0;i<n;i++)
                r.push_back( string(n,'.'));
            return r;
            
        }

        void helper(vector<string> board, int i,int j,int n,vector<vector<string>> &r)
        {
              
                if(!isValid( board)) //no point recursing any further eh ?
                    return ;
                
                if(i==n)
                    {   
                        
                        if(isValid(board))
                            {
                                // print_board(board);
                                r.push_back(board);}
                        //check if board is valid, if it is, then save in a vector.
                        return;
                        }
                for(int k=0;k<n;k++) //place a queen in the row
                    {
                        board[i][k] = 'Q';
                        
                        helper(board,i+1,j,n,r);
                        board[i][k] = '.';
                        
                    }

                    
                
                
        }

        void print_board(vector<string> board)
        {
            cout<<"\n";
            for(int i=0;i<board.size();i++)
                cout<<board[i]<<"\n";
        }

        bool isValid(vector<string> board)
        {

            int n = board.size();
            for(int i=0;i<board.size();i++)
            {
                for(int j=0;j<board[i].size();j++)
                {
                    if(board[i][j] == 'Q')
                    {
                        for(int k=i+1;k<n;k++) //check rows q 
                        {
                            if(board[k][j] == 'Q')
                                return false;
                        }
                        int ki = i+1;
                        int kj = j+1;
                        while(ki<n && kj<n)// bottom right diagonal
                        {
                            if(board[ki][kj] == 'Q')
                                return false;
                                ki++;
                                kj++;
                        }
                        ki = i+1;
                        kj = j-1;
                        while(ki>0 && ki <n ) //bottom left diagonal
                        {
                            if(board[ki][kj] == 'Q')
                                return false;
                            ki++;
                            kj--;
                        }


                    }
                }
            }

            return true;
        }

};


int main()
{

    Solution s;
    int n = 3; //lets start small
    cout<<s.solveNQueens(n).size()<<endl;
    



    return 0;
}