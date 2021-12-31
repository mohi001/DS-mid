#include <iostream>
#include <chrono>
class fix_to_fix
{
    const char *m_name;

    unsigned int count = 0;
    int64_t m_last_time = 0;

public:
    fix_to_fix(const char *name)
    {
        m_name = name;
    }
    void update()
    {
        const auto p1 = std::chrono::system_clock::now();
        m_last_time = std::chrono::duration_cast<std::chrono::seconds>(
                          p1.time_since_epoch())
                          .count();
        count++;
    }
    int64_t get_time()
    {
        return m_last_time;
    }
    int64_t get_count()
    {
        return count;
    }
    void print()
    {
        std::cout << m_name << " : " << count << "\n";
    }
    static void show_history_inc(fix_to_fix *fixes)
    {
        fix_to_fix tmp("");
        for (size_t i = 0; i < 5; i++)
        {
            for (size_t i = 0; i < 5; i++)
            {
                if (fixes[i].get_time() > fixes[i + 1].get_time())
                {
                    tmp = fixes[i];
                    fixes[i] = fixes[i + 1];
                    fixes[i + 1] = tmp;
                }
            }
        }
        for (size_t i = 0; i < 5; i++)
        {
            for (size_t i = 0; i < 5; i++)
            {
                if (fixes[i].get_count() < fixes[i + 1].get_count())
                {
                    tmp = fixes[i];
                    fixes[i] = fixes[i + 1];
                    fixes[i + 1] = tmp;
                }
            }
        }
        for (size_t i = 0; i < 6; i++)
        {
            fixes[i].print();
        }
    }
    static void show_history_dec(fix_to_fix *fixes)
    {
        fix_to_fix tmp("");
        for (size_t i = 0; i < 5; i++)
        {
            for (size_t i = 0; i < 5; i++)
            {
                if (fixes[i].get_time() < fixes[i + 1].get_time())
                {
                    tmp = fixes[i];
                    fixes[i] = fixes[i + 1];
                    fixes[i + 1] = tmp;
                }
            }
        }
        for (size_t i = 0; i < 5; i++)
        {
            for (size_t i = 0; i < 5; i++)
            {
                if (fixes[i].get_count() > fixes[i + 1].get_count())
                {
                    tmp = fixes[i];
                    fixes[i] = fixes[i + 1];
                    fixes[i + 1] = tmp;
                }
            }
        }
        for (size_t i = 0; i < 6; i++)
        {
            fixes[i].print();
        }
    }
};
