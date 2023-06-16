#include <stdio.h>
#include <stdlib.h>

#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)

int main()
{
    /* Setting the i18n environment */
    /* setlocale (LC_ALL, "ru_RU"); */
    setlocale (LC_MESSAGES, "ru_RU.UTF-8");
    const char *domain = textdomain("hello");
    const char *pwd = getenv("PWD");
    const char *domain_dir = bindtextdomain(domain, pwd);

    printf("domain: %s\npwd: %s\ndomain dir: %s\n", domain, pwd, domain_dir);

    /* Example of i18n usage */
    printf(_("Hello World\n"));

    return EXIT_SUCCESS;
}
