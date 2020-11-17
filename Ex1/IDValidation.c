#include <stdio.h>
#include <stdbool.h>
/**
 *         assumption input id's length is 9
 * @param  id - israeli id number
 * @return true or false.
 * @see    useful url
 *         https://stackoverflow.com/questions/17307275/what-is-the-printf-format-specifier-for-bool
 */
bool IsValidId(char *id)
{
    int var;
    for (int i = 6;i > 0;i -= 2)
    {
        var = (id[i] - '0') * 2 ;
        if (var > 9)
        {
            id[i] = (char)(var % 10 + var / 10) ;
        }
        else
        {
            id[i] = (char)(var);
        }
        int sum = 0;
        for (int i = 0;i < 9;++i)
        {
            sum += (char)(id[i]);
        }
        if ((sum % 10) == 0)
            return true;
        return false;
    }


}
/**
 * @brief  function checks IsValidId() correctly works
 * @return 0 when terminates
 * @see IsValidId(string id)
 */
int main()
{
    char id[9];
    int j = 0;
    for (int i = 0;i < 8;++i)
    {
        id[j] = i;
        ++j;
    }
    id[8] = 2;
    bool x = IsValidId(id);
    fputs(x ? "true" : "false", stdout);
    return 0;
}
