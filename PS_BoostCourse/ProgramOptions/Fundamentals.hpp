#pragma once

int fundamentals(int argc, char* argv[])
{
    po::options_description desc("Program options");
    desc.add_options()
        ("help", "print info")
        ("filename",
            po::value<string>()->default_value("default.txt"),
            "file to process");

    po::variables_map vm;
    auto parsed = po::parse_command_line(argc, argv, desc);
    po::store(parsed, vm);
    po::notify(vm);

    if (vm.count("help"))
    {
        cout << desc << endl;
        getchar();
        return 1;
    }

    string filename = vm["filename"].as<string>();

    cout << "Processing file " << filename << endl;

    getchar();
    return 0;
}