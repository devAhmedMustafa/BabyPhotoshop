#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class ScrollableContainer : public QWidget {
public:
    QVBoxLayout* container;
    ScrollableContainer(QWidget* parent = nullptr) : QWidget(parent) {
        container = new QVBoxLayout(this);
        setLayout(container);
    }

    void AddChild(QWidget& widget) {
        container->addWidget(&widget);
    }
};