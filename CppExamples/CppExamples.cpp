// CppExamples.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cmath>
#include <complex>
#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>

#include <boost/lambda/lambda.hpp>
#include <boost/algorithm/string.hpp>

#include "CppExamples.h"

extern "C" int fileIoStruct();
extern "C" int mainStringC();
extern "C" int mainErrno();
extern "C" int mainTime();
extern "C" int mainStat();
extern "C" int mainMemory();
using namespace std;

class HowLong
{
    int runCount;
    int successCnt;
    int warningCnt;
    int failCnt;
};

class M {
public:
    M() {}
    M(int x = 1, int y = 1) : i(x), j(y) { }
    int foo(int x) { (x == 1) ? cout << "\n\nFoogetaboutit!\n\n" : cout << "\n\nFoogetaboutfoo!\n\n"; return 1; }
    int poo(int x) { (x == 1) ? cout << "\n\nPoogetaboutit!\n\n" : cout << "\n\nPoogetaboutfoo!\n\n"; return 1; }
    ~M() {}
    int getI() { return i; }
    int getJ() { return j; }
    void setI(const int x) { i = x; }
    void setJ(const int x) { j = x; }
private:
    int i, j;
};

extern "C" void call_M_setI(M* m, const int i) { m->setI(i); }
extern "C" int call_M_getI(M* m) { return m->getI(); }
extern "C" int call_M_foo(M* m, int i) { return m->foo(i); }
extern "C" int call_M_poo(M* m, int i) { return m->poo(i); }

//------------------------------------------------------------------------------------

template <typename T> T maxof(T a, T b) {
    return (a > b ? a : b);
}

template <typename T>
class AB {
    T ab;
public:
    T getAB() const { return ab; }
    void setAB(T x) { ab = x; }
};
void byeEverybody() {
    std::cout << "\n\nWe've compiled a list of winners and you, [this->contestWinnerId()] were...\n";
}

double fcn(double x) {
    return x * x - 1;
}

double fcn2(double x) {
    return x * x * x * x - exp(x) - 2;
}

double root_find(
    double f(double),
    double a, double b,
    double eps,
    double *root) {
    if (b - a < eps) {
        *root = (b + a) / 2.0;
        return f(*root);
    }
    else
        if (f(a)*f((b + a) / 2) <= 0)
            return root_find(f, a, (b + a) / 2, eps, root);
        else
            return root_find(f, (b + a) / 2, b, eps, root);
}
void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void double_swap(double *i, double *j) {
    double temp = *i;
    *i = *j;
    *j = temp;
}

inline void cpp_swap(int& i, int& j) {
    int temp = i;
    i = j;
    j = temp;
}
inline void cpp_swap(double& i, double& j) {         //cplusplus overloading
    double temp = i;
    i = j;
    j = temp;
}
// keyword <class id> inline or not   where <class id> gets substituted for an actual type such as int
template <class T> inline void generic_cpp_swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
double data[] = { 1.2,2.3,4.5,6.7,8.1 };
double summing(double * data, int size) {
    double total = 0.0;
    for (int i = 0; i < size; ++i)
        total += data[i];
    return total;
    //	return static_cast<int>(total);
}

template <class T>
T sum(const T data[], int size, T s = 0)
{
    for (int i = 0; i < size; ++i)
        s += data[i];
    return s;
}

int main(int argc, char ** argv) {
    cout << "Hey kids! Let's do some time operations!" << endl;
    std::tm t = {};
    std::istringstream ss("2011-February-18 23:12:34");
    //	ss.imbue(std::locale("en_US.utf-8"));
    ss >> std::get_time(&t, "%Y-%b-%d %H:%M:%S");
    if (ss.fail()) {
        std::cout << "Parse failed\n";
    }
    else {
        std::cout << std::put_time(&t, "%c") << '\n';
    }

    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::string bs = { "THis is a std::string" };
    cout << boost::algorithm::to_upper_copy(bs) << endl;
    cout << bs << endl;

    double x;
    printf("Root Finder\n");
    root_find(fcn, 0.0, 4.0, 0.00001, &x);
    printf("root is at %g with residual %g \n", x, fcn(x));
    root_find(fcn2, 0.0, 14.0, 0.00001, &x);
    printf("root is at %g\n", x);

    //swap in c then c++

    int m = 5, n = 10;
    x = 5.3;
    double y = 10.6;
    printf("inputs: %d, %d\n", m, n);
    swap(&m, &n);
    printf("outputs: %d, %d\n", m, n);
    printf("double inputs: %lf, %lf\n", x, y);
    double_swap(&x, &y);
    printf("double outputs: %lf, %lf\n", x, y);

    cout << "cpluscplus version of swapping" << endl;
    cout << "inputs: " << m << ", " << n << endl;
    cpp_swap(m, n);
    cout << "outputs: " << m << ", " << n << endl;
    cout << "double inputs: " << x << ", " << y << endl;
    cpp_swap(x, y);
    cout << "double outputs: " << x << ", " << y << endl;

    complex<double> r(2.4, 3.5), s(3.4, 6.7);
    cout << "complex inputs: " << r << ", " << s << endl;
    generic_cpp_swap(r, s);
    cout << "complex outputs: " << r << ", " << s << endl;

    const int result_1 = std::atexit(byeEverybody);
    if (result_1 != 0) {
        std::cerr << "Geez, couldn't register exit handler... dude that sucks!";
        return EXIT_FAILURE;
    }
    cout << "hello wourld!" << endl;
    if (mainC_examples())
        cout << "c_examples, nice" << endl;
    if (mainExceptions())
        cout << "exceptions, nice" << endl;
    if (mainSimpleInheritance())
        cout << "simpleInheritance(), nice" << endl;
    if (mainRational())
        cout << "rational, nice" << endl;
    if (mainFunctionObject())
        cout << "functionObject(), nice" << endl;
    if (mainNewDelete())
        cout << "new Delete(), nice" << endl;
    if (mainComplexInheritance())
        cout << "complexInheritance(), nice" << endl;
    if (mainFriendInheritance())
        cout << "friendInheritance(), nice" << endl;
    if (mainJoin())
        cout << "\n mainJoin(), nice" << endl;
    if (mainTest())
        cout << "\n mainTest(), nice" << endl;
    if (mainVector())
        cout << "\n mainVector(), nice" << endl;
    mainTuple();              cout << "\n mainTuple();                  --done-- " << endl;
    mainTemplateFunction();	  cout << "\n mainTemplateFunction();       --done-- " << endl;
    mainTemplateClass();	  cout << "\n mainTemplateClass();	        --done-- " << endl;
    mainString();			  cout << "\n mainString();			        --done-- " << endl;
    mainQueue();			  cout << "\n mainQueue();			        --done-- " << endl;
    mainNullptr();			  cout << "\n mainNullptr();                --done-- " << endl;
    mainMap();				  cout << "\n mainMap();	                --done-- " << endl;
    mainLambda();			  cout << "\n mainLambda();			        --done-- " << endl;
    mainIostreamFormatting(); cout << "\n mainIostreamFormatting();     --done-- " << endl;
    mainIostreamFile();		  cout << "\n mainIostreamFile();	        --done-- " << endl;
    mainDeque();			  cout << "\n mainDeque();	                --done-- " << endl;
    mainFor();				  cout << "\n mainFor();	                --done-- " << endl;
    mainAuto();				  cout << "\n mainAuto();	                --done-- " << endl;
    fileIo();				  cout << "\n fileIo();		                --done-- " << endl;
    fileIoStruct();           cout << "\n fileIoStruct();               --done-- " << endl;

    std::system("ls -l >test.txt");
    std::system("pwd ");
    std::system("dir ");

    char* buf = 0;
    size_t sz = 0;
    if (_dupenv_s(&buf, &sz, "PATH") == 0)
        cout << "PATH is defined as: " << buf << "\n";
    // MemFrag();
    // 							file.c commented for now
    mainStringC();
    //   mainErrno();
    //   mainTime();
    mainStat();

    mainIterator();            cout << "\n mainIterator();     --done-- " << endl;
    mainList();				   cout << "\n mainList();		   --done-- " << endl;
    mainSet();				   cout << "\n mainSet();		   --done-- " << endl;
    mainSet14();			   cout << "\n mainSet14();		   --done-- " << endl;
    mainMap();				   cout << "\n mainMap();		   --done-- " << endl;
    mainException();		   cout << "\n mainException();	   --done-- " << endl;
    mainRandy();			   cout << "\n mainRandy();		   --done-- " << endl;
    nondupset();			   cout << "\n nondupset();		   --done-- " << endl;
    threadlightly();		   cout << "\n threadlightly();	   --done-- " << endl;
    mainSort();				   cout << "\n mainSort();		   --done-- " << endl;
    mainAlgorithm();		   cout << "\n mainAlgorithm();	   --done-- " << endl;
    mainMemory();    		   cout << "\n mainMemory();	   --done-- " << endl;

    getchar();
    return EXIT_SUCCESS;
}