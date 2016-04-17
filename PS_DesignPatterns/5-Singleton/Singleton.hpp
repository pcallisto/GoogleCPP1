#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <boost\lexical_cast.hpp>
#include <vector>

using namespace std;

class Database
{
public:
  virtual int get_population(const std::string& name) = 0;
};

class SingletonDatabase : public Database
{
  SingletonDatabase()
  {
    std::vector<std::string> vs = { "To3yo",
                                    "33300000",
                                    "Ne3 York",
                                    "17300000",
                                    "Sa3 Paulo",
                                    "17300000",
                                    "Se3ul",
                                    "17300000",
                                    "Me3ico City",
                                    "17300000",
                                    "Os3ka",
                                    "16325000",
                                    "Ma3ila",
                                    "14350000",
                                    "Mu3bai",
                                    "14350000",
                                    "De3hi",
                                    "14300000",
                                    "Ja3arta",
                                    "14350000"};
    std::ofstream ofs("ccccapitals.txt");
    for (auto s: vs)
          ofs << s;
    ofs.close();

    std::cout << "Initializing database" << std::endl;

    std::ifstream ifs("capitals.txt");

    std::string s, s2;
    while (getline(ifs, s))
    {
      getline(ifs, s2);
      int pop = boost::lexical_cast<int>(s2);
      capitals[s] = pop;
    }
    instance_count++;
  }

  std::map<std::string, int> capitals;

public:
 //   static int instance_count;
    int instance_count;

  SingletonDatabase(SingletonDatabase const&) = delete; // block the compiler from automatically creating a copy constructor
  void operator=(SingletonDatabase const&) = delete; // same for copy assignment

  static SingletonDatabase& get()  // static, so it only gets called once and remains thread same
  {
    static SingletonDatabase db;
    return db;
  }

  int get_population(const std::string& name) override
  {
    return capitals[name];
  }

  /*
  static SingletonDatabase* get_instance()
  {
    if (!instance)
      instance = new SingletonDatabase;
    return instance; // atexit
  }
  */
};

//int SingletonDatabase::instance_count = 0;

class DummyDatabase : public Database
{
  std::map<std::string, int> capitals;
public:


  DummyDatabase()
  {
    capitals["alpha"] = 1;
    capitals["beta"] = 2;
    capitals["gamma"] = 3;
  }

  int get_population(const std::string& name) override {
    return capitals[name];
  }
};

struct SingletonRecordFinder
{
  int total_population(std::vector<std::string> names)
  {
    int result = 0;
    for (auto& name : names)
      result += SingletonDatabase::get().get_population(name);
    return result;
  }
};

struct ConfigurableRecordFinder
{
  explicit ConfigurableRecordFinder(Database& db)
    : db{db}
  {
  }

  int total_population(std::vector<std::string> names)
  {
    int result = 0;
    for (auto& name : names)
      result += db.get_population(name);
    return result;
  }

  Database& db;
};