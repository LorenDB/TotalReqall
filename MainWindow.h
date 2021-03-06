// SPDX-FileCopyrightText: 2020 Loren Burkholder <computersemiexpert@outlook.com
// SPDX-License-Identifier: BSD-2-Clause

#ifndef MainWindow_H
#define MainWindow_H

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QWidget>
#include <QMainWindow>
#include <QGridLayout>

#include "ChooseReferenceWidget.h"
#include "MemorizeWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	MainWindow(QMainWindow *parent = nullptr);
	~MainWindow();

protected:
	virtual void resizeEvent(QResizeEvent *);

private:
	ChooseReferenceWidget *m_refChooser;
	// when a central widget needs removed but not deleted
	QWidget *m_saveCentralWidget = nullptr;
	QWidget *m_saveFocusWidget = nullptr;
	MemorizeWidget *m_memorizer = nullptr;
    
private slots:
	void runMemorizer(const QString &);
	void cleanUpMemorizer();
	void setStatusMessage(QString);

};
#endif // MainWindow_H
