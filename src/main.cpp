#include <IProcessable.h>
#include <diff/Build.h>
#include <diff/TopologyLoader.h>

using namespace std::string_literals;

void processAll(const std::vector<std::reference_wrapper<IProcessable>> &processables) {   // process until everything finished
    while (std::any_of(processables.cbegin(), processables.cend(), [](IProcessable &p) { return !p.finished(); })) {
        for (IProcessable &p : processables) {
            if (!p.finished()) {
                p.process();
            }
        }
    }
}

int main(int argc, char *argv[]) {
    diff::Topology topology;   // load topology from json
    diff::TopologyLoader("topology.json"s).load(topology);

    diff::Build build(topology);             // compose a component build
    processAll(build.get<IProcessable>());   // access all dependencies of type IProcessable

    return 0;
}
