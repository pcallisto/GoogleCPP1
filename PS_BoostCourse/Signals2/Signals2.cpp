#include "stdafx.h"

template <typename T> class INotifyPropertyChanged
{
public:
    signal<void(const T*, string)> PropertyChanged;
};

class Player : public INotifyPropertyChanged<Player>
{
    int numberOfGoals;
    int age;
public:
    __declspec(property(get = GetAge, put = PutAge)) int Age;

    int GetAge() const { return age; }

    void PutAge(int value)
    {
        if (value == age) return;
        PropertyChanged(this, string("Age"));
        age = value;
    }

    string name;
    Player(string name) : name(name)
    {
        numberOfGoals = 0;
    }
    typedef signal<void(string, int)> SignalType;
    SignalType Scores;
    void Score()
    {
        numberOfGoals++;
        Scores(name, numberOfGoals);
    }
};

class Coach
{
public:
    void PlayerScored(string name)
    {
        cout << "well done, " << name << endl;
    }
};

#include "FundamentalsAndCustom.h"

template <typename T> struct average
{
    typedef T result_type;

    template <typename II> T operator()(II first, II last) const
    {
        if (first == last) return T();
        float sum = 0.0;
        int count = 0;
        while (first != last)
        {
            sum += *first++;
            count++;
        }
        return sum / count;
    }
};

void f()
{
    signal<float(float, float), average<float>> s;

    s.connect([](float a, float b) { return a + b; });
    s.connect([](float a, float b) { return a * b; });

    cout << "Average is " << s(3, 4) << endl;
}

int main(int argc, char* argv[])
{
    Player p("John");
    p.PropertyChanged.connect(
        [](const Player* p, string propName)
    {
        cout << p->name << "'s " << propName <<
            " has changed " << endl;
    });

    p.PutAge(32);

    p.Age = 25;

    signal<void(int)> values;

    values.connect_extended([](const connection& conn, int value)
    {
        static int count = 0;
        if (++count > 5)
            conn.disconnect();
        else
            cout << "we got a value of " << value << endl;
    });

    srand((unsigned)time(nullptr));
    for (size_t i = 0; i < 100; i++)
    {
        values(rand());
    }

    //    f();

        //Coach coach;
        //Player p("John");

        //{
        //    auto coach = boost::make_shared<Coach>();
        //    // Using track makes the signal drop when 'coach' goes out of scope.
        //    // otherwise, with a normal p.connect(), the signal wouldn't get dropped
        //    // when coach goes out of scope
        //    p.Scores.connect(
        //        Player::SignalType::slot_type(&Coach::PlayerScored, coach.get(), _1).track(coach)
        //        );

        //    p.Score();
        //}
        //p.Score();

       /* signal<void()> s;
        s.connect(third);

        {
            auto c = s.connect(1, []() { cout << "first" << endl; });
            scoped_connection sc(c);
            s.connect(0, []() { cout << "second" << endl; });
            s();
        }

        cout << "======" << endl;

        s.disconnect(third);

        s();

    */

    //Player p("John");

    //p.PropertyChanged.connect(
    //  [](const Player* p, string propName)
    //  {
    //    cout << p->name << "'s " << propName <<
    //      " has changed " << endl;
    //});

    //p.Age = 25;

  //
  ////  auto c = p.Scores.connect([](string name, int count)
  //  boost::signals2::connection c = p.Scores.connect([](string name, int count)
  //  {
  //      cout << "Player "<<name<<"has scored "<< count<<" goals already."<<endl;
  //  });
  //
  //  p.Score();
  //  p.Score();
  //
  //  {
  //      shared_connection_block b(c);
  //      p.Score();  // the signals don't get through...
  //      b.unblock();  // <-----
  //      p.Score();
  //      b.block();    // <-----
  //      p.Score();
  //  }             //out of scope... shared_connection_block 'b' get flushed
  //
  //  p.Score();
  //  p.Score();

  /*
    signal<void(int)> values;

    values.connect_extended(
      [](const connection& conn, int value)
    {
      static int count = 0;
      if (++count > 5)
        conn.disconnect();
      else
        cout << "got a value of " << value << endl;
    });

    srand((unsigned)time(nullptr));
    for (size_t i = 0; i < 100; i++)
    {
      values(rand());
    }*/

    getchar();
    return 0;
}