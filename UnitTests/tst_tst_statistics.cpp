#include <QtTest>
#include <QCoreApplication>
#include <../Game/statistics.hh>
#include <../Game/actor.hh>


// add necessary includes here

class tst_statistics : public QObject
{
    Q_OBJECT

public:
    tst_statistics();
    ~tst_statistics();

private slots:
    void test_num_of_passengers();

    void test_num_of_passengers_data();

    void test_givePoints();

};

tst_statistics::tst_statistics()
{

}

tst_statistics::~tst_statistics()
{

}



void tst_statistics::test_num_of_passengers()
{
    //QFETCH(int, number);
    QFETCH(int, num);
    StudentSide::Statistics stats;
    QVERIFY2(0 < num, "Number of passenger not zero or negative");
}

void tst_statistics::test_num_of_passengers_data()
{
    QTest::addColumn<int>("num");
    QTest::newRow("num") << 1;
}

void tst_statistics::test_givePoints()
{
    int zeroPoints = 0;
    int passengerPoints = 10;
    StudentSide::Statistics stats;
    QVERIFY2(stats.giveCurrentPoints() == zeroPoints, "Points not zero");
    QVERIFY2(stats.giveCurrentPoints() + POINTS_FROM_PASSENGER  == passengerPoints, "Points after eating one Timo");
}


QTEST_MAIN(tst_statistics)

#include "tst_tst_statistics.moc"
