#include <QWidget>
#include <QPaintEvent>
#include <QRect>

class Window : public QWidget
{
private:
	QString programName = "Baby Photoshop";
	QString defaultStyle = "\
		background-color: rgb(230, 230, 230);\
	";

public:
	Window(int, int);
};

