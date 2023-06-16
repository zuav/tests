#include <assert.h>
#include <string>
#include <vector>
#include <iostream>


namespace umsctl {

    class jid {
    public:
        explicit jid(const std::string& name = std::string(), const std::string& domain = std::string())
            : m_name(name),
              m_domain(domain)
            {
            }

        bool empty() const
            {
                return m_name.empty() and m_domain.empty();
            }

    private:
        std::string m_name;
        std::string m_domain;
    };
}


class Location_list {
public:
    explicit Location_list(const std::string& s = std::string())
        {
            if (!s.empty())
                m_locations.push_back(s);
        }

    bool empty() const { return m_locations.empty(); }

private:
    std::vector<std::string> m_locations;
};


struct Spf_data {
    umsctl::jid spf_jid;
    Location_list locations;
    int num_sessions_created = 0;
    bool is_active = false;
};



int main()
{
    Spf_data d;

    assert(d.spf_jid.empty());
    assert(d.locations.empty());
    assert(d.num_sessions_created == 0);
    assert(d.is_active == false);

    std::cout << std::boolalpha
              << "d.spf_jid.empty()      : " << d.spf_jid.empty() << std::endl
              << "d.locations.empty()    : " << d.locations.empty() << std::endl
              << "d.num_sessions_created : " << d.num_sessions_created << std::endl
              << "d.is_active            : " << d.is_active << std::endl;

    return 0;
}
