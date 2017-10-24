/**
 * main.cpp
 * Create a chessboard game using Qt
 *
 * @Author: Vishwanath Raman
 *
 */
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include "Box.h"

/**
 * Create the chessboard display containing 64 light and dark tiles
 *
 * @param mainWidget	The pointer to the base Widget
 *
 */
void createPlayers(QWidget *mainWidget)
{
  // Declare and initialize both players' labels
  QLabel *player1 = new QLabel(mainWidget);
  QLabel *name1 = new QLabel("Player 1", mainWidget);

  QLabel *player2 = new QLabel(mainWidget);
  QLabel *name2 = new QLabel("Player 2", mainWidget);

  player1->setGeometry(100,100,100,100);
  name1->setGeometry(125,200,80,20);

  player2->setGeometry(100,500,100,100);
  name2->setGeometry(125,600,80,20);

  // Create a QPixmap object and load an image for both players
  QPixmap pixmap;
  pixmap.load("men_playing_chess.png");
  player1->setPixmap(pixmap);
  player2->setPixmap(pixmap);
}

/**
 * Create the chessboard display containing 64 light and dark tiles
 *
 * @param mainWidget	The pointer to the base Widget
 *
 */
void makeBoard(QWidget *mainWidget)
{  
  QLabel *tempLabel[4] = { NULL };
  
  // Top Border
  tempLabel[0] = new QLabel(mainWidget);
  tempLabel[0]->setGeometry(330 ,105 , 520, 20);
  tempLabel[0]->setStyleSheet("QLabel {background-color :rgb(170,170,127); color:black; }");

  // Bottom Border
  tempLabel[1] = new QLabel(mainWidget);
  tempLabel[1]->setGeometry(330 ,605 , 500, 20);
  tempLabel[1]->setStyleSheet("QLabel {background-color :rgb(170,170,127); color:black; }");

  // Left Border
  tempLabel[2] = new QLabel(mainWidget);
  tempLabel[2]->setGeometry(330 ,125 , 20, 500);
  tempLabel[2]->setStyleSheet("QLabel {background-color :rgb(170,170,127); color:black; }");

  // Right border
  tempLabel[3] = new QLabel(mainWidget);
  tempLabel[3]->setGeometry(830 ,125 , 20, 500);
  tempLabel[3]->setStyleSheet("QLabel {background-color :rgb(170,170,127); color:black; }");

}


/**
 * Create the chessboard display containing 64 light and dark tiles
 *
 * @param mainWidget	The pointer to the base Widget
 * @param tiles		Pointer to the multidimensional array
 *			representing all 64 tiles
 *
 */
void createTiles(QWidget *mainWidget, Box *tiles[8][8])
{
  int hor, ver;
  ver=125;
  for(int i=0;i<8;i++)
  {
    hor=350;
    for(int j=0;j<8;j++)
    {
       // Initialize a tile, whether it is light or dark
       // set its background and geometry
       tiles[i][j] = new Box(mainWidget);
       tiles[i][j]->bgColorFlag = (i+j)%2;
       tiles[i][j]->setBackground();
       tiles[i][j]->setGeometry(hor, ver, 60, 60);
       hor += 60;
    }
    ver += 60;
  }
}

/**
 * Display the different chess pieces on the board
 *
 * @param mainWidget	The pointer to the base Widget
 * @param tiles		Pointer to the multidimensional array
 *			representing all 64 tiles
 *
 */
void displayImages(QWidget *mainWidget, Box *tiles[8][8] )
{
  // Set the white pawns
  for(int i=0; i<8; i++)
  {
    tiles[1][i]->showPiece('1');
    tiles[1][i]->pieceColor = 1;
  }

  // Set the black pawns
  for(int i=0; i<8; i++)
  {
    tiles[6][i]->showPiece('a');
    tiles[1][i]->pieceColor = 0;
  }

  // Set the other white chess pieces
  tiles[0][0]->setChessPiece('2');
  tiles[0][0]->pieceColor = 1;
  tiles[0][1]->setChessPiece('3');
  tiles[0][1]->pieceColor = 1;
  tiles[0][2]->setChessPiece('4');
  tiles[0][2]->pieceColor = 1;
  tiles[0][3]->setChessPiece('5');
  tiles[0][3]->pieceColor = 1;
  tiles[0][4]->setChessPiece('6');
  tiles[0][4]->pieceColor = 1;
  tiles[0][5]->setChessPiece('4');
  tiles[0][5]->pieceColor = 1;
  tiles[0][6]->setChessPiece('3');
  tiles[0][6]->pieceColor = 1;
  tiles[0][7]->setChessPiece('2');
  tiles[0][7]->pieceColor = 1;

  // Set the other black chess pieces
  tiles[7][0]->setChessPiece('b');
  tiles[7][0]->pieceColor = 0;
  tiles[7][1]->setChessPiece('c');
  tiles[7][1]->pieceColor = 0;
  tiles[7][2]->setChessPiece('d');
  tiles[7][2]->pieceColor = 0;
  tiles[7][3]->setChessPiece('e');
  tiles[7][3]->pieceColor = 0;
  tiles[7][4]->setChessPiece('f');
  tiles[7][4]->pieceColor = 0;
  tiles[7][5]->setChessPiece('d');
  tiles[7][5]->pieceColor = 0;
  tiles[7][6]->setChessPiece('c');
  tiles[7][6]->pieceColor = 0;
  tiles[7][7]->setChessPiece('b');
  tiles[7][7]->pieceColor = 0;

}

/**
 * The main function that program execution starts from
 *
 * @param argc	 Command line argument
 * @param *argv  Pointer to command line arguments
 *
 */
int main(int argc, char *argv[])
{
  // Create a Qt Application
  QApplication a(argc, argv);

  // Create a base widget to show the game
  QWidget *myWidgetPointer = new QWidget();
  myWidgetPointer->setGeometry(200,200,1000,700);

  // Initialize the game components
  Box *tile[8][8] = {{NULL}};
  createPlayers(myWidgetPointer);
  makeBoard(myWidgetPointer);
  createTiles(myWidgetPointer, tile);
  displayImages(myWidgetPointer, tile);

  // Make the Widget visible (default is invisible)
  myWidgetPointer->show();

  // Pass on the execution control to Qt Application
  return a.exec();
}
