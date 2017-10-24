/**
 * Box.cpp
 * Class to depict each light or dark square on the
 * chessboard
 *
 * @Author: Vishwanath Raman
 *
 */
#include "Box.h"
#include<iostream>

/**
 * Set the background for a tile
 *
 */
void Box::setBackground()
{
  if(this->bgColorFlag)
    this->setStyleSheet("QLabel {background-color: rgb(120,120,90);}:hover{background-color: rgb(170,85,127);}");
  else
    this->setStyleSheet("QLabel {background-color: rgb(211,211,158);}:hover{background-color: rgb(170,95,127);}");
}

/**
 * Catch a mouse press event
 *
 * @param event	  Pointer to the Mouse event that just happened
 *
 */
void Box::mousePressEvent(QMouseEvent *event)
{
    this->setStyleSheet("QLabel {background-color: green;}");
}

/**
 * Set the type of a chess piece (e.g. Pawn, Rook, ...)
 *
 * @param name	  Name to denote the type of chess piece
 *
 */
void Box::setChessPiece(char name)
{
  this->chessPiece = name;
  this->showPiece(name);
}

/**
 * Load the image for the corresponding type of 
 * chess piece (e.g. Pawn, Rook, ...)
 *
 * @param name	  Name to denote the type of chess piece
 *
 */
void Box::showPiece(char name)
{
 switch(name)
 {
    case '1': this->setPixmap(QPixmap("white_pawn.png"));   break;
    case '2': this->setPixmap(QPixmap("white_rook.png"));   break;
    case '3': this->setPixmap(QPixmap("white_knight.png")); break;
    case '4': this->setPixmap(QPixmap("white_bishop.png")); break;
    case '5': this->setPixmap(QPixmap("white_king.png"));   break;
    case '6': this->setPixmap(QPixmap("white_queen.png"));  break;

    case 'a': this->setPixmap(QPixmap("black_pawn.png"));   break;
    case 'b': this->setPixmap(QPixmap("black_rook.png"));   break;
    case 'c': this->setPixmap(QPixmap("black_knight.png")); break;
    case 'd': this->setPixmap(QPixmap("black_bishop.png")); break;
    case 'e': this->setPixmap(QPixmap("black_king.png"));   break;
    case 'f': this->setPixmap(QPixmap("black_queen.png"));  break;
    case 'x': this->setBackground();			    break;
    default:  std::cout<<"wrong piece name";		    break;
 }
}

