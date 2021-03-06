/********************************************************************************
** Form generated from reading UI file 'TunnelClientUI.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUNNELCLIENTUI_H
#define UI_TUNNELCLIENTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <keplayerplugin.h>

QT_BEGIN_NAMESPACE

class Ui_TunnelClientUI
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    KePlayerPlugin *playPlugin;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_init;
    QLineEdit *edit_peer_id;
    QPushButton *btn_connect;
    QPushButton *btn_disconnect;
    QPushButton *getwifi;
    QGroupBox *groupBox_ptz;
    QGridLayout *gridLayout;
    QPushButton *ptz_left;
    QPushButton *ptz_right;
    QPushButton *ptz_up;
    QPushButton *ptz_down;
    QPushButton *btn_video;
    QPushButton *video2;
    QPushButton *btn_save_video;
    QPushButton *stop_cut;
    QPushButton *btn_stop_video;
    QGroupBox *local;
    QVBoxLayout *verticalLayout_2;
    QPushButton *searchDevice;
    QLineEdit *editAddr;
    QPushButton *connectLocal;
    QPushButton *disconnectLocal;
    QPushButton *startLocalMedia;
    QPushButton *stopLocalMedia;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TunnelClientUI)
    {
        if (TunnelClientUI->objectName().isEmpty())
            TunnelClientUI->setObjectName(QStringLiteral("TunnelClientUI"));
        TunnelClientUI->resize(750, 464);
        TunnelClientUI->setToolButtonStyle(Qt::ToolButtonIconOnly);
        centralwidget = new QWidget(TunnelClientUI);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(400, 300));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        playPlugin = new KePlayerPlugin(groupBox);
        playPlugin->setObjectName(QStringLiteral("playPlugin"));

        horizontalLayout_2->addWidget(playPlugin);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btn_init = new QPushButton(groupBox_2);
        btn_init->setObjectName(QStringLiteral("btn_init"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn_init->sizePolicy().hasHeightForWidth());
        btn_init->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(btn_init);

        edit_peer_id = new QLineEdit(groupBox_2);
        edit_peer_id->setObjectName(QStringLiteral("edit_peer_id"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(edit_peer_id->sizePolicy().hasHeightForWidth());
        edit_peer_id->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(edit_peer_id);

        btn_connect = new QPushButton(groupBox_2);
        btn_connect->setObjectName(QStringLiteral("btn_connect"));
        sizePolicy2.setHeightForWidth(btn_connect->sizePolicy().hasHeightForWidth());
        btn_connect->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(btn_connect);

        btn_disconnect = new QPushButton(groupBox_2);
        btn_disconnect->setObjectName(QStringLiteral("btn_disconnect"));
        sizePolicy2.setHeightForWidth(btn_disconnect->sizePolicy().hasHeightForWidth());
        btn_disconnect->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(btn_disconnect);

        getwifi = new QPushButton(groupBox_2);
        getwifi->setObjectName(QStringLiteral("getwifi"));

        verticalLayout->addWidget(getwifi);

        groupBox_ptz = new QGroupBox(groupBox_2);
        groupBox_ptz->setObjectName(QStringLiteral("groupBox_ptz"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox_ptz->sizePolicy().hasHeightForWidth());
        groupBox_ptz->setSizePolicy(sizePolicy4);
        groupBox_ptz->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(groupBox_ptz);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        ptz_left = new QPushButton(groupBox_ptz);
        ptz_left->setObjectName(QStringLiteral("ptz_left"));

        gridLayout->addWidget(ptz_left, 2, 0, 1, 1);

        ptz_right = new QPushButton(groupBox_ptz);
        ptz_right->setObjectName(QStringLiteral("ptz_right"));

        gridLayout->addWidget(ptz_right, 2, 3, 1, 1);

        ptz_up = new QPushButton(groupBox_ptz);
        ptz_up->setObjectName(QStringLiteral("ptz_up"));

        gridLayout->addWidget(ptz_up, 0, 0, 1, 1);

        ptz_down = new QPushButton(groupBox_ptz);
        ptz_down->setObjectName(QStringLiteral("ptz_down"));

        gridLayout->addWidget(ptz_down, 0, 3, 1, 1);


        verticalLayout->addWidget(groupBox_ptz);

        btn_video = new QPushButton(groupBox_2);
        btn_video->setObjectName(QStringLiteral("btn_video"));
        sizePolicy2.setHeightForWidth(btn_video->sizePolicy().hasHeightForWidth());
        btn_video->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(btn_video);

        video2 = new QPushButton(groupBox_2);
        video2->setObjectName(QStringLiteral("video2"));

        verticalLayout->addWidget(video2);

        btn_save_video = new QPushButton(groupBox_2);
        btn_save_video->setObjectName(QStringLiteral("btn_save_video"));

        verticalLayout->addWidget(btn_save_video);

        stop_cut = new QPushButton(groupBox_2);
        stop_cut->setObjectName(QStringLiteral("stop_cut"));

        verticalLayout->addWidget(stop_cut);

        btn_stop_video = new QPushButton(groupBox_2);
        btn_stop_video->setObjectName(QStringLiteral("btn_stop_video"));

        verticalLayout->addWidget(btn_stop_video);


        horizontalLayout->addWidget(groupBox_2);

        local = new QGroupBox(centralwidget);
        local->setObjectName(QStringLiteral("local"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(local->sizePolicy().hasHeightForWidth());
        local->setSizePolicy(sizePolicy5);
        local->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        verticalLayout_2 = new QVBoxLayout(local);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        searchDevice = new QPushButton(local);
        searchDevice->setObjectName(QStringLiteral("searchDevice"));

        verticalLayout_2->addWidget(searchDevice);

        editAddr = new QLineEdit(local);
        editAddr->setObjectName(QStringLiteral("editAddr"));

        verticalLayout_2->addWidget(editAddr);

        connectLocal = new QPushButton(local);
        connectLocal->setObjectName(QStringLiteral("connectLocal"));

        verticalLayout_2->addWidget(connectLocal);

        disconnectLocal = new QPushButton(local);
        disconnectLocal->setObjectName(QStringLiteral("disconnectLocal"));

        verticalLayout_2->addWidget(disconnectLocal);

        startLocalMedia = new QPushButton(local);
        startLocalMedia->setObjectName(QStringLiteral("startLocalMedia"));

        verticalLayout_2->addWidget(startLocalMedia);

        stopLocalMedia = new QPushButton(local);
        stopLocalMedia->setObjectName(QStringLiteral("stopLocalMedia"));

        verticalLayout_2->addWidget(stopLocalMedia);


        horizontalLayout->addWidget(local);

        TunnelClientUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TunnelClientUI);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 750, 23));
        TunnelClientUI->setMenuBar(menubar);
        statusbar = new QStatusBar(TunnelClientUI);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TunnelClientUI->setStatusBar(statusbar);

        retranslateUi(TunnelClientUI);

        QMetaObject::connectSlotsByName(TunnelClientUI);
    } // setupUi

    void retranslateUi(QMainWindow *TunnelClientUI)
    {
        TunnelClientUI->setWindowTitle(QApplication::translate("TunnelClientUI", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("TunnelClientUI", "VideoWall", 0));
        groupBox_2->setTitle(QApplication::translate("TunnelClientUI", "Control", 0));
        btn_init->setText(QApplication::translate("TunnelClientUI", "Init", 0));
        edit_peer_id->setText(QApplication::translate("TunnelClientUI", "0090B0D41909-10E1", 0));
        btn_connect->setText(QApplication::translate("TunnelClientUI", "ConnectToPeer", 0));
        btn_disconnect->setText(QApplication::translate("TunnelClientUI", "DisConnectToPeer", 0));
        getwifi->setText(QApplication::translate("TunnelClientUI", "get wifi", 0));
        groupBox_ptz->setTitle(QApplication::translate("TunnelClientUI", "PTZ", 0));
        ptz_left->setText(QApplication::translate("TunnelClientUI", "left", 0));
        ptz_right->setText(QApplication::translate("TunnelClientUI", "right", 0));
        ptz_up->setText(QApplication::translate("TunnelClientUI", "up", 0));
        ptz_down->setText(QApplication::translate("TunnelClientUI", "down", 0));
        btn_video->setText(QApplication::translate("TunnelClientUI", "Ask Video", 0));
        video2->setText(QApplication::translate("TunnelClientUI", "ask video 2", 0));
        btn_save_video->setText(QApplication::translate("TunnelClientUI", "save video", 0));
        stop_cut->setText(QApplication::translate("TunnelClientUI", "stop save", 0));
        btn_stop_video->setText(QApplication::translate("TunnelClientUI", "Stop Video", 0));
        local->setTitle(QApplication::translate("TunnelClientUI", "local", 0));
        searchDevice->setText(QApplication::translate("TunnelClientUI", "search device", 0));
        editAddr->setText(QApplication::translate("TunnelClientUI", "192.168.40.192:22616", 0));
        connectLocal->setText(QApplication::translate("TunnelClientUI", "connect local", 0));
        disconnectLocal->setText(QApplication::translate("TunnelClientUI", "disconnect local", 0));
        startLocalMedia->setText(QApplication::translate("TunnelClientUI", "start media", 0));
        stopLocalMedia->setText(QApplication::translate("TunnelClientUI", "stop media", 0));
    } // retranslateUi

};

namespace Ui {
    class TunnelClientUI: public Ui_TunnelClientUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUNNELCLIENTUI_H
