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
#include <QDialogButtonBox>
#include <numeric>
#include "baza.h"

void sigter() {
    qApp->exit();
}


void dialog() {
    QDialog * dialog = new QDialog;
    QFormLayout * forms = new QFormLayout;
    QList<QLineEdit *> fields;
    dialog->setLayout(forms);
    forms->addRow(new QLabel("Wpisz artykuły"));
    for (int i = 0; i < 4; ++i) {
        QLineEdit *lineEdit = new QLineEdit(dialog);
        QString label = QString("Artykuł %1").arg(i + 1);
        forms->addRow(label, lineEdit);

        fields << lineEdit;
    }
// Add some standard buttons at the bottom
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, dialog);
    forms->addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));

// Show the dialog as modal
    if (dialog->exec() == QDialog::Accepted) {
        QVector<QString> objekt;
        QVector<double> objekty;
        // If the user didn't dismiss the dialog, do something with the fields
//                foreach(QLineEdit *lineEdit, fields) {
        for (int i = 0; i < fields.size(); ++i) {
            objekt.push_back(fields[i]->text());
        }
        for (int i = 0; i < objekt.size(); ++i) {
            QString tex = objekt[i];
            if (mama.contains(tex)) {
                objekty.append(mama.value(tex));
            }
        }
        QMessageBox *boxxy = new QMessageBox;
        QString gogogo = QString::number(std::accumulate(objekty.begin(), objekty.end(), 0.0));
        if (objekty.size() == 1) {
            QString nogo = objekt[0];
            boxxy->setText("Znaleziono: 1 \n" + nogo + "\n" + gogogo + " kcal");
            boxxy->exec();
        }
        if (objekty.size() == 2) {
            QString nogo = objekt[0];
            QString nogo2 = objekt[1];
            boxxy->setText("Znaleziono: 2 \n" + nogo + " " + nogo2 + "\n" + gogogo + " kcal");
            boxxy->exec();
        }
        if (objekty.size() == 3) {
            QString nogo = objekt[0];
            QString nogo2 = objekt[1];
            QString nogo3 = objekt[2];
            boxxy->setText("Znaleziono: 3 \n" + nogo + " " + nogo2 + " " + nogo3 + "\n" + gogogo + " kcal");
            boxxy->exec();
        }
        if (objekty.size() == 4) {
            QString nogo = objekt[0];
            QString nogo2 = objekt[1];
            QString nogo3 = objekt[2];
            QString nogo4 = objekt[3];
            boxxy->setText("Znaleziono: 4 \n" + nogo + " " + nogo2 + " " + nogo3 + " " + nogo4 + "\n" + gogogo + " kcal");
            boxxy->exec();
        }
        }
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
    QObject::connect(button, &QPushButton::clicked, button, diag);
    QObject::connect(butt, &QPushButton::clicked, button, dialog);

    window.show();

    return QApplication::exec();
}



