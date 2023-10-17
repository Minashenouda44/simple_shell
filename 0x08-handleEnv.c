#include "shell.h"

/**
 * handleEnv - a function that handle shell env command
 * @environ: environ
 * Return: void
 */

void handleEnv(char **environ)
{
    unsigned int i = 0;

    for (i = 0; environ[i]; i++)
    {
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
}

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

    free2D(arguments);
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

    free2D(arguments);
}
