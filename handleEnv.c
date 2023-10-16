#include "shell.h"

/**
 * handleSetEnv - a function that handle shell setenv command
 * @arguments: arguments
 * @argv: arguments vector
 * @status: execution statues
 * @errIndeX: error number
 * Return: void
 */

void handleSetEnv(char **arguments, char **argv, int status, int errIndeX)
{
    (void)status;

    if (arguments[1] && arguments[2])
    {
        if (setenv(arguments[1], arguments[2], 1) != 0)
            handleError(argv[0], arguments[0], errIndeX);
    }
    else
        handleError(argv[0], arguments[0], errIndeX);

    free2DArrayMemory(arguments);
}

/**
 * handleUnsetEnv - a function that handle shell unsetenv command
 * @arguments: arguments
 * @argv: arguments vector
 * @status: execution statues
 * @errIndeX: error number
 * Return: void
 */

void handleUnsetEnv(char **arguments, char **argv, int status, int errIndeX)
{
    (void)status;

    if (arguments[1])
    {
        if (unsetenv(arguments[1]) != 0)
            handleError(argv[0], arguments[0], errIndeX);
    }
    else
        handleError(argv[0], arguments[0], errIndeX);

    free2DArrayMemory(arguments);
}
