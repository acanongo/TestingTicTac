/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/


TEST(TicTacToeBoardTest, unitTestName)
{
  TicTacToeBoard obj;
  bool actual = obj.getWinner();
	ASSERT_FALSE(actual);
}

TEST(TicTacToeBoardTest, unitTest)
{
  TicTacToeBoard obj;
  bool actual = obj.getWinner();
	ASSERT_TRUE(actual);
}



TEST(TicTacToeBoardTest, unitTestPiece)
{
  TicTacToeBoard obj;
  bool actual = obj.getPiece(5,5);
	ASSERT_TRUE(actual);
}



TEST(TicTacToeBoardTest, unitTestPieceF)
{
  TicTacToeBoard obj;
  bool actual = obj.getPiece(5,5);
	ASSERT_FALSE(actual);
}


TEST(TicTacToeBoardTest, unitTestPiecett)
{
  TicTacToeBoard obj;
  bool actual = obj.toggleTurn();
	ASSERT_FALSE(actual);
}



TEST(TicTacToeBoardTest, unitTesttt)
{
  TicTacToeBoard obj;
  bool actual = obj.toggleTurn();
	ASSERT_TRUE(actual);
}
