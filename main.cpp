#include <QApplication>
#include <QObject>
#include <QString>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <QStyleFactory>
#include <QStyle>
#include <QPalette>
#include <QInputDialog>
#include <QMessageBox>
#include <QFormLayout>
#include "baza.h"

void sigter() {
    qApp->exit();
}


void dialog() {
    QDialog *dialog = new QDialog;
    QFormLayout *forms = new QFormLayout;
    QList<QLineEdit *> fields;
    dialog->setLayout(forms);
    forms->addRow(new QLabel("Wpisz artykuły"));
    for(int i = 0; i < 4; ++i) {
        QLineEdit *lineEdit = new QLineEdit(dialog);
        QString label = QString("Artykuł %1").arg(i + 1);
        forms->addRow(label, lineEdit);
        fields << lineEdit;
    }
    QPushButton *but = new QPushButton;
    but->setText("OK");
    forms->addWidget(but);
    dialog->exec();
}

void diag() {
    bool ok;
    QString text = QInputDialog::getText(nullptr, "Tabela", "Wpisz nazwę szukanego produktu", QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty()) {
        if (mama.contains(text)) {
            double resultes = mama.value(text);
            QString gogo = QString::number(resultes) + " kcal w 100 g";
            QMessageBox msgBox;
            msgBox.setText(gogo);
            msgBox.exec();
            if (msgBox.clickedButton()) {
                diag();
            }
        }
    }
}


int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    QFont f("Arial", 20, QFont::Bold);
    // Theme
    QStyle* style = QStyleFactory::create("Fusion");
    QPalette palette = style->standardPalette();
    QApplication::setStyle(style);
    QApplication::setPalette(palette);
//okno
    QWidget window;
    window.setWindowTitle("Kalorie");
    window.setMinimumSize(400, 200);
//layout
    QVBoxLayout *layout = new QVBoxLayout(&window);
//tekst
    QLabel *label = new QLabel("Wyszukaj w tabeli kalorii");
    label->setMinimumSize(100, 100);
    label->setFont(f);
    layout->addWidget(label,0,  Qt::AlignCenter);

//wprowadzanie tekstu
//    QLineEdit *lineEdit = new QLineEdit();
//    layout->addWidget(lineEdit);
//button
    QPushButton *button = new QPushButton();
    QPushButton *buton = new QPushButton();
    QPushButton *butt = new QPushButton();
    button->setText("Sprawdź artykuł");
    layout->addWidget(button);
    butt->setText("Sprawdź posiłek");
    layout->addWidget(butt);
    buton->setText("Zamknij");
    layout->addWidget(buton);
    QObject::connect(buton, &QPushButton::clicked, buton, sigter);
    //testdebug
    QObject::connect(button, &QPushButton::clicked, button, diag);
    QObject::connect(butt, &QPushButton::clicked, button, dialog);

    window.show();

    return QApplication::exec();
}



