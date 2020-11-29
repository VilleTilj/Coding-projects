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

    void test_givePoints_data();
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
    QFETCH(int, points);
    StudentSide::Statistics stats;
    QVERIFY2(stats.giveCurrentPoints() == points, "Points are zero at start");

    QVERIFY2(stats.giveCurrentPoints() + POINTS_FROM_PASSENGER == points, "Points are zero at start");
}

void tst_statistics::test_givePoints_data()
{
    QTest::addColumn<int>("points");
    QTest::newRow("zero") << 0;
    QTest::newRow("after_passenger") << 10;
}

QTEST_MAIN(tst_statistics)

#include "tst_tst_statistics.moc"
