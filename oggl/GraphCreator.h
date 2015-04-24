// GraphCreator.h

// undefines the macros min and max which are specified in the windows headers
#define NOMINMAX

#include <ogdf/basic/GraphAttributes.h>

namespace oggl {

void CreateGrid(ogdf::Graph& graph, ogdf::GraphAttributes& graphAttributes, int cols, int rows);

}

