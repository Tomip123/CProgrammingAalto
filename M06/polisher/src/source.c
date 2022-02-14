#include <string.h>
#include "source.h"
#include <stdlib.h>

/**
 * \brief Removes the C comments from the input C code.
 *
 * \details The function polishes the code by */
//          - removing the block comments delimited by /* and */.
/*            These comments may span multiple lines.You should remove only */
//            characters starting with /* and ending with */. The characters,
/*            including white space characters (' ', \n, \r, \t), */
//            after */ should not be removed.
/*
 *          - remove the line comments starting with // until and including the
 *            newline character \n.
 *
 * \param input A code segment that contains some comments.It is a dynamically
 *              allocated string(array of characters).
 * \return A pointer to the polished code
 */

char *delete_comments(char *input)
{   
    // solve the problem by using malloc and free

    int i = 0;
    int j = 0;
    char *result = (char *)malloc(strlen(input) + 1);
    while (input[i] != '\0')
    {
        if (input[i] == '/' && input[i + 1] == '*')
        {
            i = i + 2;
            while (input[i] != '\0')
            {
                if (input[i] == '*' && input[i + 1] == '/')
                {
                    i = i + 2;
                    break;
                }
                i++;
            }
        }
        else if (input[i] == '/' && input[i + 1] == '/')
        {
            i = i + 2;
            while (input[i] != '\0')
            {
                if (input[i] == '\n')
                {
                    i++;
                    break;
                }
                i++;
            }
        }
        else
        {
            result[j] = input[i];
            j++;
            i++;
        }
    }
    result[j] = '\0';
    free(input);
    return result;
}





