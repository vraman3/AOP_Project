/**
 * Box.h
 * Header file for Box.cpp
 *
 * @Author: Vishwanath Raman
 *
 */

#ifndef BOX_H
#define BOX_H
#include <QLabel>

/**
 * Class definition
 *
 */
class Box : public QLabel
{
  // Variables
  public:
  int bgColorFlag;
  char chessPiece;
  int pieceColor;

  // Functions
  Box(QWidget* parent=0, Qt::WindowFlags f=0) : QLabel(parent,f) {};

  Box(const QString& text, QWidget* parent=0, Qt::WindowFlags f=0): QLabel(text,parent,f) {};
  
  void setBackground();
  void mousePressEvent(QMouseEvent *event);
  void setChessPiece(char name);
  void showPiece(char name);
};
#endif // BOX_H
