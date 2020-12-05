#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == 'X')
     turn = X;

    turn = O;

    return turn;


}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location.
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/
Piece TicTacToeBoard::placePiece(int row, int column)
{
  //check if board is full
  int count = 0;
  for(int i =0; i <row; i++)
  {
    for(int j =0; j <column; j++)
    {
      if(board[row][column]!= ' ')
      {
        count++;
      }
    }
  }
  //board is full
  if(count == row * column)
  {
    return Invalid;
  }
  if(row > 2 || column >2)
  {
    return Invalid;
  }

  if(board[row][column] == ' ')
  {
    board[row][column] = turn;
    //update the turn
    toggleTurn();
    return turn;
  }

  //the next two if mean cell is take already, return the value of that cell
  if(board[row][column] == 'X')
  {
    board[row][column] = turn;
    return X;

  }
  if(board[row][column] == 'O')
  {
    board[row][column] = turn;
    return O;
  }

  //else at this stage the cell requested is taken alread
  return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(row > 2 || column >2)
  {
    return Invalid;
  }
  if(board[row][column] == Blank)
  {
    return Blank;
  }
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{

  //cannot have a turn when theres a winner so return the previos turn

  if(turn == 'X')
    return O;

  return X;
}
