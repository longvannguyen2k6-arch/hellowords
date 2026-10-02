#include <iostream>
#include <fstream>
using namespace std;
bool check(const int* arr1, const int* arr2, int length) {
    if (arr1 == nullptr || arr2 == nullptr) return false;
    for (int i = 0; i < length; ++i) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}
void swap(void* x, void* y) {
    int* a = static_cast<int*>(x);
    int* b = static_cast<int*>(y);
    int tmp = *a;
    *a = *b;
    *b = tmp;
};
void print_array(int* arr, int width, int height) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::cout << arr[y * width + x] << " ";
        }
        cout << "\n";
    }
};
void print_board(int* board) {
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            int i = y * 3 + x;
            char c = (board[i] == 1) ? 'X'
                : (board[i] == 2) ? 'O'
                : (char)('0' + i);   // show cell number if empty
            cout << " " << c << " ";
            if (x < 2) cout << "|";
        }
        cout << "\n";
        if (y < 2) cout << "---+---+---\n";
    }
}

// Place a piece. Returns false if the move is invalid.
bool make_move(int* board, int pos, int player) {
    if (pos < 0 || pos > 8 || board[pos] != 0) return false;
    board[pos] = player;
    return true;
}

// Returns 1 or 2 if that player has won, otherwise 0.
int check_winner(int* board) {
    int lines[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},   // rows
        {0,3,6}, {1,4,7}, {2,5,8},   // columns
        {0,4,8}, {2,4,6}             // diagonals
    };
    for (int i = 0; i < 8; i++) {
        int a = lines[i][0], b = lines[i][1], c = lines[i][2];
        if (board[a] != 0 && board[a] == board[b] && board[b] == board[c])
            return board[a];
    }
    return 0;
}

// True if every cell is taken (used to detect a draw).
bool is_full(int* board) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) return false;
    }
    return true;
}

int main()
{ 
    cout << "task1\n";
    int n;
    cout << "the value of n is ";
    cin >> n;
    int* ptrton = &n;
    *ptrton += 1;
    cout << "pointer " << *ptrton << endl;;
    int l[3] = { 10,20,2000 };
    cout << "task2\n";
    int*k = &l[3];
    for (int i = 0; i < 3; i++) {
        cout << "value of k is " << *(l+i)
            << " the address of k is " << (k + i) << endl;
    }
    int a[] = { 1,2,3};
    int b[] = { 1,4,9 };
    int c[] = { 1,2,3 };
    cout << "task3\n";
    cout << boolalpha;
    cout << "a and b are the same: " << check(a, b, 3) << endl;
    cout << "a and c are the same: " << check(a, c, 3) << endl;
    cout << "b and c are the same: " << check(b, c, 3) << endl;
    cout << "task4\n";

    ifstream file("foo.txt");
    if (!file) {
        cout << "Khong mo duoc foo.txt\n";
    } else {
        int value, sum = 0;
        while (file >> value) sum += value;
        cout << "Sum = " << sum << "\n";
    }
   cout << "\n";
 
    cout<<"task\n";
    int x = 5, y = 9;
    cout << "Task 5:\nbefore: x=" << x << ", y=" << y << "\n";
    swap(&x, &y);
    cout << "after:  x=" << x << ", y=" << y << "\n\n";
 
    cout<<"task\n";
    int grid[2 * 3] = {1, 2, 3,
                       4, 5, 6};
  cout << "Task 6:\n";
    print_array(grid, 3, 2);
 int board[9] = { 0 };
int player = 1;   // X goes first

while (true) {
    print_board(board);
    cout << "Player " << player << " (" << (player == 1 ? 'X' : 'O')
        << "), choose a cell (0-8): ";

    int pos;
    if (!(cin >> pos)) {              // user typed text instead of a number
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a number from 0 to 8.\n";
        continue;
    }

    if (!make_move(board, pos, player)) {
        cout << "Invalid cell, try again.\n";
        continue;                     // same player tries again
    }

    int winner = check_winner(board);
    if (winner != 0) {
        print_board(board);
        cout << "Player " << winner << " wins!\n";
        break;
    }
    if (is_full(board)) {
        print_board(board);
        cout << "It's a draw!\n";
        break;
    }

    player = (player == 1) ? 2 : 1;   // switch turn
}
}
