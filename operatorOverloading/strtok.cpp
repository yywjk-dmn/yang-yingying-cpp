#include <iostream>
#include <cstring>


char* myStrtok(char* source, const char* delim)
{
    static char * delimHeader;
    if (source == nullptr)
    {
        if (delimHeader == nullptr)
            return nullptr;
        source = delimHeader;
    }
    char *target = strstr(source, delim);
    if (target == nullptr)
    {
        delimHeader = nullptr;
        return source;
    }
    else
    {
        *target = '\0';
        delimHeader = target + strlen(delim);
        return source;
    }
}

int main()
{
    char str[] = "zhang,yangyingying,hahahahaha";
    char *s = myStrtok(str, ",");
    while (s != nullptr)
    {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
        std::cout<<s<<std::endl;
        s = myStrtok(nullptr, ",");
    }
    

    return 0;
}