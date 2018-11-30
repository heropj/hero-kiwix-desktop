#ifndef SEARCHBAR_H
#define SEARCHBAR_H

#include <QLineEdit>
#include <QStringListModel>
#include <QCompleter>
#include <QIcon>
#include <QPushButton>

class SearchButton : public QPushButton {
    Q_OBJECT
public:
    SearchButton(QWidget *parent = nullptr);

public slots:
    void set_searchMode(bool searchMode);
protected:
    bool m_searchMode;
};

class SearchBar : public QLineEdit
{
    Q_OBJECT
public:
    SearchBar(QWidget *parent = nullptr);

protected:
    virtual void focusInEvent(QFocusEvent *);
private:
    QStringListModel m_completionModel;
    QCompleter m_completer;
    std::vector<std::string> m_urlList;
    QString m_currentHost;
    SearchButton m_button;

private slots:
    void updateCompletion(const QString& text);
    void openCompletion(const QModelIndex& index);
    void openTitle();
};

#endif // SEARCHBAR_H
