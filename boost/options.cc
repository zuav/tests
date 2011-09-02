#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main()
{
	po::options_description log_grp("Logging (log levels: TRACE,DEBUG,INFO,NOTICE,WARNING,ERROR,CRITICAL)");
	log_grp.add_options()
		(optstring("LOGLEVEL").c_str(), po::value<std::string>(),                       "Global log level")
		(optstring("STDLOG").c_str()  , po::value<std::string>()->default_value("on"),  "Log to stdout/stderr (off | on [loglevel] | loglevel)")
		(optstring("FILELOG").c_str(),  po::value<strvector>()->composing(),            "Log file name (filename [loglevel] [limit]) (multiple)")
		(optstring("SYSLOG").c_str(),   po::value<std::string>()->default_value("off"), "Log to system syslogd daemon (off | on [loglevel])")
		(optstring("NETLOG").c_str(),   po::value<strvector>()->composing(),            "Log to network (proto:host:port [loglevel]) (multiple)")
		;

	std::cout << log_grp << std::end;

	return 0;
}
