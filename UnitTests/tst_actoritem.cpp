/*#include <QtTest>
#include <QCoreApplication>
#include "../Game/actoritem.hh"

class tst_actoritem : public QObject
{
    Q_OBJECT

public:
    tst_actoritem();
    virtual ~tst_actoritem() {};

private slots:
    void test_actoritem1();
    void test_actoritem1_data();

};

tst_actoritem::tst_actoritem()
{

}


void tst_actoritem::test_actoritem1()
{
    QFETCH(int, x);
    QFETCH(int, y);
    QFETCH(int, type);
    QFETCH(int, x_limit);
    QFETCH(int, y_limit);
    QFETCH(int, type_limit);

    //StudentSide::ActorItem a(x,y,type);
    QVERIFY2(0 >= x > x_limit, "X-coordinate not valid");
    QVERIFY2(0 >= y > y_limit, "Y-coordinate not valid");
    QVERIFY2(0 >= type > type_limit, "Type not valid");
}

void tst_actoritem::test_actoritem1_data()
{

    QTest::addColumn<int>("x");
    QTest::addColumn<int>("y");
    QTest::addColumn<int>("type");
    QTest::addColumn<int>("x_limit");
    QTest::addColumn<int>("y_limit");
    QTest::addColumn<int>("type_limit");

    QTest::newRow("location1") << 20 << 20 << 1 << 1100 << 590;
    QTest::newRow("location2") << -20 << 600 << 1 << 1100 << 590;
}
QTEST_MAIN(tst_actoritem);

#include "tst_actoritem.moc"
*/
