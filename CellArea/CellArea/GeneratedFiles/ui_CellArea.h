/********************************************************************************
** Form generated from reading UI file 'CellArea.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CELLAREA_H
#define UI_CELLAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "imageview.h"

QT_BEGIN_NAMESPACE

class Ui_CellArea
{
public:
    QAction *actionLoadImage;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    ImageView *imageView;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonSaveCroppedImage;
    QPushButton *pushButtonSaveCroppedImageMask;
    QFrame *line_2;
    QFrame *line;
    QLabel *messageShow;
    QMenuBar *menuBar;
    QMenu *menu_File;

    void setupUi(QMainWindow *CellArea)
    {
        if (CellArea->objectName().isEmpty())
            CellArea->setObjectName(QStringLiteral("CellArea"));
        CellArea->resize(1126, 829);
        actionLoadImage = new QAction(CellArea);
        actionLoadImage->setObjectName(QStringLiteral("actionLoadImage"));
        centralWidget = new QWidget(CellArea);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(1, 1, 1, 1);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        imageView = new ImageView(centralWidget);
        imageView->setObjectName(QStringLiteral("imageView"));

        horizontalLayout->addWidget(imageView);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(3, 3, 3, 3);
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButtonSaveCroppedImage = new QPushButton(groupBox);
        pushButtonSaveCroppedImage->setObjectName(QStringLiteral("pushButtonSaveCroppedImage"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonSaveCroppedImage->sizePolicy().hasHeightForWidth());
        pushButtonSaveCroppedImage->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(pushButtonSaveCroppedImage);

        pushButtonSaveCroppedImageMask = new QPushButton(groupBox);
        pushButtonSaveCroppedImageMask->setObjectName(QStringLiteral("pushButtonSaveCroppedImageMask"));
        sizePolicy.setHeightForWidth(pushButtonSaveCroppedImageMask->sizePolicy().hasHeightForWidth());
        pushButtonSaveCroppedImageMask->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(pushButtonSaveCroppedImageMask);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        sizePolicy.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 4);

        verticalLayout->addWidget(groupBox);

        line = new QFrame(frame);
        line->setObjectName(QStringLiteral("line"));
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 2);

        horizontalLayout->addWidget(frame);

        horizontalLayout->setStretch(0, 6);
        horizontalLayout->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout);

        messageShow = new QLabel(centralWidget);
        messageShow->setObjectName(QStringLiteral("messageShow"));
        messageShow->setStyleSheet(QStringLiteral("font: 12pt \"Times New Roman\";"));

        verticalLayout_3->addWidget(messageShow);

        verticalLayout_3->setStretch(0, 30);
        verticalLayout_3->setStretch(1, 1);

        horizontalLayout_2->addLayout(verticalLayout_3);

        CellArea->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CellArea);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1126, 23));
        menuBar->setFocusPolicy(Qt::ClickFocus);
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_File->setFocusPolicy(Qt::ClickFocus);
        CellArea->setMenuBar(menuBar);

        menuBar->addAction(menu_File->menuAction());
        menu_File->addAction(actionLoadImage);

        retranslateUi(CellArea);

        QMetaObject::connectSlotsByName(CellArea);
    } // setupUi

    void retranslateUi(QMainWindow *CellArea)
    {
        CellArea->setWindowTitle(QApplication::translate("CellArea", "CellArea", Q_NULLPTR));
        actionLoadImage->setText(QApplication::translate("CellArea", "Load", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("CellArea", "Save", Q_NULLPTR));
        pushButtonSaveCroppedImage->setText(QApplication::translate("CellArea", "SaveCroppedImage", Q_NULLPTR));
        pushButtonSaveCroppedImageMask->setText(QApplication::translate("CellArea", "SaveCroppedImageMask", Q_NULLPTR));
        messageShow->setText(QString());
#ifndef QT_NO_TOOLTIP
        menu_File->setToolTip(QApplication::translate("CellArea", "Load Image", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        menu_File->setTitle(QApplication::translate("CellArea", " File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CellArea: public Ui_CellArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CELLAREA_H
