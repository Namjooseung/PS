#include <bits/stdc++.h>
using namespace std;

int N, M, H;
int board[300][25] = {
    0,
};

bool PlayGame()
{
    int CheckNum=0;
    for (int i = 0; i < N * 2 - 1; i += 2)
    {
        pair<int, int> Sur = make_pair(0, i);
        bool SideMove = false;
        while (1)
        {
            if (Sur.first == H)
            {
                if(Sur.second==i) CheckNum++;
                else return false;
                break;
            }
            if (SideMove)
            {
                Sur = make_pair(Sur.first + 1, Sur.second);
                SideMove = false;
                continue;
            }
            if (Sur.second == 0)
            {
                if (board[Sur.first][Sur.second + 1] == 1)
                {
                    Sur = make_pair(Sur.first, Sur.second + 2);
                    SideMove = true;
                }
                else
                    Sur = make_pair(Sur.first + 1, Sur.second);
                continue;
            }
            if (Sur.second == N * 2 - 2)
            {
                if (board[Sur.first][Sur.second - 1] == 1)
                {
                    Sur = make_pair(Sur.first, Sur.second - 2);
                    SideMove = true;
                }
                else
                    Sur = make_pair(Sur.first + 1, Sur.second);
                continue;
            }
            if (board[Sur.first][Sur.second + 1] == 1)
            {
                Sur = make_pair(Sur.first, Sur.second + 2);
                SideMove = true;
            }
            else if (board[Sur.first][Sur.second - 1] == 1)
            {
                Sur = make_pair(Sur.first, Sur.second - 2);
                SideMove = true;
            }
            else
                Sur = make_pair(Sur.first + 1, Sur.second);
        }
    }
    if(CheckNum==N) return true;
    return false;
}

bool CheckLadder(int x, int y)
{
    if (y == 1)
    {
        if (board[x][y + 2] == 0)
            return true;
        else
            return false;
    }
    if (y == N * 2 - 3)
    {
        if (board[x][y - 2] == 0)
            return true;
        else
            return false;
    }
    if (board[x][y + 2] == 0 && board[x][y - 2] == 0)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> H;

    for (int i = 0; i < N * 2 - 1; i += 2)
    {
        for (int j = 0; j <= H; j++)
            board[j][i] = 1;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        board[a - 1][2 * b - 1] = 1;
    }

    vector<pair<int, int>> Empty;

    for (int i = 0; i < H; i++){
        for (int j = 1; j < N * 2 - 2; j += 2)
            if (board[i][j] == 0)
                Empty.push_back(make_pair(i, j));
    }

    int CopyBoard[300][25];

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N * 2 - 1; j++)
            CopyBoard[i][j] = board[i][j];
    }
    for (int n = 0; n <= 3; n++)
    {
        vector<int> AddLadder;

        for (int i = 0; i < Empty.size(); i++)
        {
            if (i < Empty.size() - n)
                AddLadder.push_back(0);
            else
                AddLadder.push_back(1);
        }

        do{
            for (int i = 0; i < H; i++){
                for (int j = 0; j < N * 2 - 1; j++) board[i][j] = CopyBoard[i][j];
            }
            bool Check=false;
            for (int i=0;i<AddLadder.size();i++){
                if (AddLadder[i] == 1){
                    if (CheckLadder(Empty[i].first, Empty[i].second)){
                        board[Empty[i].first][Empty[i].second] = 1;
                    }
                    else{
                        Check=true;
                        break;
                    }
                }
            }
            if(Check) continue;
            if (PlayGame()){
                cout << n;
                return 0;
            }
        } while (next_permutation(AddLadder.begin(), AddLadder.end()));
    }

    cout << -1;

    return 0;
}