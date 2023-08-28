#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

namespace logging = boost::log;
namespace keywords = boost::log::keywords;

void init_logging() {
//    logging::register_simple_formatter_factory<logging::trivial::severity_level, char>("Severity");

    logging::add_file_log(
            keywords::file_name = "sample.log",
            keywords::auto_flush = true
//            , keywords::format = "[%TimeStamp%] [%ThreadID%] [%Severity%] [%ProcessID%] [%LineID%] %Message%"
            );

   logging::add_common_attributes();
}

int main (int argc, const char *argv[])
{
    init_logging();

    BOOST_LOG_TRIVIAL(debug) << "Test";
    return 0;
}

