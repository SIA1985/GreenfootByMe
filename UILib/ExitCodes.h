#define EXIT(exitCode) exit(static_cast<short>(exitCode))
#define EXITWITHCODE(exitCode) throw ExitException(exitCode)

enum class ExitCodes : short
{
    NormalProgramTermination    = 0,
    CantCreateUIObject          = 1,
    CantCreateUI                = 2,
    CantLoadTexture             = 3,
    CantLoadFont                = 4,
    CantCreateWindow            = 5,
    NoObjectOwner               = 6,
};

static const char* GetExitMessageByExitCode(ExitCodes __exitCode)
{
    const char* exitMessage;

    switch (__exitCode)
    {
    case ExitCodes::CantCreateUIObject:
        exitMessage = "Can't create UI object!\n"; 
        break;
    
    case ExitCodes::CantCreateUI:
        exitMessage = "Can't create UI!\n"; 
        break;

    case ExitCodes::CantLoadTexture:
        exitMessage = "Can't load texture!\n"; 
        break;

    case ExitCodes::CantLoadFont:
        exitMessage = "Can't load font!\n"; 
        break;

    case ExitCodes::CantCreateWindow:
        exitMessage = "Can't create window!\n"; 
        break;

    case ExitCodes::NoObjectOwner:
        exitMessage = "UI or UI's object with no owner!\n"; 
        break;

    default:
        break;
    }

    return exitMessage;
}

#include <exception>

class ExitException : std::exception
{
public:
    ExitException(ExitCodes __exitCode)
        {exitCode = __exitCode;}

    const char* what() const noexcept 
        { return GetExitMessageByExitCode(exitCode); }

private:
    ExitCodes exitCode;
};