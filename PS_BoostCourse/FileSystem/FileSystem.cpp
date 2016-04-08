#include "stdafx.h"

void check_path(const char* p)
{
    path myPath(p);

    if (exists(myPath))
    {
        if (is_regular_file(myPath))
        {
            cout << "path " <<
                myPath.filename().replace_extension() << " is a regular file of size " <<
                file_size(myPath) << endl;
        }
        else if (is_directory(myPath))
        {
            cout << "path " << myPath.filename() <<
                " is a directory" << endl;
        }
    }
    else {
        cout << "path " << myPath << " does not exist"
            << endl;
    }
}

void fundamentals(int argc, char* argv[])
{
    check_path("foo");
    check_path(argv[0]);

    auto dir = path(argv[0]).parent_path();
    check_path(dir.string().c_str());

    // decomposition
    for (auto& child : dir)
    {
        cout << child << endl;
    }

    try {
        path p("junk");
        cout << file_size(p) << endl;
    }
    catch (const filesystem_error& e)
    {
        cout << e.what() << endl;
    }
}

void check_file(path& p)
{
    auto s = status(p);
    auto t = s.type();

    cout << "the type is " << t << endl;

    auto ps = s.permissions();

    if ((ps & owner_write) != owner_write)
    {
        cout << "no permission to write" << endl;
    }
}

void dir_nav(path& dir)
{
    directory_iterator end;
    for (directory_iterator i(dir); i != end; ++i)
    {
        path p = i->path();

        if (is_regular_file(p))
            cout << p.filename() << endl;
        else if (is_directory(p))
        {
            cout << "directory " << p.filename() <<
                "============================" << endl;
            dir_nav(p);
        }
    }
}

int main(int argc, char* argv[])
{
    //    check_path("c:\DEV\Projects");
    //    check_path(argv[0]);

    boost::filesystem::path parent = path(argv[0]).parent_path().parent_path();

    //    check_file(path("c:\DEV\Projects"));
    //    check_file(path(argv[0]));
        // auto parent = path(argv[0]).parent_path().parent_path();

    dir_nav(parent);

    getchar();
    return 0;
}