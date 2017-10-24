/home/vraman3/qt-4.8.6/qt-everywhere-opensource-src-4.8.6/bin/qmake -project

sed -i '9i\CONFIG += acxx.prf' ChessQt_board.pro

/home/vraman3/qt-4.8.6/qt-everywhere-opensource-src-4.8.6/bin/qmake ChessQt_board.pro 

make
