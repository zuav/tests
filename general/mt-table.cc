#include <iostream>
#include <string>
#include <mutex>
#include <chrono>
#include <vector>
#include <random>



const int DEF_NUM_CHANGES = 1000;
const int DEF_NUM_READS_BETWEEN_CHANGES = 10000;
const int DEF_TABLE_SIZE = 10;



struct Data {
    std::string address;
    std::string domain;
    std::string locations;

    static void set_random_values(Data&);
};


class Table {
public:
    Table(int size = DEF_TABLE_SIZE);

private:
    int sz;
};


class Locked_table {
public:
    Locked_table();


private:
    std::mutex mutex;
    std::vector<Data> table;
};


class Shared_table {
};


class Copied_table {
};


class Test {
public:
    Test(const Table&);

    std::chrono::millisecods run();

    static void set_num_changes(int);
    static void set_num_reads_between_changes(int);
    static void generate_test_data();

private:
    static int num_chages;
    static int num_reads_between_changes;
    static int num_reads;
    static int num_read_threads;

    void read_thread_func(int thread_num);
    void write_thread_func();

    static std::vector<Data> data;
    Table& table;
    std::mutex m;
    std::condition_variable cv;
    bool change;
    bool quit;
    std::thread wt;
    std::vector<std::thread> rt;
};



std::string random_string();



int main(int argc, char *argv[])
{
    Test::set_num_changes(DEF_NUM_CHANGES);
    Test::set_num_reads_between_changes(DEF_NUM_READS_BETWEEN_CHANGES);
    Test::generate_test_data();

    Locked_table ltbl;
    Test ltest(ltbl, DEF_TABLE_SIZE);
    std::chrono::millisecods lt = ltest.run();

    Shared_table stbl;
    Test stest(stbl, DEF_TABLE_SIZE);
    std::chrono::millisecods st = stest.run();

    Copied_table ctbl;
    Test ctest(ctbl, DEF_TABLE_SIZE);
    std::chrono::millisecods ct = ltest.run();

    std::cout << "num changes: " << Test::num_changes << std::endl
              << "reads between changes: " << Test::reads_between_changes << std::end
              << "locked table time: " << lt.count() << std::end
              << "shared table time: " << st.count() << std::end
              << "copied table time: " << ct.count() << std::end;

    return 0;
}


void Data::set_random_values(Data& d)
{
    d.address   = random_string(32);
    d.domain    = random_string(64);
    d.locations = random_string(16);
}


Test::Test(const Table& t)
    : table(t),
      change(false),
      quit(false)
{
    rt.reserve(num_read_threads);
}


std::chrono::millisecods run()
{
    std::chrono::millisecods start = std::chrono::steady_clock::now();

    wt = std::thread([this] { write_thread_func(); });
    for (int i=0; i<num_read_threads; ++i)
        rt[i] = std::thread([this] { read_thread_func(i); });

    for (int i=0; i<num_read_threads; ++i)
        rt[i].join();
    wt.join();

    std::chrono::millisecods end = std::chrono::steady_clock::now();

    return end - start;
}


void Test::set_num_changes(int v)
{
    num_chages = v;
}


void Test::set_num_reads_between_changes(int v)
{
    num_reads_between_changes = v;
}


void Test::generate_test_data()
{
    // set num_reads here
    num_reads = (num_changes + 1) * num_reads_between_changes;

    data.clear();
    data.reserve(num_changes);

    for (Data& d : data)
        Data::set_random_values(d);
}


void Test::read_thread_func(int thread_num)
{
    Data d;

    for (int i=0; i<num_reads; i++) {
        table.read_data(d);

        d.address   += " Russia";
        d.domain    += ".ru";
        d.locations += ",ru";

        if ((thread_num == 0) and (i % num_reads_between_changes == 0)) {
            std::lock_guard lk(m);
            change = true;
            cv.notify_one();
        }
    }

    if (thread_num == 0) {
        std::lock_guard lk(m);
        change = true;
        quit = true;
        cv.notify_one();
    }
}


void Test::write_thread_func()
{
    for (int i=0; i<data.size() && !quit; ++i) {
        if (!change) {
            std::unique_lock lk(m);
            cv.wait(lk, [this] { return change; });
            change = false;
        }
        table.set_data(data[i]);
    }
}


std::string random_string(int len)
{
    std::string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<> dist(0, chars.size()-1);

    string s = "";
    for (int i=0; i<len; i++) {
        int ind = dist(engine);
        s += chars[ind];
    }

    return s;
}
