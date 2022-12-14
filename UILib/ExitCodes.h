#define EXIT(exitCode) exit(static_cast<short>(exitCode))

enum class ExitCodes : short
{
    NormalProgramTermination    = 0,
    CantCreateUIObject          = 1,
    CantCreateUI                = 2,
    CantLoadTexture             = 3,
    CantLoadFont                = 4
};

#include <exception>

class CantCreateClassMember : std::exception
{
    
};