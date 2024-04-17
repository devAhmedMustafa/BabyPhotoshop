#include <QWidget>
#include <QPaintEvent>
#include <QRect>
#include <QFrame>
#include <QPixmap>
#include <QLabel>


class Window : public QWidget
{
private:
	QString programName = "IAM Filter";

    QString defaultStyle = "";
    QString backgroundUrl = "images/background.png";
    QPixmap backImage = QPixmap(backgroundUrl);
    QLabel background = QLabel(this);

public:

	Window(int x, int y) : QWidget(nullptr) {
		setMinimumSize(x, y);
		setWindowTitle(programName);

		background.setPixmap(backImage);
		background.setGeometry(0, 0, width(), height());
		background.setScaledContents(true);

		setWindowFlags(this->windowFlags() |
			Qt::WindowMinimizeButtonHint |
			Qt::WindowMaximizeButtonHint |
			Qt::Window);

	}

protected:
	void resizeEvent(QResizeEvent* e) override {
		background.setPixmap(backImage);
		background.setGeometry(0, 0, e->size().width(), e->size().height());
	}
};

