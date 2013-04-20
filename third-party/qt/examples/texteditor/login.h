#ifndef TEXTEDITOR_LOGIN_H
#define TEXTEDITOR_LOGIN_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QStringList>
#include <QDebug>
#include <QtGui>

#include <shadow.h>

//class LoginMdiSubWindow : public QMdiSubWindow {
//
//public:
//    LoginMdiSubWindow() : QMdiSubWindow() {}
//
//protected:
//    bool event(QEvent *event);
//};

/*!
 *Makes class LoginDialog a child to its parent, QDialog
 */
class LoginDialog : public QDialog
{
/*!
 *Turns Login Dialog into a QObject
 */
    Q_OBJECT

private:
    /*!
      * A label for the username component.
      */
    QLabel* labelUsername;

    /*!
      * A label for the password.
      */
    QLabel* labelPassword;

    /*!
      * An editable combo box for allowing the user
      * to enter his username or select it from a list.
      */
    QLineEdit* editUsername;

    /*!
      * A field to let the user enters his password.
      */
    QLineEdit* editPassword;

    /*!
      * The standard dialog button box.
      */
    QDialogButtonBox* buttons;

    QLabel *errorLabel;

    /*!
      * A method to set up all dialog components and
      * initialize them.
      */
    void setUpGUI();

public:
    explicit LoginDialog(QWidget *parent = 0);

    QMdiSubWindow *subwindow;
    QGridLayout* formGridLayout;

signals:

    /*!
      * A signal emitted when the login is performed.
      * \param username the username entered in the dialog
      * \param password the password entered in the dialog
      * \param index the number of the username selected in the combobox
      */
    void acceptLogin( QString& username, QString& password, int& indexNumber );

public slots:
    /*!
      * A lot to adjust the emitting of the signal.
      */
    void slotAcceptLogin();
    void close();
};

#endif // TEXTEDITOR_LOGIN_H