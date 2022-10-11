#define EXIT(exitCode) exit(static_cast<short>(exitCode))

enum class ExitCodes : short
{
    CantCreateUIObject  = 0,
    CantCreateUI        = 1
};