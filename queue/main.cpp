#include <iostream>
#include <time.h>
#include <string>
#include <ctime>
using namespace std;


class Printer {
    string* statistics;
    string* queue_print;
    int max_size;
    int length;
    int statistics_size;
public:
    Printer(int m) : max_size(m), length(0), statistics_size(0)
    {
        queue_print = new string[max_size];
        statistics = new string[max_size];
    }
    void Pop()
    {
        if (length > 0)
        {
            string client = queue_print[0];
            for (int i = 1; i < length; i++)
            {
                queue_print[i - 1] = queue_print[i];
            }
            length--;
            char date[50] = {};
            time_t unixTime = time(nullptr);
            cout << client << " \nprinting\n" << endl;
        }
    }
    void Add(string clientname)
    {
        if (length < max_size)
        {
            queue_print[length++] = clientname;
            cout << "user " << clientname << " added in queue " << endl;
        }
    }
    void PrintStatistics()
    {
        cout << "\nprint statistic:\n";
        for (int i = 0; i < statistics_size; i++)
        {
            cout << statistics[i] << endl;
        }
    }
    void PrintQueue()
    {
        cout << " \nqueue print:\n";
        for (int i = 0; i < length; i++)
        {
            cout << queue_print[i] << " ";
        }
    }
    ~Printer()
    {
        delete[] queue_print;
        delete[] statistics;
    }
};
int main()
{

    Printer printer(3);
    printer.Add("User 1");
    printer.Add("User 2");
    printer.Add("User 3");

    printer.PrintQueue();

    printer.Pop();
    printer.Pop();

    printer.PrintQueue();

    printer.PrintStatistics();
}


