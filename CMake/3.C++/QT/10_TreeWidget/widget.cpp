#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置头部标签
    ui->treeWidget->setHeaderLabels(QStringList() << "地区"<< "面积(平方千米)");

    //设置顶级项目
    QTreeWidgetItem * treeItem1 = new QTreeWidgetItem(QStringList() << "北京" << "16418");
    QTreeWidgetItem * treeItem2 = new QTreeWidgetItem(QStringList() << "天津" << "11967");

    ui->treeWidget->addTopLevelItem(treeItem1);
    ui->treeWidget->addTopLevelItem(treeItem2);

    //设置北京下具体城区的数值
    QStringList districtList; //地区列表
    QStringList squareList;   //面积列表
    districtList << "东城" << "西城" << "朝阳" << "丰台" << "石景山" << "海淀"
                 << "门头沟" << "房山" << "通州" << "顺义" << "昌平" << "大兴"
                 << "怀柔" << "平谷"<<"密云" << "延庆";
    squareList << "42" << "51" << "465" << "306" << "84" << "431" << "1448"
               << "1995" << "906" << "1020" << "1342" << "1036" << "2123"
               << "948" << "2226" << "1995";

    //通过循环将每个城区的数值 放入到 北京item下
    for(int i = 0 ; i< districtList.size();i++)
    {
        QStringList colList;
        QTreeWidgetItem * childItem;
        colList << districtList.at(i)  << squareList.at(i);
        childItem = new QTreeWidgetItem(colList);
        treeItem1->addChild(childItem);
    }

}

Widget::~Widget()
{
    delete ui;
}
