#include "ChooseReferenceWidget.h"

#include <QSettings>
#include <QDebug>
#include <QLabel>

ChooseReferenceWidget::ChooseReferenceWidget(QWidget *parent)
    : QWidget(parent),
      m_layout{ new QGridLayout{ this } },
      m_books{ new QComboBox },
      m_chapters{ new QComboBox },
      m_startVerses{ new QComboBox },
      m_endVerses{ new QComboBox },
      m_runMemorizerBtn{ new QPushButton },
      m_displayVerseBtn{ new QPushButton },
      m_verseDisplayBox{ new QTextEdit{ "" } },
      m_bible{ new Bible }
{
	// set up the first combo box manually and scrape the other 2
	// maybe the books could be scraped as well but this way seems easier ATM
	// TODO: add tr() to each of these
	m_bookList << "Genesis" << "Exodus" << "Leviticus" << "Numbers" << "Deuteronomy"
	      << "Joshua" << "Judges" << "Ruth" << "1 Samuel" << "2 Samuel"
	      << "1 Kings" << "2 Kings" << "1 Chronicles" << "2 Chronicles" << "Ezra"
	      << "Nehemiah" << "Esther" << "Job" << "Psalms" << "Proverbs"
	      << "Ecclesiastes" << "Song of Solomon" << "Isaiah" << "Jeremiah"
	      << "Lamentations" << "Ezekiel" << "Daniel" << "Hosea" << "Joel" << "Amos"
	      << "Obadiah" << "Jonah" << "Micah" << "Nahum" << "Habakkuk"
	      << "Zephaniah" << "Haggai" << "Zechariah" << "Malachi" << "Matthew"
	      << "Mark" << "Luke" << "John" << "Acts" << "Romans" << "1 Corinthians"
	      << "2 Corinthians" << "Galatians" << "Ephesians" << "Philippians"
	      << "Colossians" << "1 Thessalonians" << "2 Thessalonians" << "1 Timothy"
	      << "2 Timothy" << "Titus" << "Philemon" << "Hebrews" << "James"
	      << "1 Peter" << "2 Peter" << "1 John" << "2 John" << "3 John" << "Jude"
	      << "Revelation";
	m_books->insertItems(0, m_bookList);

	// connect the combos
	connect(m_books, SIGNAL(currentIndexChanged(int)), this, SLOT(updateChapterVerseValues()));
	connect(m_chapters, SIGNAL(currentIndexChanged(int)), this, SLOT(updateVerseValues()));
	connect(m_startVerses, SIGNAL(currentIndexChanged(int)), this, SLOT(updateEndVerseValues()));
	connect(m_endVerses, SIGNAL(currentIndexChanged(int)), this, SLOT(updateEndVerseValues()));


	QSettings settings;
	auto lastBook = settings.value("ChooseReferenceWidget/lastBook").toString();
	auto lastChapter = settings.value("ChooseReferenceWidget/lastChapter").toString();
	auto lastStartVerse = settings.value("ChooseReferenceWidget/lastStartVerse").toString();
	auto lastEndVerse = settings.value("ChooseReferenceWidget/lastEndVerse").toString();

	if (lastBook != "" && lastChapter != "" && lastStartVerse != "" && lastEndVerse != "")
	{
		m_books->setCurrentText(lastBook);
		m_chapters->setCurrentText(lastChapter);
		m_startVerses->setCurrentText(lastStartVerse);
		m_endVerses->setCurrentText(lastEndVerse);
	}
	else
	{
		updateSaveVerse();
	}
	updateChapterVerseValues();

	// we also need to save all info about the last verse
	connect(m_books, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSaveVerse()));
	connect(m_chapters, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSaveVerse()));
	connect(m_startVerses, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSaveVerse()));
	connect(m_endVerses, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSaveVerse()));

	m_books->setWhatsThis(tr("Use this to choose a book of the Bible."));
	m_chapters->setWhatsThis(tr("Use this to choose a chapter."));
	m_startVerses->setWhatsThis(tr("Use this to choose a verse."));
	m_runMemorizerBtn->setWhatsThis(tr("Starts memorizing the selected verse."));
	m_displayVerseBtn->setWhatsThis(tr("Displays the selected verse"));

	// ... and make sure that the combo boxes don't display ellipses (try removing this and then
	// viewing the chapters for Psalms if you think this is unnecessary!)
	m_chapters->setSizeAdjustPolicy(QComboBox::AdjustToContents);
	m_startVerses->setSizeAdjustPolicy(QComboBox::AdjustToContents);

	m_runMemorizerBtn->setText(tr("Memorize verse"));
	connect(m_runMemorizerBtn, &QPushButton::clicked, this, &ChooseReferenceWidget::runMemorizer);

	m_displayVerseBtn->setText(tr("Display verse"));
	connect(m_displayVerseBtn, &QPushButton::clicked, this, &ChooseReferenceWidget::displayVerse);

	m_verseDisplayBox->setReadOnly(true);

	auto colon = new QLabel{ ":" };
	colon->setAlignment(Qt::AlignHCenter);
	auto dash = new QLabel{ "-" };
	dash->setAlignment(Qt::AlignHCenter);

	// set up the layout
	m_layout->addWidget(m_books, 0, 0);
	m_layout->addWidget(m_chapters, 0, 1);
	m_layout->addWidget(colon, 0, 2);
	m_layout->addWidget(m_startVerses, 0, 3);
	m_layout->addWidget(dash, 0, 4);
	m_layout->addWidget(m_endVerses, 0, 5);
	m_layout->addWidget(m_runMemorizerBtn, 1, 0);
	m_layout->addWidget(m_displayVerseBtn, 1, 1);
	m_layout->addWidget(m_verseDisplayBox, 2, 0, 1, 6);

	this->setLayout(m_layout);
}

void ChooseReferenceWidget::updateChapterVerseValues()
{
	// prevent lots of signals from being emitted
	disconnect(m_chapters, SIGNAL(currentIndexChanged(int)), this, SLOT(updateVerseValues()));
	disconnect(m_chapters, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSaveVerse()));

	// first take care of the chapter
	// get data to insert
	int chapters = m_bible->scrapeChaptersPerBook(m_books->currentText());

	// make sure that we do not set the current index to -1, use the first item instead
	auto old = (m_chapters->currentIndex() == -1) ? 0 : m_chapters->currentIndex();

	// remove existing items
	m_chapters->clear();

	// insert the new data
	QStringList chapList;
	for (int i = 0; i < chapters; ++i)
	{
		QString temp{ "%1" };
		temp = temp.arg(i + 1);
		chapList.push_back(temp); // + 1 to ensure that we insert at the end
	}
	m_chapters->insertItems(0, chapList);

	// this triggers a call to updateVerseValues()
	if ((m_chapters->count() - 1) >= old)
		m_chapters->setCurrentIndex(old);
	else // use the closest thing to the old index that we have
		m_chapters->setCurrentIndex(m_chapters->count() - 1);

	updateVerseValues();
	updateSaveVerse();

	// reconnect the signals
	connect(m_chapters, SIGNAL(currentIndexChanged(int)), this, SLOT(updateVerseValues()));
	connect(m_chapters, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSaveVerse()));
}

void ChooseReferenceWidget::updateVerseValues()
{
	// prevent lots of signals from being emitted
	disconnect(m_startVerses, SIGNAL(currentIndexChanged(int)), this, SLOT(updateEndVerseValues()));
	disconnect(m_endVerses, SIGNAL(currentIndexChanged(int)), this, SLOT(updateEndVerseValues()));
	disconnect(m_startVerses, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSaveVerse()));
	disconnect(m_endVerses, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSaveVerse()));

	// get data to insert
	int verses = m_bible->scrapeVersesPerChapter(m_books->currentText(), m_chapters->currentText());

	// make sure that we do not set the current index to -1, use the first item instead
	auto oldStart = (m_startVerses->currentIndex() == -1) ? 0 : m_startVerses->currentIndex();
	auto oldEnd = (m_endVerses->currentIndex() == -1) ? 0 : m_endVerses->currentIndex();

	// remove existing items
	m_startVerses->clear();
	m_endVerses->clear();

	// insert the new data
	QStringList startVerseList;
	QStringList endVerseList;
	for (int i = 0; i < verses; ++i)
	{
		QString temp{ "%1" };
		temp = temp.arg(i + 1);
		startVerseList.push_back(temp);
		endVerseList.push_back(temp);
	}
	m_startVerses->insertItems(0, startVerseList);
	m_endVerses->insertItems(0, endVerseList);

	// make sure that the old index is still valid
	// - 1 because count isn't zero numbered but the index is
	if ((m_startVerses->count() - 1) >= oldStart)
		m_startVerses->setCurrentIndex(oldStart);
	else // use the closest thing to the old index that we have
		m_startVerses->setCurrentIndex(m_startVerses->count() - 1);

	if ((m_endVerses->count() - 1) >= oldEnd)
		m_endVerses->setCurrentIndex(oldEnd);
	else
		m_endVerses->setCurrentIndex(m_endVerses->count() - 1);

	// make sure that m_endVerses has a proper index
	updateEndVerseValues();

	updateSaveVerse();

	// reconnect the signals
	connect(m_startVerses, SIGNAL(currentIndexChanged(int)), this, SLOT(updateEndVerseValues()));
	connect(m_endVerses, SIGNAL(currentIndexChanged(int)), this, SLOT(updateEndVerseValues()));
	connect(m_startVerses, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSaveVerse()));
	connect(m_endVerses, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSaveVerse()));
}

void ChooseReferenceWidget::updateEndVerseValues()
{
	// prevent lots of signals from being emitted
	disconnect(m_endVerses, SIGNAL(currentIndexChanged(int)), this, SLOT(updateEndVerseValues()));
	disconnect(m_endVerses, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSaveVerse()));

	if (m_startVerses->currentIndex() > m_endVerses->currentIndex())
		m_endVerses->setCurrentIndex(m_startVerses->currentIndex());

	updateSaveVerse();

	// reconnect the signals
	connect(m_endVerses, SIGNAL(currentIndexChanged(int)), this, SLOT(updateEndVerseValues()));
	connect(m_endVerses, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSaveVerse()));
}

void ChooseReferenceWidget::updateSaveVerse()
{
	QSettings settings;
	settings.setValue("ChooseReferenceWidget/lastBook", m_books->currentText());
	settings.setValue("ChooseReferenceWidget/lastChapter", m_chapters->currentText());
	settings.setValue("ChooseReferenceWidget/lastStartVerse", m_startVerses->currentText());
	settings.setValue("ChooseReferenceWidget/lastEndVerse", m_endVerses->currentText());
}

void ChooseReferenceWidget::setUpBible()
{
	m_bible->readData();
}

void ChooseReferenceWidget::freeBible()
{
	m_bible->freeData();
}

void ChooseReferenceWidget::runMemorizer()
{
	QString reference{ "%1 %2:%3" };
	int extraVerses = (m_endVerses->currentIndex() > m_startVerses->currentIndex()) ? (m_endVerses->currentIndex() - m_startVerses->currentIndex()) : 0;
	reference = reference.arg(m_books->currentText(), m_chapters->currentText(), m_startVerses->currentText());
	emit signalRunMemorizer(m_bible->getVerseStringFromRef(reference, extraVerses));
}

void ChooseReferenceWidget::displayVerse()
{
	QString reference{ "%1 %2:%3" };
	reference = reference.arg(m_books->currentText(), m_chapters->currentText(), m_startVerses->currentText());
	int extraVerses = (m_endVerses->currentIndex() > m_startVerses->currentIndex()) ? (m_endVerses->currentIndex() - m_startVerses->currentIndex()) : 0;
	m_verseDisplayBox->setText(m_bible->getVerseStringFromRef(reference, extraVerses));
}
