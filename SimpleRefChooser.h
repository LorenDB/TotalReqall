#ifndef SIMPLEREFCHOOSER_H
#define SIMPLEREFCHOOSER_H

#include <QObject>
#include <QDialog>
#include <QGridLayout>
#include <QComboBox>
#include <QPushButton>

#include "Bible.h"

class SimpleRefChooser : public QDialog
{
	Q_OBJECT
public:
	SimpleRefChooser(QWidget *, const QString &, const QString &, const QString &, const QString &);

	inline QString getBook() { return m_book; }
	inline QString getChapter() { return m_chapter; }
	inline QString getStartVerse() { return m_startVerse; }
	inline QString getEndVerse() { return m_endVerse; }

private slots:
	void updateChapterVerseValues();
	void updateVerseValues();
	void updateEndVerseValues();
	void updateSaveVerse();

private:
	QString m_book;
	QString m_chapter;
	QString m_startVerse;
	QString m_endVerse;

	QGridLayout *m_layout;
	QComboBox *m_books;
	QComboBox *m_chapters;
	QComboBox *m_startVerses;
	QComboBox *m_endVerses;
	QPushButton *m_ok;
	QPushButton *m_cancel;

	Bible *m_bible;
};

#endif // SIMPLEREFCHOOSER_H