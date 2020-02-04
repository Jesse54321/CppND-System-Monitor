#include <string>
#include <vector>

#include "processor.h"
#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
    std::vector<std::string> cpu_values = LinuxParser::CpuUtilization();
    
    float idle = std::stof(cpu_values[3]) + std::stof(cpu_values[4]);
    float non_idle = std::stof(cpu_values[0]) + std::stof(cpu_values[1]) + std::stof(cpu_values[2]) + std::stof(cpu_values[5]) + std::stof(cpu_values[6]) + std::stof(cpu_values[7]);

    float total = idle + non_idle;

    return (total - idle) / total; 
}
