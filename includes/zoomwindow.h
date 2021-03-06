#ifndef HEADER_ZOOMWINDOW
#define HEADER_ZOOMWINDOW

#include <QtGui>
#include <QtNetwork>
#include <QStackedWidget>
#include "QAffiche.h"
#include "image.h"
#include "mainwindow.h"
#include "detailswindow.h"
#include "imagethread.h"

#include <QVideoWidget>
#include <QVideoSurfaceFormat>
#include <QMediaPlayer>



namespace Ui
{
	class zoomWindow;
}



class zoomWindow : public QDialog
{
	Q_OBJECT

	public:
        zoomWindow(Image *image, Site *site, QMap<QString,Site*> *sites, QWidget *parent = 0);
		void go();
		~zoomWindow();
		void load();

	public slots:
		void update(bool onlysize = false);
		void replyFinished(Image*);
		void replyFinishedZoom();
		void display(QImage, int);
		void saveNQuit();
		void saveNQuitFav();
		QStringList saveImage(bool fav = false);
		QStringList saveImageFav();
		QString saveImageAs();
		void fullScreen();
		void unfullScreen();
		void openUrl(QString);
		void openPool(QString);
		void openPoolId(Page*);
		void openSaveDir(bool fav = false);
		void openSaveDirFav();
		void linkHovered(QString);
		void contextMenu(QPoint);
		void openInNewTab();
		void openInNewWindow();
		void openInBrowser();
		void favorite();
		void setfavorite();
		void unfavorite();
		void viewitlater();
		void unviewitlater();
		void ignore();
		void unignore();
        void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
		void colore();
		void sslErrorHandler(QNetworkReply*, QList<QSslError>);
		void urlChanged(QString, QString);
		void showDetails();

	protected:
		void closeEvent(QCloseEvent *);
		void resizeEvent(QResizeEvent *);
		void save(QString, QPushButton *);
		void draw();

	signals:
		void linkClicked(QString);
		void poolClicked(int, QString);
		void linkMiddleClicked(QString);

	private:
		mainWindow *m_parent;
		Ui::zoomWindow *ui;
        detailsWindow *m_detailsWindow;
        Image *m_image;
		QMap<QString,QString> regex, m_details;
		Site *m_site;
		int timeout, m_loaded, oldsize, m_mustSave;
		QString id, m_url, tags, rating, score, user, format;
		QAffiche *m_labelTagsTop, *m_labelTagsLeft;
		QPixmap *image;
		QMovie *movie;
		QTimer *m_resizeTimer;
        QTime *m_imageTime;
		QPushButton *buttonSave, *buttonSaveNQuit, *buttonSaveas, *m_buttonSaveNQuit;
		QString link, m_program;
		QNetworkReply *m_reply;
		const char* m_format;
		bool m_finished, m_thread;
		QStringList m_favorites, m_viewItLater, m_ignore;
		QByteArray m_data;
		int m_size;
		QMap<QString,Site*> *m_sites;
		QString m_source;
		ImageThread *m_th;
		QAffiche *m_fullScreen;

		QStackedWidget *m_stackedWidget;
		QAffiche *m_labelImage;
		QVideoWidget *m_videoWidget;
		QMediaPlayer *m_mediaPlayer;
};

#endif
