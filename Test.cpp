#include "doctest.h"
#include <cmath>
#include "sources/Team.hpp"

#include "sources/Cowboy.hpp"
#include "sources/Ninja.hpp"
#include "sources/Point.hpp"

TEST_CASE("creating characters")
{
    Point a(32.3, 44), b(1.3, 3.5);
    CHECK_NOTHROW(new Cowboy("Hagay", a));
    CHECK_NOTHROW(new OldNinja("Ella", b));
    CHECK_NOTHROW(new YoungNinja("Yogi", Point(1, 1)));
    CHECK_NOTHROW(new TrainedNinja("Shmulik", Point(2, 2)));
    CHECK_NOTHROW(new Ninja("Young", Point(4, 4), 100, 25));
}

TEST_CASE("Characters functions")
{
    Point a(32.3, 44), b(1.3, 3.5);
    Cowboy Hagay("Hagay", a);
    OldNinja Ella("Ella", b);
    YoungNinja Avichi("Avichi", b);
    TrainedNinja Rechel("Rechel", b);
    CHECK_NOTHROW(Hagay.shoot(&Ella));
    CHECK_NOTHROW(Ella.slash(&Hagay));
    CHECK_NOTHROW(Ella.move(&Hagay));
    CHECK_NOTHROW(Hagay.shoot(&Avichi));
    CHECK_NOTHROW(Hagay.shoot(&Rechel));
    CHECK_NOTHROW(Ella.slash(&Avichi));
    CHECK_NOTHROW(Ella.move(&Rechel));
    CHECK_NOTHROW(Ella.slash(&Rechel));
    CHECK_NOTHROW(Ella.move(&Avichi));
    CHECK_NOTHROW(Avichi.slash(&Hagay));
    CHECK_NOTHROW(Avichi.move(&Hagay));
    CHECK_NOTHROW(Rechel.slash(&Hagay));
    CHECK_NOTHROW(Rechel.move(&Hagay));
    CHECK(Hagay.isAlive());
    Ella.move(&Rechel);
    CHECK_NOTHROW(Ella.getLocation());
    Ella.hit(10);
    CHECK(Hagay.hasboolets());
    CHECK_NOTHROW(Ella.slash(&Hagay));
    CHECK_NOTHROW(Hagay.reload());
    YoungNinja Naomi("Naomi", a);
    TrainedNinja Netanel("Netanel", b);
    Cowboy Kobi("Kobi", a);
    Ninja Roni("Roni", a, 100, 151515);
    // CHECK_EQ(Roni.distance(&Kobi), 0);
    CHECK(Kobi.hasboolets());
    CHECK_NOTHROW(Kobi.shoot(&Naomi));
    CHECK_NOTHROW(Kobi.shoot(&Avichi));
    CHECK_NOTHROW(Naomi.slash(&Kobi));
    CHECK_NOTHROW(Naomi.move(&Avichi));
}

TEST_CASE("distance between points")
{
    Point a(32.3, 44), b(1.3, 3.5);
    CHECK(a.distance(b) == b.distance(a));
    Point c(0, 0), d(0, 0), g(1, 1);
    CHECK(c.distance(d) == 0);
    CHECK(d.distance(c) == 0);
    CHECK(c.distance(c) == 0);
    CHECK(c.distance(g) == sqrt(2));
    double dist1 = a.distance(b);
    Point::moveTowards(a, b, 1);
    CHECK(a.distance(b) != dist1);
}

TEST_CASE("check Team functions")
{
    Point a(32.3, 44), b(1.3, 3.5);
    Cowboy Hagay("Hagay", a);
    OldNinja Ella("Ella", b);
    YoungNinja Avichi("Avichi", b);
    TrainedNinja Rechel("Rechel", b);
    Cowboy Shir("Shir", a);
    OldNinja Avital("Avital", b);
    YoungNinja Miri("Miri", b);
    TrainedNinja Yoel("Yoel", b);
    YoungNinja Eitan("Eitan", b);
    TrainedNinja David("David", b);
    YoungNinja Shlomi("Shlomi", b);
    TrainedNinja caa("caa", b);
    Team teamA(&Hagay);
    CHECK_NOTHROW(teamA.add(&Ella));
    Team teamB(&Avichi);
    CHECK_THROWS(teamB.add(&Hagay));
    CHECK_THROWS(teamB.add(&Avichi));
    CHECK(teamA.stillAlive());
    CHECK_NOTHROW(teamA.print());
    CHECK_NOTHROW(teamB.print());
    CHECK_NOTHROW(teamA.attack(&teamB));
    teamA.add(&Ella);
    teamA.add(&Rechel);
    teamA.add(&Shir);
    teamA.add(&Avital);
    teamA.add(&Miri);
    teamA.add(&Yoel);
    teamA.add(&Eitan);
    teamA.add(&David);
    teamA.add(&Shlomi);
    CHECK_THROWS(teamA.add(&caa));
    while (teamB.stillAlive())
    {
        teamA.attack(&teamB);
    }
    CHECK_THROWS(Hagay.shoot(&Avichi)); // cant shoot a dead man.(WASTE OF BULLETS :D)
    CHECK_EQ(teamB.stillAlive(), 0);
}