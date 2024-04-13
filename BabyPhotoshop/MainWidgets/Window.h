#include <QWidget>
#include <QPaintEvent>
#include <QRect>
#include <QFrame>
#include <QPixmap>
#include <QLabel>

class Window : public QWidget
{
private:
	QString programName = "Baby Photoshop";

    QString defaultStyle = "";
    QString backgroundUrl = "C:\\Users\\am180\\source\\repos\\BabyPhotoshop\\BabyPhotoshop\\MainWidgets\\background.jpg";
    QPixmap backImage = QPixmap(backgroundUrl);
    QLabel background = QLabel(this);

public:

	Window(int x, int y) : QWidget(nullptr) {
		setFixedSize(x, y);
		setWindowTitle(programName);

		background.setPixmap(backImage);
		background.setGeometry(0, 0, width(), height());
	}
};

