#ifndef TAGTAB_H
#define TAGTAB_H

#include <QWidget>
#include <QMap>
#include <QCalendarWidget>
#include "textedit.h"
#include "searchtab.h"
#include "page.h"
#include "mainwindow.h"
#include "downloader.h"



namespace Ui
{
	class tagTab;
	class mainWindow;
}



class mainWindow;

class tagTab : public searchTab
{
	Q_OBJECT

	public:
		explicit tagTab(int id, QMap<QString, Site*> *sites, QList<Favorite> favorites, mainWindow *parent);
		~tagTab();
		Ui::tagTab *ui;
		QString tags();
		QString results();
		QString wiki();
		int imagesPerPage();
		int columns();
		QString postFilter();

	public slots:
		void updateCheckboxes();
		// Search
		void firstPage();
		void previousPage();
		void nextPage();
		void lastPage();
		// Zooms
		void setTags(QString);
		void webZoom(int);
		// Loading
		void load();
		void finishedLoading(Page*);
		void failedLoading(Page*);
		void postLoading(Page*);
		void finishedLoadingTags(Page*);
		void finishedLoadingPreview(Image*);
		// Batch
		void getPage();
		void getAll();
		void getSel();
		// Tag list
		void linkHovered(QString);
		void linkClicked(QString);
		void contextMenu();
		void openInNewTab();
		void openInNewWindow();
		void viewitlater();
		void unviewitlater();
		// History
		void historyBack();
		void historyNext();
		// Others
		void optionsChanged();
		void closeEvent(QCloseEvent*);
		void on_buttonSearch_clicked();
		void toggleImage(int, bool);
		void setImagesPerPage(int ipp);
		void setColumns(int columns);
		void setPostFilter(QString postfilter);

	signals:
		void batchAddGroup(QStringList);
		void batchAddUnique(QMap<QString,QString>);

	private:
		int								m_id;
		mainWindow						*m_parent;
		TextEdit						*m_search, *m_postFiltering;
		QCalendarWidget					*m_calendar;
		QList<Favorite>					m_favorites;
		QMap<QString,Page*>				m_pages;
		QList<Image*>					m_images;
		int								m_pagemax;
		QString							m_link, m_lastTags, m_wiki;
		bool							m_sized, m_from_history, m_stop;
		int								m_page, m_history_cursor;
		QList<QGridLayout*>				m_layouts;
		QList<QLabel*>					m_labels;
		QList<QMap<QString,QString> >	m_history;
		QStringList						m_modifiers, m_ignored, m_completion;
		Downloader						*m_downloader;
};

#endif // TAGTAB_H
