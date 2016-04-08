#pragma once

int customization(int argc, char* argv[])
{
    int value;
    po::options_description desc("my file processor");

    desc.add_options()
        ("value,V", po::value<int>(&value)->default_value(42),
            "input value")
            ("files", po::value<vector<string>>()->multitoken(),
                "input files");

    po::positional_options_description pos;
    pos.add("files", -1);

    po::variables_map vm;
    po::command_line_parser parser(argc, argv);
    auto parsed_options = parser.options(desc).positional(pos).run();
    po::store(parsed_options, vm);
    po::notify(vm);

    cout << "the value is " << value << endl;

    if (vm.count("files"))
    {
        int i = 0;
        auto files = vm["files"].as<vector<string>>();
        for (auto s : files)
        {
            cout << (++i) << ": " << s << endl;
        }
    }

    getchar();
    return 0;
}