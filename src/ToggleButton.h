#include <QPushButton>
#include <QAbstractButton>
#include <QStyleOptionButton>
#include <QPainter>
#include <libssh/libssh.h>
#include "GPIO.h"

class ToggleButton : public QPushButton
{
    Q_OBJECT


public:
    ToggleButton(QWidget * parent = 0) : QPushButton (parent)
    {
        setStyleSheet("QPushButton { background-color: grey; }" "QPushButton:checked { background-color: green; }");
    }
    ToggleButton(const QString &text, QWidget *parent = 0) : QPushButton(text, parent) 
    { 
        this->setCheckable(true);
        setStyleSheet("QPushButton { background-color: grey; }"
                      "QPushButton:checked { background-color: green; }");
        this->setMinimumSize(40,5);
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }

    // void paintEvent(QPaintEvent* event)
    // {
    //     QStyleOptionButton option;
    //     option.initFrom(this);
    //     option.features |= QStyleOptionButton::Flat;
    //     option.text = text();
    //     option.icon = icon();
    //     option.iconSize = iconSize();
    //     QPainter painter(this);
    //     style()->drawControl(QStyle::CE_PushButton, &option, &painter, this);
    // }


public slots: 
    void did_toggle(bool checked) {
        // creating a universal GPIOClass object
        QString setgpio = this->text().mid(4, 2);
        GPIOClass gpio_x = GPIOClass(setgpio);

        // Initialize ssh session, as defined below
        ssh_session sshSesh = sshSesh_init();

        if (checked) { 
            this->setStyleSheet("background-color: green;");
            gpio_x.export_gpio_ssh(sshSesh);
            gpio_x.setdir_gpio("out", sshSesh);
            gpio_x.setval_gpio("1", sshSesh);

        }
        else { 
            this->setStyleSheet("background-color: grey;");
            gpio_x.unexport_gpio(sshSesh);
        }
    }

    private:
    ssh_session sshSesh_init(){
    // initialize SSH sesh
    ssh_session sshSession = ssh_new();
    if (sshSession == NULL)
    {
        fprintf(stderr, "Failed to create SSH session.\n");
        // return 1;
    }

    // Set SSH options (hostname, username, password, etc.)
    ssh_options_set(sshSession, SSH_OPTIONS_HOST, "<IP ADDR>");                      // Raspberry Pi IP address
    ssh_options_set(sshSession, SSH_OPTIONS_USER, "<HOSTNAME>");                     // username
    ssh_options_set(sshSession, SSH_OPTIONS_IDENTITY, "</path/to/rsa/priv-key>");    // path/to/priv key

    // Connect to the SSH server
    int rc = ssh_connect(sshSession);
    if (rc != SSH_OK)
    {
        fprintf(stderr, "Failed to connect: %s\n", ssh_get_error(sshSession));
        ssh_free(sshSession);
        // return 1;
    }

    // Authenticate
    rc = ssh_userauth_password(sshSession, NULL, "<PASSWORD>"); // In the future, replace this with RSA key authentication
    if (rc != SSH_AUTH_SUCCESS)
    {
        fprintf(stderr, "Authentication failed: %s\n", ssh_get_error(sshSession));
        ssh_disconnect(sshSession);
        ssh_free(sshSession);
        // return 1;
    }
    
    return sshSession;
}

};