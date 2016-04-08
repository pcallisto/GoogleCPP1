#pragma once

void third()
{
    cout << "third" << endl;
}

void fundamentals()
{
    signal<void()> s;

    s.connect(third);

    {
        boost::signals2::connection c = s.connect(1, []() { cout << "first" << endl; });
        // auto c = s.connect(1, []() { cout << "first" << endl; });
        scoped_connection sc(c);
        s.connect(0, []() { cout << "second" << endl; });

        s();
    }

    cout << "========" << endl;

    s.disconnect(third);

    s();
}

void customization()
{
    Player p("John");

    {
        auto coach = boost::make_shared<Coach>();

        p.Scores.connect(
            Player::SignalType::slot_type
            (&Coach::PlayerScored, coach.get(), _1).track(coach)
        );

        p.Score();
    }

    p.Score();
}