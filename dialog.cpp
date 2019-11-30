#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::init()
{
    for (int row = 0;row < 10;row++)
    {
        QStandardItem *rowitem = new QStandardItem(QString("Item %0").arg(row));
        QList<QStandardItem*> items;
        for (int col = 0;col < 5;col++)
        {
            items.append(new QStandardItem(QString("Col %0").arg(col)));
        }
        rowitem->appendRows(items);
        model.appendRow(rowitem);
    }

    ui->treeView->setModel(&model);
    ui->listView->setModel(&model);
    ui->tableView->setModel(&model);
}

