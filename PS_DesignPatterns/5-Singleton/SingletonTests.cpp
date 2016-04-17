#include <iostream>
#include "Singleton.hpp"
#if 0
//#include <gtest/gtest.h>

TEST(DatabaseTests, IsSingletonTest)
{
  auto& db = SingletonDatabase::get();
  auto& db2 = SingletonDatabase::get();
  ASSERT_EQ(1, db.instance_count);
  ASSERT_EQ(1, db2.instance_count);
}

TEST(RecordFinderTests, SingletonTotalPopulationTest)
{
  SingletonRecordFinder rf;
  std::vector<std::string> names{ "Seoul", "Mexico City" };
  int tp = rf.total_population(names);
  EXPECT_EQ(17500000 + 17400000, tp);
}

TEST(RecordFinderTests, DependantTotalPopulationTest)
{
  DummyDatabase db{};
  ConfigurableRecordFinder rf{ db };
  EXPECT_EQ(4, rf.total_population(
    std::vector<std::string>{"alpha", "gamma"}));
}
#endif
int main(int ac, char* av[])
{
    getchar();
    std::cout << "test" << std::endl;
//  testing::InitGoogleTest(&ac, av);
  return 1;    //RUN_ALL_TESTS();

}
