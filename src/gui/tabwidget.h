#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>

#include "gui/tabbar.h"
#include "gui/tabcontent.h"


class TabWidget : public QTabWidget {
    Q_OBJECT

  public:
    // Constructors and destructors.
    explicit TabWidget(QWidget *parent = 0);
    virtual ~TabWidget();

    // Manimulators for tabs.
    int addTab(TabContent *widget, const QString &,
               const TabBar::TabType &type = TabBar::NonClosable);
    int addTab(TabContent *widget, const QIcon &icon,
               const QString &label, const TabBar::TabType &type = TabBar::NonClosable);
    int insertTab(int index, QWidget *widget, const QString &label,
                  const TabBar::TabType &type = TabBar::Closable);
    int insertTab(int index, QWidget *widget, const QIcon &icon,
                  const QString &label, const TabBar::TabType &type = TabBar::NonClosable);
    void removeTab(int index);

    // Returns tab bar.
    TabBar *tabBar();
    TabContent *widget(int index) const;

    // Initializes TabWidget with tabs, this includes initialization
    // of main "Feeds" widget.
    void initializeTabs();

    // Sets up icons for this TabWidget.
    void setupIcons();

  protected:
    // Creates necesary connections.
    void createConnections();
    
  public slots:
    // Closes tab with given index and deletes contained widget.
    void closeTab(int index);

    // Adds new WebBrowser tab to global TabWidget.
    int addEmptyBrowser();

    // Adds new WebBrowser with link. This is used when user
    // selects to "Open link in new tab.".
    int addLinkedBrowser(const QUrl &initial_url);

    // General method for adding WebBrowsers.
    int addBrowser(bool move_after_current,
                    bool make_active,
                    const QUrl &initial_url = QUrl());
};

#endif // TABWIDGET_H
