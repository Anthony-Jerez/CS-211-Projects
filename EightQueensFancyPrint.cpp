/* Anthony Jerez-Tenecela (Eight Queens Fancy Print Assignment) */
#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
   // returns false if the row and up/down diagonal tests fail
   for (int i = 0; i < c; ++i) {
      if (q[i] == q[c] || abs(q[i] - q[c]) == (c - i)) return false;
   }
   return true;
}

void print(int q[]) {
   static int solution = 0;
   int i, j, k, l;
   typedef char box[5][7];   // box is now a data type: 5x7 2D array of characters
   box bb, wb, *board[8][8]; // bb and wb are boxes (5x7 arrays).  Board is an 8x8 array of pointers to boxes so its elements hold addresses of boxes bb and wb.

   // Fills in bb (black box) and wb (white box). Each represents a square of the chessboard.
   // It's only necessary to create one of each, since the chessboard can contain many pointers to the same box.
   for (i=0; i<5; i++) {
      for (j=0; j<7; j++) {
         wb[i][j] = ' ';
         bb[i][j] = char(219);
      }
   }
   // Creates 2 more boxes to represent the queens, by drawing a picture of each queen in the 2D array.
   static box bq = { {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
                     {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),char(219),char(219),char(219),char(219),char(219),char(219)} };
               
   static box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
                     {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      } };

   // Fills board with pointers to bb and wb in alternate positions.
   for(i=0; i<8; i++) {
      for(j=0; j<8; j++) {
         if((i+j)%2 == 0) {
            board[i][j] = &wb;
         }
         else {
            board[i][j] = &bb;
         }
      }
   }

   // Sets up the current solution's configuration by placing pointers to bq and wq in the appropriate squares.
   // A wq (white queen) is placed in a black square and a bq (black queen) is placed in a white square
   for (int i = 0; i < 8; i++) {
      if ((q[i] + i) % 2 == 0) {
         board[q[i]][i] = &wq;
      }
      else {
         board[q[i]][i] = &bq;
      }
   }
   // Increments the solution count by 1 when a solution is found
   cout << "Solution #" << ++solution << ":\n ";
   
   // Prints upper border of the chessboard
   for (i=0; i<7*8; i++)
      cout << '_';
   cout << "\n";

   // Prints the chessboard so that it matches the current solution's configuration
   for (i=0; i<8; i++)          // for each board row
      for (k=0; k<5; k++) {     // for each box row
         cout << char(179);     // used to print the left border
         for (j=0; j<8; j++)    // for each board column
            for (l=0; l<7; l++) // for each box column
               // board[i][j] is the box pointer in the ith row, jth column of the board.
               // *board[i][j] is the box being pointed to.
               // (*board[i][j])[k][l] is the kth row, lth column of the box.
               cout << (*board[i][j])[k][l];
         cout << char(179) << "\n"; // used to print the right border
      }

   // Prints lower border of the chessboard
   cout << " ";
   for (i=0; i<7*8; i++)
      cout << char(196);
   cout << "\n\n";
}

int main() {
   int q[8] = {}, c = 0;
   q[c] = 0;
   // ends the loop once c backtracks from the first column
   while (c >= 0) { 
      c++;          // moves to the next column        
      if (c > 7) {  // prints the array and backtracks if c exceeds the last column.
         print(q);
         c--;
      }
      else q[c] = -1; // Otherwise, set the row equal to -1 so that in the inner loop we start at the actual first row (q[c] = 0)  
      // ends the loop once c backtracks from the first column
      while (c >= 0) { 
         q[c]++;           // moves to the next row
         if (q[c] > 7) {   // if q[c] exceeds the last row then backtrack
            c--;  
         }
         else if (ok(q,c)) { // Otherwise, call the ok function. If q[c] passes the row and up/down diagonal tests, then we found a queen in the row
            break;
         }           
      }
   }
   return 0;
} 