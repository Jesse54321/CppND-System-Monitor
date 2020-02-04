#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"
#include "form.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() { return _pid; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { 
    long curr_active = LinuxParser::ActiveJiffies(_pid);
    long curr_total = LinuxParser::ActiveJiffies();    

    float active = curr_active - _active_jiffies;
    float total = curr_total - _total_jiffies;

    _active_jiffies = curr_active;
    _total_jiffies = curr_total;

  	if (total <= 0) {
    	return 0.0;
  	}
  
    return active / total;
}

// TODO: Return the command that generated this process
string Process::Command() { return LinuxParser::Command(_pid); }

// TODO: Return this process's memory utilization
string Process::Ram() { return std::to_string(LinuxParser::Ram(_pid)); }

// TODO: Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(_pid); }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(_pid); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { 
    return LinuxParser::ActiveJiffies(_pid) > LinuxParser::ActiveJiffies(a._pid); 
}
